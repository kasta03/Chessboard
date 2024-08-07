#pragma once
#include "Board.h"

//holds pices masks
namespace NS_mask
{
    U64 blackPiecesMask(Board &board);
    U64 whitePiecesMask(Board &board);
}

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
