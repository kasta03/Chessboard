#pragma once
#include "Board.h"

//holds pices masks
namespace NS_mask
{
    U64 blackPiecesMask(Board &board);
    U64 whitePiecesMask(Board &board);
}

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