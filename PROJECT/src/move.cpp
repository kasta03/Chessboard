#include "move.h"

void flipSide(Board &board)
{
    board.permission = !board.permission;
}

void printError()
{
    std::cout << "\033[1;31mIllegal move\033[0m" << std::endl;
}

void pieceToCapture(U64 to_Mask, std::vector<U64> &pieces)
{
    for (int i = 0; i < pieces.size(); ++i)
    {
        if (to_Mask & pieces.at(i))
        {
            pieces.at(i) ^= to_Mask;
        }
    }
}

void pieceToCaptureBlack(U64 to_Mask, Board &board)
{
    pieceToCapture(to_Mask, board._blackPieces);
}

void pieceToCaptureWhite(U64 to_Mask, Board &board)
{
    pieceToCapture(to_Mask, board._whitePieces);
}

namespace NS_mask // przechowyje maski dla wszystich figur
{
    U64 blackPiecesMask(Board &board)
    {
        U64 mask = board._blackPieces[Pawns] | board._blackPieces[Rooks] | board._blackPieces[Knights] | board._blackPieces[Bishops] | board._blackPieces[Queen] | board._blackPieces[King];
        return mask;
    }
    U64 whitePiecesMask(Board &board)
    {
        U64 mask = board._whitePieces[Pawns] | board._whitePieces[Rooks] | board._whitePieces[Knights] | board._whitePieces[Bishops] | board._whitePieces[Queen] | board._whitePieces[King];
        return mask;
    }
}
