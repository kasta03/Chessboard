#pragma once
#include "Board.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

enum Square {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
};

enum
{
    Pawns,
    Knights,
    Bishops,
    Rooks,
    Queen,
    King
};

void flipSide(Board &board);

//holds pices masks
namespace NS_mask
{
    U64 blackPiecesMask(Board &board);
    U64 whitePiecesMask(Board &board);
}
//prints error message
void printError();

//removing captured piece
void pieceToCapture(U64 toMask, std::vector<U64> &pieces);

//removing black pices after capture
void pieceToCaptureBlack(U64 toMask, Board &board);

//removing white pices after capture
void pieceToCaptureWhite(U64 toMask, Board &board);

//moving white pawn
void moveWhitePawn(Board &board, int from, int to);

//moving black pawn
void moveBlackPawn(Board &board, int from, int to);

//moving white pony
void moveWhiteKnight(Board &board, int from, int to);

//moving black pony
void moveBlackKnight(Board &board, int from, int to);

//moving white bishop
void moveWhiteBishop(Board &board, int from, int to);

//moving black bishop
void moveBlackBishop(Board &board, int from, int to);

//moving white rook
void moveWhiteRook(Board &board, int from, int to);

//moving black rook
void moveBlackRook(Board &board, int from, int to);

//moving white queen
void moveWhiteQueen(Board &board, int from, int to);

//moving black queen
void moveBlackQueen(Board &board, int from, int to);

//moving white king
void moveWhiteKing(Board &board, int from, int to);

//moving black king
void moveBlackKing(Board &board, int from, int to);
