#include <bitset>
// #include <windows.h>
#include "Board.h"
#include "move.h"
#include "Graphic.h"

#define U64 unsigned long long

int main()
{
    Board board;
    graphicBoard();

    // Testowanie ruchów białych
    U64 mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    // Ruchy białymi pionkami
    moveWhitePawn(board, E2, E4); // Pionek biały z E2 na E4
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveWhitePawn(board, D2, D4); // Pionek biały z D2 na D4
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveWhitePawn(board, E4, E5); // Pionek biały z E4 na E5
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveWhitePawn(board, G2, G4); // Pionek biały z G2 na G4
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveWhitePawn(board, F2, F3); // Pionek biały z F2 na F3
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    // Ruchy czarną królową
    moveBlackPawn(board, D7, D5); // Pionek biały z F2 na F3
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveBlackQueen(board, D8, D6); // Królowa czarna z D8 na D5
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveBlackQueen(board, D6, E5); // Królowa czarna z D8 na D5
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveBlackQueen(board, E5, D5); // Królowa czarna z D8 na D5
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;


    moveBlackQueen(board, D5, D4); // Królowa czarna z D5 na D4 (zbijając pionka białego na D4)
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveBlackQueen(board, D4, H4); // Królowa czarna z D4 na H4
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveBlackQueen(board, H4, H5); // Królowa czarna z H4 na H5
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    moveBlackQueen(board, H5, E5); // Królowa czarna z H5 na E5 (zbijając pionka białego na E5)
    mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    std::cout << "------------------" << std::endl;

    return 0;
}
