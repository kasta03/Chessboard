#include "move.h"


void moveWhiteQueen(Board &board, int from, int to)
{
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

    if((diff_rank != 0 && diff_file != 0) && (diff_rank != diff_file))
    {
        printError();
        return;
    }

    U64 current_Mask = from_Mask;
    int direction_change = 0;
    int steps = 0;

    if(diff_rank == diff_file)
    {
        int steps = diff_rank;
        int direction_change = (to - from)/steps;
    }
    else if(diff_file != 0)
    {
        direction_change = (to - from)/diff_file;
        steps = diff_file;
    }
    else if(diff_rank != 0)
    {
        direction_change = (to - from);
        steps = diff_rank;
    }

    for(steps; steps > 1; --steps)
    {
        current_Mask <<= direction_change;

        std::cout << steps << std::endl;

        if(current_Mask & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
    }

    if(from_Mask & board._whitePieces[Queen] && to_Mask ^ NS_mask::whitePiecesMask(board))
    {
        board._whitePieces[Queen] ^= from_Mask;
        board._whitePieces[Queen] |= to_Mask;
        if(to_Mask & NS_mask::blackPiecesMask(board))
        {
            pieceToCaptureBlack(to_Mask, board);
        }
    }
}

void moveBlackQueen(Board &board, int from, int to)
{
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

    if((diff_rank != 0 && diff_file != 0) && (diff_rank != diff_file))
    {
        printError();
        return;
    }

    U64 current_Mask = from_Mask;
    int direction_change = 0;
    int steps = 0;

    if(diff_rank == diff_file)
    {
        int steps = diff_rank;
        int direction_change = (to - from)/steps;
    }
    else if(diff_file != 0)
    {
        direction_change = (to - from)/diff_file;
        steps = diff_file;
    }
    else if(diff_rank != 0)
    {
        direction_change = (to - from);
        steps = diff_rank;
    }

    for(steps; steps > 1; --steps)
    {
        current_Mask <<= direction_change;

        std::cout << steps << std::endl;

        if(current_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board)))
        {
            printError();
            return;
        }
    }

    if(from_Mask & board._blackPieces[Queen] && to_Mask ^ NS_mask::blackPiecesMask(board))
    {
        board._blackPieces[Queen] ^= from_Mask;
        board._blackPieces[Queen] |= to_Mask;
        if(to_Mask & NS_mask::whitePiecesMask(board))
        {
            pieceToCaptureWhite(to_Mask, board);
        }
    }
}