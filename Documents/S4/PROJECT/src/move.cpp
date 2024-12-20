#include "move.h"
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

void moveWhitePawn(Board &board, int from, int to)
{
    // Setting masks
    U64 from_Mask = 1ULL;
    U64 to_Mask = 1ULL;
    from_Mask <<= from;
    to_Mask <<= to;

    // Checking if there is a piece on pointed square and there is no white piece on toSquare
    if (from_Mask & board._whitePieces[Pawns])
    {
        // Checking captures from h to a and from a to h
        if ((from % 8 == 7 && to % 8 == 0) || (to % 8 == 7 && from % 8 == 0))
        {
            printError();
            return;
        }
        // Move forward or Move forward twice
        if ((from_Mask & (to_Mask >> 8)) || ((from / 8 == 1) && ((from + 16) == to) && (!(to_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board))))))
        {
            board._whitePieces[Pawns] ^= from_Mask;
            board._whitePieces[Pawns] |= to_Mask;
        }
        // Captures
        else if ((((from + 9) == to) || ((from + 7) == to)) && (to_Mask & NS_mask::blackPiecesMask(board)))
        {
            pieceToCaptureBlack(to_Mask, board);
            board._whitePieces[Pawns] ^= from_Mask;
            board._whitePieces[Pawns] |= to_Mask;
        }
    }
    // if there is no pawn
    else
    {
        std::cout << "There is no pawn";
        return;
    }
}

void moveBlackPawn(Board &board, int from, int to)
{
    // Checking if the piece is at pointed
    U64 from_Mask = 1ULL;
    U64 to_Mask = 1ULL;
    from_Mask <<= from;
    to_Mask <<= to;

    if ((from_Mask & board._blackPieces[Pawns]) && (to_Mask ^ NS_mask::blackPiecesMask(board)))
    {
        // Checking captures from h to a and from a to h
        if ((from % 8 == 7 && to % 8 == 0) || (to % 8 == 7 && from % 8 == 0))
        {
            printError();
            return;
        }
        // Move forward or Move forward twice
        if ((from_Mask & (to_Mask << 8)) || ((from / 8 == 6) && ((from - 16) == to) && (!(to_Mask & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board))))))
        {
            board._blackPieces[Pawns] ^= from_Mask;
            board._blackPieces[Pawns] |= to_Mask;
        }
        // Captures
        else if ((((from - 9) == to) || ((from - 7) == to)) && (to_Mask & NS_mask::whitePiecesMask(board)))
        {
            pieceToCaptureWhite(to_Mask, board);
            board._blackPieces[Pawns] ^= from_Mask;
            board._blackPieces[Pawns] |= to_Mask;
        }
    }
    // if there is no pawn
    else
    {
        std::cout << "There is no pawn";
        return;
    }
}

void moveWhiteKnight(Board &board, int from, int to)
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

    if (diff_rank == 2 && diff_file == 1 || diff_rank == 1 && diff_file == 2)
    {
        if (from_Mask & board._whitePieces[Knights] && to_Mask ^ NS_mask::whitePiecesMask(board))
        {
            board._whitePieces[Knights] ^= from_Mask;
            board._whitePieces[Knights] |= to_Mask;
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

void moveWhiteBishop(Board &board, int from, int to)
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

    if (diff_rank != diff_file)
    {
        printError();
        return;
    }

    int steps = diff_rank;
    int direction_change = (to - from)/steps;
    U64 current_Mask = from_Mask;

    for (steps; steps > 1; --steps)
    {
        current_Mask <<= direction_change;

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
        if (to_Mask & NS_mask::blackPiecesMask(board))
        {
            pieceToCaptureBlack(to_Mask, board);
        }
    }
}

void moveBlackBishop(Board &board, int from, int to)
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

    if (diff_rank != diff_file)
    {
        printError();
        return;
    }

    int steps = diff_rank;
    int direction_change = (to - from)/steps;
    U64 current_Mask = from_Mask;

    for (steps; steps > 1; --steps)
    {
        current_Mask <<= direction_change;

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
        if (to_Mask & NS_mask::whitePiecesMask(board))
        {
            pieceToCaptureWhite(to_Mask, board);
        }
    }
}

void moveWhiteRook(Board &board, int from, int to)
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

    if(diff_rank != 0 && diff_file != 0)
    {
        printError();
        return;
    }

    U64 current_Mask = from_Mask;
    int direction_change = 0;
    int steps = 0;

    if(diff_file != 0)
    {
        direction_change = (to - from)/diff_file;
        steps = diff_file;
    }
    else
    {
        direction_change = (to - from);
        steps = diff_rank;
    }

    for(steps; steps > 1; --steps)
    {
        current_Mask <<= direction_change;

        // std::cout << steps << std::endl;

        if(current_Mask & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
    }

    if(from_Mask & board._whitePieces[Rooks] && to_Mask ^ NS_mask::whitePiecesMask(board))
    {
        board._whitePieces[Rooks] ^= from_Mask;
        board._whitePieces[Rooks] |= to_Mask;
        if(to_Mask & NS_mask::blackPiecesMask(board))
        {
            pieceToCaptureBlack(to_Mask, board);
        }
    }
}

void moveBlackRook(Board &board, int from, int to)
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

    if(diff_rank != 0 && diff_file != 0)
    {
        printError();
        return;
    }

    U64 current_Mask = from_Mask;
    int direction_change = 0;
    int steps = 0;

    if(diff_file != 0)
    {
        direction_change = (to - from)/diff_file;
        steps = diff_file;
    }
    else
    {
        direction_change = (to - from);
        steps = diff_rank;
    }

    for(steps; steps > 1; --steps)
    {
        current_Mask <<= direction_change;

        // std::cout << steps << std::endl;

        if(current_Mask & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
    }

    if(from_Mask & board._blackPieces[Rooks] && to_Mask ^ NS_mask::blackPiecesMask(board))
    {
        board._blackPieces[Rooks] ^= from_Mask;
        board._blackPieces[Rooks] |= to_Mask;
        if(to_Mask & NS_mask::whitePiecesMask(board))
        {
            pieceToCaptureWhite(to_Mask, board);
        }
    }
}

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

void moveWhiteKing(Board &board, int from, int to)
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

    if(diff_rank > 1 || diff_file > 1)
    {
        printError();
        return;
    }
    if (from_Mask & board._whitePieces[King] && to_Mask ^ NS_mask::whitePiecesMask(board))
    {
        board._whitePieces[King] ^= from_Mask;
        board._whitePieces[King] |= to_Mask;
        if (to_Mask & NS_mask::blackPiecesMask(board))
        {
            pieceToCaptureBlack(to_Mask, board);
        }
    }
}
void moveBlackKing(Board &board, int from, int to)
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

    if(diff_rank > 1 || diff_file > 1)
    {
        printError();
        return;
    }
    if (from_Mask & board._blackPieces[King] && to_Mask ^ NS_mask::blackPiecesMask(board))
    {
        board._blackPieces[King] ^= from_Mask;
        board._blackPieces[King] |= to_Mask;
        if (to_Mask & NS_mask::whitePiecesMask(board))
        {
            pieceToCaptureWhite(to_Mask, board);
        }
    }
}