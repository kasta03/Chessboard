#include "Board.h"
#include "move.h"
#include "Graphic.h"

#define U64 unsigned long long

int main()
{
    Board board;
    graphicBoard();

    U64 mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    moveWhitePawn(board, E2, E4);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Black's moves
    moveBlackPawn(board, E7, E5);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // White develops knight
    moveWhiteKnight(board, G1, F3);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Black develops knight
    moveBlackKnight(board, B8, C6);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // White bishop development
    moveWhiteBishop(board, F1, C4);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    return 0;
}
