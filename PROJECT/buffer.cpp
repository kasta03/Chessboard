void moveBlackKnight(Board &board, int from, int to)
{
    U64 fromMask = 1ULL;
    U64 toMask = 1ULL;
    fromMask <<= from;
    toMask <<= to;
    if (fromMask & board._whitePieces[Knights])
    {
        // Corners
        if (from == A1 && (to == B3 || to == C2))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // H1 specific move
        else if (from == H1 && (to == G3 || to == F2))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // A8 specific move
        else if (from == A8 && (to == B6 || to == C7))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // H8 specific move
        else if (from == H8 && (to == G6 || to == F7))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // Edges close to corners
        // B1 specific move
        else if (from == B1 && (to == A3 || to == C3 || to == D2))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // G1 specific move
        else if (from == G1 && (to == F3 || to == H3 || to == E2))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // B8 specific move
        else if (from == B8 && (to == A6 || to == C6 || to == D7))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
            std::cout << "penis" << std::endl;
        }
        // G8 specific move
        else if (from == G8 && (to == F6 || to == H6 || to == E7))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // H7 specific move
        else if (from == H7 && (to == F8 || to == F6 || to == G5))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // A7 specific move
        else if (from == A7 && (to == B5 || to == C6 || to == C8))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // A2 specific move
        else if (from == A2 && (to == B4 || to == C3 || to == C1))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // H2 specific move
        else if (from == H2 && (to == F1 || to == F3 || to == G4))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // B2 specific move
        else if (from == B2 && (to == A4 || to == C4 || to == D3 || to == D1))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // G2 specific move
        else if (from == G2 && (to == F4 || to == H4 || to == E3 || to == E1))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // B7 specific move
        else if (from == B7 && (to == A5 || to == C5 || to == D6 || to == D8))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // G7 specific move
        else if (from == G7 && (to == F5 || to == H5 || to == E6 || to == E8))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // 1st rank
        else if (from / 1 == 0 && from != (A1||B1||G1||H1) && (to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17)))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // 2nd rank
        else if (from / 2 == 1 && from != (A2||B2||G2||H2) && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // 7th rank
        else if (from / 7 == 6 && from != (A7||B7||G7||H7) && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from - 15 || to == from - 17))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // 8th rank
        else if (from / 8 == 7 && from != (A8||A7||G8||H8) && (to == from - 6 || to == from - 10 || to == from - 15 || to == from - 17))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // A file
        else if (from % 8 == 0 && from != (A1||A2||A7||A8) && (to == from + 17 || to == from - 6 || to == from + 10 || to == from - 15))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // B file
        else if (from % 8 == 1 && from != (B1||B2||B7||B8) && (to == from + 17 || to == from - 6 || to == from + 15 || to == from + 10 || to == from - 15 || to == from - 17))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // G file
        else if (from % 8 == 6 && from != (G1||G2||G7||G8) && (to == from + 17 || to == from + 6 || to == from + 15 || to == from - 10 || to == from - 15 || to == from - 17))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // H file
        else if (from % 8 == 7 && from != (H1||H2||H7||H8) && (to == from - 17 || to == from + 6 || to == from - 10 || to == from + 15))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
        }
        // other places
        else if (from / 1 != 0 && from / 2 != 1 && from / 7 != 6 && from / 8 != 7 && from % 8 != 0 && from % 8 != 1 && from % 8 != 6 && from % 8 != 7 && (to == from - 6 || to == from + 6 || to == from - 10 || to == from + 10 || to == from - 15 || to == from + 15 || to == from - 17 || to == from + 17))
        {
            board._whitePieces[Knights] ^= fromMask;
            board._whitePieces[Knights] |= toMask;
            std::cout << "penis" << std::endl;
        }
        
    }
    // If there is no knight
    else
    {
        std::cout << "There is no knight";
        return;
    }
}

void moveWhitePawn(Board &board, int from, int to)
{
    // Setting masks
    U64 fromMask = 1ULL;
    U64 toMask = 1ULL;
    fromMask <<= from;
    toMask <<= to;

    // Checking if there is a pice on pointed square
    if (fromMask & board._whitePieces[Pawns])
    {
        // Checking captures from h to a and from a to h
        if ((from % 8 == 7 && to % 8 == 0) || (to % 8 == 7 && from % 8 == 0))
        {
            std::cout << "Illegal move" << std::endl;
            return;
        }
        // Move forward
        if (fromMask & (toMask >> 8))
        {
            board._whitePieces[Pawns] ^= fromMask;
            board._whitePieces[Pawns] |= toMask;
        }
        // Move forward twice
        else if ((from / 8 == 1) && ((from + 16) == to) && (!(toMask & (NS_mask::blackPicesMask(board) | NS_mask::whitePicesMask(board)))))
        {
            board._whitePieces[Pawns] ^= fromMask;
            board._whitePieces[Pawns] |= toMask;
        }
        // Captures
        else if (((from + 9) == to) && (toMask & NS_mask::blackPicesMask(board)))
        {
            pieceToCaptureBlack(toMask, board);
            board._whitePieces[Pawns] ^= fromMask;
            board._whitePieces[Pawns] |= toMask;
        }
        else if (((from + 7) == to) && (toMask & NS_mask::blackPicesMask(board)))
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



//////// Knight outdated

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