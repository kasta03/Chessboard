#include "move.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

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

void pieceToCaptureBlack(U64 toMask, Board &board)
{
    if (toMask & board._blackPieces.at(0))
    {
        board._blackPieces.at(0) ^= toMask;
    }
    else if (toMask & board._blackPieces.at(1))
    {
        board._blackPieces.at(1) ^= toMask;
    }
    else if (toMask & board._blackPieces.at(2))
    {
        board._blackPieces.at(2) ^= toMask;
    }
    else if (toMask & board._blackPieces.at(3))
    {
        board._blackPieces.at(3) ^= toMask;
    }
    else if (toMask & board._blackPieces.at(4))
    {
        board._blackPieces.at(4) ^= toMask;
    }
}

void pieceToCaptureWhite(U64 toMask, Board &board)
{
    if (toMask & board._whitePieces.at(0))
    {
        board._whitePieces.at(0) ^= toMask;
    }
    else if (toMask & board._whitePieces.at(1))
    {
        board._whitePieces.at(1) ^= toMask;
    }
    else if (toMask & board._whitePieces.at(2))
    {
        board._whitePieces.at(2) ^= toMask;
    }
    else if (toMask & board._whitePieces.at(3))
    {
        board._whitePieces.at(3) ^= toMask;
    }
    else if (toMask & board._whitePieces.at(4))
    {
        board._whitePieces.at(4) ^= toMask;
    }
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
    U64 fromMask = 1ULL;
    U64 toMask = 1ULL;
    fromMask <<= from;
    toMask <<= to;

    // Checking if there is a piece on pointed square and there is no white piece on toSquare
    if (fromMask & board._whitePieces[Pawns])
    {
        // Checking captures from h to a and from a to h
        if ((from % 8 == 7 && to % 8 == 0) || (to % 8 == 7 && from % 8 == 0))
        {
            std::cout << "Illegal move" << std::endl;
            return;
        }
        // Move forward or Move forward twice
        if ((fromMask & (toMask >> 8)) || ((from / 8 == 1) && ((from + 16) == to) && (!(toMask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board))))))
        {
            board._whitePieces[Pawns] ^= fromMask;
            board._whitePieces[Pawns] |= toMask;
        }
        // Captures
        else if ((((from + 9) == to) || ((from + 7) == to)) && (toMask & NS_mask::blackPiecesMask(board)))
        {
            pieceToCaptureBlack(toMask, board);
            board._whitePieces[Pawns] ^= fromMask;
            board._whitePieces[Pawns] |= toMask;
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
    U64 fromMask = 1ULL;
    U64 toMask = 1ULL;
    fromMask <<= from;
    toMask <<= to;

    if ((fromMask & board._blackPieces[Pawns]) && (toMask ^ NS_mask::blackPiecesMask(board)))
    {
        // Checking captures from h to a and from a to h
        if ((from % 8 == 7 && to % 8 == 0) || (to % 8 == 7 && from % 8 == 0))
        {
            std::cout << "Illegal move" << std::endl;
            return;
        }
        // Move forward or Move forward twice
        if ((fromMask & (toMask << 8)) || ((from / 8 == 6) && ((from - 16) == to) && (!(toMask & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board))))))
        {
            board._blackPieces[Pawns] ^= fromMask;
            board._blackPieces[Pawns] |= toMask;
        }
        // Captures
        else if ((((from - 9) == to) || ((from - 7) == to)) && (toMask & NS_mask::whitePiecesMask(board)))
        {
            pieceToCaptureWhite(toMask, board);
            board._blackPieces[Pawns] ^= fromMask;
            board._blackPieces[Pawns] |= toMask;
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
    U64 fromMask = 1ULL << from;
    U64 toMask = 1ULL << to;
    if ((fromMask & board._whitePieces[Knights]) && (toMask ^ NS_mask::whitePiecesMask(board))) 
    {
        if ( (from == A1 && (to == B3 || to == C2)) || // A1 specific moves
             (from == H1 && (to == G3 || to == F2)) || // H1 specific moves
             (from == A8 && (to == B6 || to == C7)) || // A8 specific moves
             (from == H8 && (to == G6 || to == F7)) || // H8 specific moves
             (from == B1 && (to == A3 || to == C3 || to == D2)) || // B1 specific moves
             (from == G1 && (to == F3 || to == H3 || to == E2)) || // G1 specific moves
             (from == B8 && (to == A6 || to == C6 || to == D7)) || // B8 specific moves
             (from == G8 && (to == F6 || to == H6 || to == E7)) || // G8 specific moves
             (from == H7 && (to == F8 || to == F6 || to == G5)) || // H7 specific moves
             (from == A7 && (to == B5 || to == C6 || to == C8)) || // A7 specific moves
             (from == A2 && (to == B4 || to == C3 || to == C1)) || // A2 specific moves
             (from == H2 && (to == F1 || to == F3 || to == G4)) || // H2 specific moves
             (from == B2 && (to == A4 || to == C4 || to == D3 || to == D1)) || // B2 specific moves
             (from == G2 && (to == F4 || to == H4 || to == E3 || to == E1)) || // G2 specific moves
             (from == B7 && (to == A5 || to == C5 || to == D6 || to == D8)) || // B7 specific moves
             (from == G7 && (to == F5 || to == H5 || to == E6 || to == E8)) || // G7 specific moves
             (from / 1 == 0 && from != A1 && from != B1 && from != G1 && from != H1 && (to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17)) || // 1st rank moves
             (from / 2 == 1 && from != A2 && from != B2 && from != G2 && from != H2 && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17)) || // 2nd rank moves
             (from / 7 == 6 && from != A7 && from != B7 && from != G7 && from != H7 && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from - 15 || to == from - 17)) || // 7th rank moves
             (from / 8 == 7 && from != A8 && from != B8 && from != G8 && from != H8 && (to == from - 6 || to == from - 10 || to == from - 15 || to == from - 17)) || // 8th rank moves
             (from % 8 == 0 && from != A1 && from != A2 && from != A7 && from != A8 && (to == from + 17 || to == from - 6 || to == from + 10 || to == from - 15)) || // A file moves
             (from % 8 == 1 && from != B1 && from != B2 && from != B7 && from != B8 && (to == from + 17 || to == from - 6 || to == from + 15 || to == from + 10 || to == from - 15 || to == from - 17)) || // B file moves
             (from % 8 == 6 && from != G1 && from != G2 && from != G7 && from != G8 && (to == from + 17 || to == from + 6 || to == from + 15 || to == from - 10 || to == from - 15 || to == from - 17)) || // G file moves
             (from % 8 == 7 && from != H1 && from != H2 && from != H7 && from != H8 && (to == from - 17 || to == from + 6 || to == from - 10 || to == from + 15)) || // H file moves
             (from / 1 != 0 && from / 2 != 1 && from / 7 != 6 && from / 8 != 7 && from % 8 != 0 && from % 8 != 1 && from % 8 != 6 && from % 8 != 7 && (to == from - 6 || to == from + 6 || to == from - 10 || to == from + 10 || to == from - 15 || to == from + 15 || to == from - 17 || to == from + 17)) // General moves
           ) 
        {
            // Update the board
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
            if (toMask & NS_mask::blackPiecesMask(board)) 
            {
                pieceToCaptureBlack(toMask, board);
            }
        }
    } 
    // If there is no knight
    else 
    {
        std::cout << "There is no knight";
        return;
    }
}

void moveBlackKnight(Board &board, int from, int to)
{
    U64 fromMask = 1ULL;
    U64 toMask = 1ULL;
    fromMask <<= from;
    toMask <<= to;
    if ((fromMask & board._blackPieces[Knights]) && (toMask ^ NS_mask::blackPiecesMask(board)))
    {
        if (
            (from == A1 && (to == B3 || to == C2)) || // A1 specific moves
            (from == H1 && (to == G3 || to == F2)) || // H1 specific moves
            (from == A8 && (to == B6 || to == C7)) || // A8 specific moves
            (from == H8 && (to == G6 || to == F7)) || // H8 specific moves
            (from == B1 && (to == A3 || to == C3 || to == D2)) || // B1 specific moves
            (from == G1 && (to == F3 || to == H3 || to == E2)) || // G1 specific moves
            (from == B8 && (to == A6 || to == C6 || to == D7)) || // B8 specific moves
            (from == G8 && (to == F6 || to == H6 || to == E7)) || // G8 specific moves
            (from == H7 && (to == F8 || to == F6 || to == G5)) || // H7 specific moves
            (from == A7 && (to == B5 || to == C6 || to == C8)) || // A7 specific moves
            (from == A2 && (to == B4 || to == C3 || to == C1)) || // A2 specific moves
            (from == H2 && (to == F1 || to == F3 || to == G4)) || // H2 specific moves
            (from == B2 && (to == A4 || to == C4 || to == D3 || to == D1)) || // B2 specific moves
            (from == G2 && (to == F4 || to == H4 || to == E3 || to == E1)) || // G2 specific moves
            (from == B7 && (to == A5 || to == C5 || to == D6 || to == D8)) || // B7 specific moves
            (from == G7 && (to == F5 || to == H5 || to == E6 || to == E8)) || // G7 specific moves
            (from / 1 == 0 && from != A1 && from != B1 && from != G1 && from != H1 && (to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17)) || // 1st rank moves
            (from / 2 == 1 && from != A2 && from != B2 && from != G2 && from != H2 && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17)) || // 2nd rank moves
            (from / 7 == 6 && from != A7 && from != B7 && from != G7 && from != H7 && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from - 15 || to == from - 17)) || // 7th rank moves
            (from / 8 == 7 && from != A8 && from != B8 && from != G8 && from != H8 && (to == from - 6 || to == from - 10 || to == from - 15 || to == from - 17)) || // 8th rank moves
            (from % 8 == 0 && from != A1 && from != A2 && from != A7 && from != A8 && (to == from + 17 || to == from - 6 || to == from + 10 || to == from - 15)) || // A file moves
            (from % 8 == 1 && from != B1 && from != B2 && from != B7 && from != B8 && (to == from + 17 || to == from - 6 || to == from + 15 || to == from + 10 || to == from - 15 || to == from - 17)) || // B file moves
            (from % 8 == 6 && from != G1 && from != G2 && from != G7 && from != G8 && (to == from + 17 || to == from + 6 || to == from + 15 || to == from - 10 || to == from - 15 || to == from - 17)) || // G file moves
            (from % 8 == 7 && from != H1 && from != H2 && from != H7 && from != H8 && (to == from - 17 || to == from + 6 || to == from - 10 || to == from + 15)) || // H file moves
            (from / 1 != 0 && from / 2 != 1 && from / 7 != 6 && from / 8 != 7 && from % 8 != 0 && from % 8 != 1 && from % 8 != 6 && from % 8 != 7 && (to == from - 6 || to == from + 6 || to == from - 10 || to == from + 10 || to == from - 15 || to == from + 15 || to == from - 17 || to == from + 17)) // General moves
        )
        {
            // Update the board
            board._blackPieces[Knights] ^= fromMask;
            board._blackPieces[Knights] |= toMask;
            if(toMask & NS_mask::whitePiecesMask(board))
            {
                pieceToCaptureWhite(toMask, board);
            }
        }
    }
    // If there is no knight
    else
    {
        std::cout << "There is no knight";
        return;
    }
}
