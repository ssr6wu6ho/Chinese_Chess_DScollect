#include "Evaluate_mfc.h"

//(Evaluate_MFC::Evaluate_MFC() {}

Evaluate_MFC::Evaluate_MFC(int* Board,int* Pieces,int* PiecesInBoard)
{
    this->Board = Board;
    this->Pieces = Pieces;
    this->PiecesInBoard = PiecesInBoard;
}

/*局面评估
int Evaluate_MFC::CountValue() {
    int value=0;
    for(int i=16;i<48;i++){
        switch (i) {
        case 16:
        case 17:
        case 32:
        case 33:value+=CountRookFlexValue(i);break;     //5 mfc数组下标,QT R:board[8] B:board[16],piece[16][17]
        case 18:
        case 19:
        case 34:
        case 35:value+=CountKnightFlexValue(i);break;
        case 20:
        case 21:
        case 36:
        case 37:value+=CountCannonFlexValue(i);break;
        case 22:
        case 23:
        case 38:
        case 39:value+=CountBishopFlexValue(i);break;
        case 24:
        case 25:
        case 40:
        case 41:value+=CountAdvisorFlexValue(i);break;
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:value+=CountPawnFlexValue(i);break;
        case 31:
        case 47:value+=CountKingFlexValue(i);break;     //5 mfc数组下标,QT board[8],piece[16][17]
        }
    }
    return value;
}
//棋子价值+位置价值 +

//车 MFC下标:5
int Evaluate_MFC::CountRookFlexValue(int PieciesId) {
    if(Pieces[PieciesId]==0){
        return 0;
    }
    int Piece_pos = Pieces[PieciesId];
    int side_=1?0:isRedTurn;
    int value=_R;
    //棋子价值
    //棋子位置价值
    value += PositionValue[side_][1][Piece_pos];
    /*for (int d = 0; d < 4; d++) {
        BYTE byTo = byFrom;
        while (true) {
            byTo = (BYTE)(byTo + RookDir[d]);
            if (!(LegalPosition[SCR(state.side)][byTo] & PositionMask[PIECE_R]) || (state.board[byTo] & state.side)) {
                break;
            }
            value += 4;
            if (state.board[byTo]) {
                break;
            }
        }
    }
    return value;
}

//将
int Evaluate_MFC::CountKingFlexValue(int PieciesId) {
    if(Pieces[PieciesId]==0){
        return 0;
    }
    int Piece_pos = Pieces[PieciesId];
    int side_=1?0:isRedTurn;
    int value=_K;
    //棋子价值
    //棋子位置价值
    value += PositionValue[side_][][Piece_pos];;
    for (int d = 0; d < 4; d++) {
        BYTE byTo = byFrom + KingDir[d];
        //判断落子是否合法
        if ((LegalPosition[SCR(bySide)][byTo] & PositionMask[PIECE_K]) && !(state.board[byTo] & bySide)) {
            value += 2;
        }
    }
    return value;
}

//士
int Evaluate_MFC::CountAdvisorFlexValue(int PieciesId) {
    int value = 0;
    for (int d = 0; d < 4; d++) {
        BYTE byTo = byFrom + AdvisorDir[d];
        if ((LegalPosition[SCR(bySide)][byTo] & PositionMask[PIECE_A]) && !(state.board[byTo] & bySide)) {
            value += 2;
        }
    }
    return value;
}

//象
int Evaluate_MFC::CountBishopFlexValue(int PieciesId) {
    int value = 0;
    for (int d = 0; d < 4; d++) {
        if (!state.board[(BYTE)(byFrom + BishopCheck[d])]) {
            BYTE byTo = byFrom + BishopDir[d];
            if ((LegalPosition[SCR(bySide)][byTo] & PositionMask[PIECE_B]) && !(state.board[byTo] & bySide)) {
                value += 2;
            }
        }
    }
    return value;
}

//马
int Evaluate_MFC::CountKnightFlexValue(int PieciesId) {
    int value = 0;
    for (int d = 0; d < 8; d++) {
        if (!state.board[(BYTE)(byFrom + KnightCheck[d])]) {
            BYTE byTo = byFrom + KnightDir[d];
            if ((LegalPosition[SCR(bySide)][byTo] & PositionMask[PIECE_N]) && !(state.board[byTo] & bySide)) {
                value += 5;
            }
        }
    }
    return value;
}



//炮
int Evaluate_MFC::CountCannonFlexValue(int PieciesId) {
    int value = 0;
    for (int d = 0; d < 4; d++) {
        bool over = false;
        BYTE byTo = byFrom;
        while (true) {
            byTo = (BYTE)(byTo + CannonDir[d]);
            if (!(LegalPosition[SCR(state.side)][byTo] & PositionMask[PIECE_C])) {
                break;
            }
            if (!over) {
                if (!state.board[byTo]) {
                    value += 3;
                }
                else {
                    over = true;
                }
            }
            else {
                if (state.board[byTo]) {
                    if (!(state.board[byTo] & state.side)) {
                        value += 3;
                    }
                    break;
                }
            }
        }
    }
    return value;
}

//兵卒
int Evaluate_MFC::CountPawnFlexValue(int PieciesId) {
    int value = 0;
    for (int d = 0; d < 3; d++) {
        BYTE byTo = byFrom + PawnDir[SCR(bySide)][d];
        if ((LegalPosition[SCR(bySide)][byTo] & PositionMask[PIECE_P]) && !(state.board[byTo] & bySide)) {
            value += 2;
        }
    }
    return value;
}*/

