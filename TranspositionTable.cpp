#include "TranspositionTable.h"
#include <QDebug>

TranspositionTable::TranspositionTable(int* Board)
{
    this->Board=Board;
    initU64();
}

//初始化U64数组
void TranspositionTable::initU64(){
    qsrand(static_cast<unsigned int>(QTime(0,0,0).secsTo(QTime::currentTime())));//qsrand是一个随机生产函数(参数是一个种子，可以保证每次程序运行时生成的随机数序列时相同的)
    //static_cast静态类型转换为unsinged int
    for(int i=0;i<256;i++){     //棋盘位置      256个位置，每个位置23种可能的棋子
        for(int j=0;j<23;j++){      //棋子种类
            unsigned long long int _U64=static_cast<unsigned long long int>(qrand())^        //0x000000000000FFFFull
                                          static_cast<unsigned long long int>(qrand())<<15^  //0x00000000FFFF0000ull
                                          static_cast<unsigned long long int>(qrand())<<30^  //0x0000FFFF00000000ull
                                          static_cast<unsigned long long int>(qrand())<<45^  //0xFFFF000000000000ull
                                          static_cast<unsigned long long int>(qrand())<<60;
            U64[i][j]=_U64;
        }
    }
    MoveSideHash=static_cast<unsigned long long int>(qrand())^
                   static_cast<unsigned long long int>(qrand())<<15^
                   static_cast<unsigned long long int>(qrand())<<30^
                   static_cast<unsigned long long int>(qrand())<<45^
                   static_cast<unsigned long long int>(qrand())<<60;
}

//计算Zobrist
unsigned long long int TranspositionTable::getZobrist(bool isRedTurn){
    unsigned long long int ZobristValue=0;
    for(int i=51;i<=203;i++){
        if(Board[i]!=0){
            ZobristValue=ZobristValue^U64[i][Board[i]];//异或u64随机数数组中棋子所在位置和种类
        }
    }
    //黑棋走再异或一次
    if(!isRedTurn){
        ZobristValue=ZobristValue^MoveSideHash;
    }
    return ZobristValue;
}

//走棋后计算Zobrist
void TranspositionTable::getFakeMoveZobrist(Step* step,unsigned long long int& Zobrist){
    //走棋后走棋方一定变化
    Zobrist=Zobrist^MoveSideHash;
    Zobrist=Zobrist^U64[step->Src_Position][step->Src_PiecesType];//源棋子移除
    Zobrist=Zobrist^U64[step->Dst_Position][step->Src_PiecesType];//源棋子落子
    if(step->Dst_PiecesType!=0){//目标位置有棋子
        Zobrist=Zobrist^U64[step->Dst_Position][step->Dst_PiecesType];//目标棋子移除
    }
}

//撤销棋子后计算
void TranspositionTable::getbackFakeMoveZobrist(Step* step,unsigned long long int& Zobrist){
    Zobrist=Zobrist^MoveSideHash;
    Zobrist=Zobrist^U64[step->Dst_Position][step->Src_PiecesType];//源棋子移除
    Zobrist=Zobrist^U64[step->Src_Position][step->Src_PiecesType];//源棋子落回
    if(step->Dst_PiecesType!=0){//目标位置有棋子
        Zobrist=Zobrist^U64[step->Dst_Position][step->Dst_PiecesType];//目标棋子添加
    }
}

/*
    struct HASHITEM{
        unsigned long long int ZobristHash;
        int depth;
        int value;
        TYPE value_type;
        char m_padding[4];//填充
    }TT[HashTableSize];
*/

//查找置换表(注意边界条件)
bool TranspositionTable::lookUpTT(unsigned long long int ZobristValue, int depth, int& value,int alpha,int beta){
    int HashIndex = ZobristValue%HashTableSize;
    HASHITEM Item = TT[HashIndex];//取出元素
    bool flag=false;//命中成功标志
    //更靠近根节点的才有用
    if(ZobristValue==Item.ZobristHash && Item.depth>=depth){
        //重复局面产生的值因为路径不同可能不同，不能直接用
        if(Item.value==-80088 || Item.value==-80060 || Item.value==80088 || Item.value==80060
                || Item.value==66666 || Item.value==-66666){
            return false;
        }
        switch (Item.value_type) {
        case exact: //0
            value=Item.value;
            flag=true;
            break;
        case lower_bound:   //1
            if(Item.value>=beta){
                value=Item.value;
                flag=true;
            }
            break;
        case upper_bound:   //2
            if(Item.value<=alpha){
                value=Item.value;
                flag=true;
            }
            break;
        }
    }
    return flag;
}

//存入置换表
void TranspositionTable::storeToTT(unsigned long long int ZobristValue, int depth, int value,TYPE value_type){
    int HashIndex = ZobristValue%HashTableSize;     //计算索引
    HASHITEM Item = TT[HashIndex];      //复制一个在置换表改索引下的一个结构体变量

    //更靠近根节点的不应该覆盖
    if(ZobristValue==Item.ZobristHash && Item.depth>depth){     //目前看是值相似(重复)的节点
        if(Item.value==-80088 || Item.value==-80060 || Item.value==80088 || Item.value==80060
                || Item.value==66666 || Item.value==-66666){//和棋局面无价值
            TT[HashIndex].ZobristHash=ZobristValue;
            TT[HashIndex].depth=depth;
            TT[HashIndex].value=value;
            TT[HashIndex].value_type=value_type;
        }
        return;
    }
    TT[HashIndex].ZobristHash=ZobristValue;
    TT[HashIndex].depth=depth;
    TT[HashIndex].value=value;
    TT[HashIndex].value_type=value_type;
}
