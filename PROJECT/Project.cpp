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

    // Move 1: White plays c4
    moveWhitePawn(board, C2, C4);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 1: Black plays e6
    moveBlackPawn(board, E7, E6);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 2: White plays Nf3
    moveWhiteKnight(board, G1, F3);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 2: Black plays d5
    moveBlackPawn(board, D7, D5);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 3: White plays d4
    moveWhitePawn(board, D2, D4);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 3: Black plays Nf6
    moveBlackKnight(board, G8, F6);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 4: White plays Nc3
    moveWhiteKnight(board, B1, C3);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 4: Black plays Be7
    moveBlackBishop(board, F8, E7);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 5: White plays Bg5
    moveWhiteBishop(board, C1, G5);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Black castles queenside
    moveBlackKing(board, E8, G8);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    std::cout << "-------------------------------------------------------------------" << std::endl;

    // Move 6: White plays e3
    moveWhitePawn(board, E2, E3);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 6: Black plays h6
    moveBlackPawn(board, H7, H6);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 7: White plays Bh4
    moveWhiteBishop(board, G5, H4);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 7: Black plays b6
    moveBlackPawn(board, B7, B6);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 8: White plays cxd5
    moveWhitePawn(board, C4, D5);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    // Move 8: Black plays Nxd5
    moveBlackKnight(board, F6, D5);
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);

    return 0;
}
