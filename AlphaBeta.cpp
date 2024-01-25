#include "AlphaBeta.h"
#include <QDebug>

AlphaBeta::AlphaBeta()
{
    EV = new Evaluate(Board,Pieces,PiecesInBoard);
}

//获取最佳步
void AlphaBeta::getBestStep(int* _Board,int* _Pieces,int* _PiecesInBoard,bool computerColor,int DEPTH){
    int time_begin=clock();
    //棋盘赋值
    for(int i=0;i<256;i++){
        this->Board[i]=_Board[i];
        this->PiecesInBoard[i]=_PiecesInBoard[i];
    }
    for(int i=0;i<48;i++){
        this->Pieces[i]=_Pieces[i];
    }
    //估值函数
    evaluate_count=0;//evaluate计数
    node_count=0;//节点计数    nDistance=0;//实际走的深度（与根节点的距离）
    MoveSide=computerColor;//走棋方颜色
    int maxValue=-LARGENUMBER;
    Step* bestStep=new Step();
    int value;//暂存
    QVector<Step*> possibleSteps;
    if(computerColor){  //如果是红就调用红放的函数
        MoveGeneratorR MVR = MoveGeneratorR(this->Board,this->Pieces,this->PiecesInBoard);
        MVR.getAllPossibleSteps(possibleSteps);
    }else{
        MoveGeneratorB MVB = MoveGeneratorB(this->Board,this->Pieces,this->PiecesInBoard);
        MVB.getAllPossibleSteps(possibleSteps);
    }
    for(auto iter=possibleSteps.begin();iter!=possibleSteps.end();iter++){  //auto自动识别变量类型
        fakeMove(*iter);        //先走完第一步探索以下最高值的步数
        value=-NegaMax(DEPTH-1,-LARGENUMBER,LARGENUMBER);   //ab
        backFakeMove(*iter);
            maxValue=value;
        if(value>maxValue){
            *bestStep=*(*iter);
        }
        showStep(*iter,value,false);//显示步骤信息
    }
    qDeleteAll(possibleSteps);  //删除，释放内存
    showStep(bestStep,maxValue,true);
    int time_end=clock();
    qDebug()<<"共遍历"<<node_count<<"个节点,调用"<<evaluate_count<<"次估值函数,"<<"耗时"<<(time_end-time_begin)/1000<<"秒";
    emit endSearch(bestStep);   //停止搜索，下棋
}
//负极大值                  4-1
int AlphaBeta::NegaMax(int depth, int alpha, int beta){
    node_count++;
    //是否胜利
    if(Pieces[31]==0||Pieces[47]==0){
        return -(80080-nDistance);
    }
    nDistance++;
    //叶子节点估值
    if(depth<=0){
        evaluate_count++;
        nDistance--;
        if(MoveSide){
            return -EV->evaluateGame();
        }else{
            return EV->evaluateGame();
        }
    }
    int value;
    QVector<Step*> steps;
    //根据走棋方获取不同棋路
    if(MoveSide){   //red=true
        MoveGeneratorR MVR = MoveGeneratorR(Board,Pieces,PiecesInBoard);
        MVR.getAllPossibleSteps(steps);
    }else{
        MoveGeneratorB MVB = MoveGeneratorB(Board,Pieces,PiecesInBoard);
        MVB.getAllPossibleSteps(steps);
    }
    //遍历走棋
    for(auto iter=steps.begin();iter!=steps.end();iter++){
        fakeMove(*iter);        //换边
        value=-NegaMax(depth-1,-beta,-alpha);   //递归调用，b传下去只是一个参考值，仅仅用来判断剪枝
        backFakeMove(*iter);    //换边(回溯)
        if(value>alpha){
            alpha=value;
            if(alpha>=beta){    //剪枝
                break;
            }
        }
    }
    qDeleteAll(steps);//一定记得释放,否则会造成严重的内存泄漏
    nDistance--;
    return alpha;
}

//移动棋子
void AlphaBeta::fakeMove(Step *step){
    Board[step->Src_Position]=0;
    PiecesInBoard[step->Src_Position]=0;
    Pieces[step->Src_PiecesId]=step->Dst_Position;      //下标对应棋子种类，数值代表所在位置
    Board[step->Dst_Position]=step->Src_PiecesType;
    PiecesInBoard[step->Dst_Position]=step->Src_PiecesId;
    Pieces[step->Dst_PiecesId]=0;       //棋子死了就0
    MoveSide=!MoveSide;
}

//显示步骤
void AlphaBeta::showStep(Step* step, int value, bool flag){
    int x_src=(step)->Src_Position%16-3;
    int y_src=(step)->Src_Position/16-3;
    int x_dst=(step)->Dst_Position%16-3;
    int y_dst=(step)->Dst_Position/16-3;
    QString chess;
    switch (this->Board[(step)->Src_Position]) {
    case 16:chess="黑車";break;
    case 17:chess="黑马";break;
    case 18:chess="黑炮";break;
    case 19:chess="黑象";break;
    case 20:chess="黑士";break;
    case 21:chess="黑兵";break;
    case 22:chess="黑将";break;
    case 8:chess="红車";break;
    case 9:chess="红马";break;
    case 10:chess="红炮";break;
    case 11:chess="红象";break;
    case 12:chess="红士";break;
    case 13:chess="红兵";break;
    case 14:chess="红将";break;
    }
    if(!flag){
        qDebug()<<this->PiecesInBoard[(step)->Src_Position]<<chess<<"("<<x_src<<","<<y_src<<")"
                                                     <<"---->"<<"("<<x_dst<<","<<y_dst<<")"<<"得分"<<value;
    }else{
        qDebug()<<"AlphaBeta:"<<"最佳步骤："<<this->PiecesInBoard[(step)->Src_Position]<<chess<<"("<<x_src<<","<<y_src<<")"
                                                     <<"---->"<<"("<<x_dst<<","<<y_dst<<")"<<"得分"<<value;
    }

}


//撤回移动
void AlphaBeta::backFakeMove(Step *step){
    Board[step->Src_Position]=step->Src_PiecesType;
    PiecesInBoard[step->Src_Position]=step->Src_PiecesId;
    Pieces[step->Src_PiecesId]=step->Src_Position;
    Board[step->Dst_Position]=step->Dst_PiecesType;
    PiecesInBoard[step->Dst_Position]=step->Dst_PiecesId;
    if(step->Dst_PiecesId!=0){//目标位置以前有棋子
        Pieces[step->Dst_PiecesId]=step->Dst_Position;
    }
    MoveSide=!MoveSide;
}
