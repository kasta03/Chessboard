#include "move.h"

void moveWhiteBishop(Board &board, int from, int to)
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
    std::cout << "from" << from << std::endl;
    std::cout << "to" << to << std::endl;
    std::cout << "diff_rank: " << diff_rank << std::endl;
    std::cout << "diff_file: " << diff_file << std::endl;
    std::cout << "from_rank: " << from_rank << std::endl;
    std::cout << "to_rank: " << to_rank << std::endl;
    std::cout << "from_file: " << from_file << std::endl;
    std::cout << "to_file: " << to_file << std::endl;

    if (diff_rank != diff_file)
    {
        // printError();
        return;
    }
    
    if (!(from_Mask & board._whitePieces[Bishops]))
    {
        // printError();
        return;
    }

    int steps = diff_rank;
    int direction_change = (to - from) / steps;
    U64 current_Mask = from_Mask;

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

    if (from_Mask & board._whitePieces[Bishops] && to_Mask ^ NS_mask::whitePiecesMask(board))
    {
        board._whitePieces[Bishops] ^= from_Mask;
        board._whitePieces[Bishops] |= to_Mask;
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
}

void moveBlackBishop(Board &board, int from, int to)
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

    if (diff_rank != diff_file)
    {
        printError();
        return;
    }
    
    if (!(from_Mask & board._blackPieces[Bishops]))
    {
        printError();
        return;
    }

    int steps = diff_rank;
    int direction_change = (to - from) / steps;
    U64 current_Mask = from_Mask;

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

    if (from_Mask & board._blackPieces[Bishops] && to_Mask ^ NS_mask::blackPiecesMask(board))
    {
        board._blackPieces[Bishops] ^= from_Mask;
        board._blackPieces[Bishops] |= to_Mask;
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
}
