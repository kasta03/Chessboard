#include "move.h"

void moveWhiteRook(Board &board, int from, int to)
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

    if (diff_rank != 0 && diff_file != 0)
    {
        printError();
        return;
    }

    if (!(from_Mask & board._whitePieces[Rooks]))
    {
        printError();
        return;
    }

    U64 current_Mask = from_Mask;
    int direction_change = 0;
    int steps = 0;

    if (diff_file != 0)
    {
        steps = diff_file;
        direction_change = (to - from) / steps;
    }
    else
    {
        steps = diff_rank;
        direction_change = (to - from) / steps;
    }

    for (steps; steps > 1; --steps)
    {
        if (direction_change > 0)
            current_Mask <<= direction_change;
        else if (direction_change < 0)
            current_Mask >>= std::abs(direction_change);

        if (current_Mask & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
    }

    if (from_Mask & board._whitePieces[Rooks] && to_Mask ^ NS_mask::blackPiecesMask(board))
    {
        board._whitePieces[Rooks] ^= from_Mask;
        board._whitePieces[Rooks] |= to_Mask;
        flipSide(board);
        if (to_Mask & NS_mask::blackPiecesMask(board))
        {
            pieceToCaptureBlack(to_Mask, board);
        }
    }
    else
    {
        printError();
        return;
    }
    if (from == 0)
    {
        board.whiteLongCastle = false;
    }
    else if (from == 7)
    {
        board.whiteShortCastle = false;
    }
}

void moveBlackRook(Board &board, int from, int to)
{
    if (board.permission == 0)
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

    if (diff_rank != 0 && diff_file != 0)
    {
        printError();
        return;
    }
    
    if (!(from_Mask & board._blackPieces[Rooks]))
    {
        printError();
        return;
    }

    U64 current_Mask = from_Mask;
    int direction_change = 0;
    int steps = 0;

    if (diff_file != 0)
    {
        steps = diff_file;
        direction_change = (to - from) / steps;
    }
    else
    {
        steps = diff_rank;
        direction_change = (to - from) / steps;
    }

    for (steps; steps > 1; --steps)
    {
        if (direction_change > 0)
            current_Mask <<= direction_change;
        else if (direction_change < 0)
            current_Mask >>= std::abs(direction_change);

        if (current_Mask & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
    }

    if (from_Mask & board._blackPieces[Rooks] && to_Mask ^ NS_mask::whitePiecesMask(board))
    {
        board._blackPieces[Rooks] ^= from_Mask;
        board._blackPieces[Rooks] |= to_Mask;
        flipSide(board);
        if (to_Mask & NS_mask::whitePiecesMask(board))
        {
            pieceToCaptureWhite(to_Mask, board);
        }
    }
    else
    {
        printError();
        return;
    }
    if (from == 56)
    {
        board.blackLongCastle = false;
    }
    else if (from == 63)
    {
        board.blackShortCastle = false;
    }
}
