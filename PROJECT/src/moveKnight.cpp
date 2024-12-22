#include "move.h"

void moveWhiteKnight(Board &board, int from, int to)
{
    if(board.permission == 1)
    {
        printError();
        return;
    }
    U64 from_Mask = 1ULL;
    U64 to_Mask = 1ULL;
    from_Mask <<= from;
    to_Mask <<= to;

    int from_file = from % 8;
    int from_rank = from / 8;
    int to_file = to % 8;
    int to_rank = to / 8;

    int diff_rank = std::abs(from_rank - to_rank);
    int diff_file = std::abs(from_file - to_file);

    if (diff_rank == 2 && diff_file == 1 || diff_rank == 1 && diff_file == 2)
    {
        if (from_Mask & board._whitePieces[Knights] && to_Mask ^ NS_mask::whitePiecesMask(board))
        {
            board._whitePieces[Knights] ^= from_Mask;
            board._whitePieces[Knights] |= to_Mask;
            flipSide(board);
            if (to_Mask & NS_mask::blackPiecesMask(board))
            {
                pieceToCaptureBlack(to_Mask, board);
            }
        }
    }
    else
    {
        printError();
        return;
    }
}

void moveBlackKnight(Board &board, int from, int to)
{
    if(board.permission == 0)
    {
        printError();
        return;
    }
    U64 from_Mask = 1ULL;
    U64 to_Mask = 1ULL;
    from_Mask <<= from;
    to_Mask <<= to;

    int from_file = from % 8;
    int from_rank = from / 8;
    int to_file = to % 8;
    int to_rank = to / 8;

    int diff_rank = std::abs(from_rank - to_rank);
    int diff_file = std::abs(from_file - to_file);

    if (diff_rank == 2 && diff_file == 1 || diff_rank == 1 && diff_file == 2)
    {
        if (from_Mask & board._blackPieces[Knights] && to_Mask ^ NS_mask::blackPiecesMask(board))
        {
            board._blackPieces[Knights] ^= from_Mask;
            board._blackPieces[Knights] |= to_Mask;
            flipSide(board);
            if (to_Mask & NS_mask::whitePiecesMask(board))
            {
                pieceToCaptureWhite(to_Mask, board);
            }
        }
    }
    else
    {
        printError();
        return;
    }
}