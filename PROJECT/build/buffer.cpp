
void moveWhiteKnight(Board &board, int from, int to)
{
    U64 fromMask = 1ULL;
    U64 toMask = 1ULL;
    fromMask <<= from;
    toMask <<= to;
    if (fromMask & board._whitePices[Knights])
    {
        // Corners
        if (from == A1 && (to == B3 || to == C2))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // H1 specific move
        else if (from == H1 && (to == G3 || to == F2))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // A8 specific move
        else if (from == A8 && (to == B6 || to == C7))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // H8 specific move
        else if (from == H8 && (to == G6 || to == F7))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // Edges close to corners
        // B1 specific move
        else if (from == B1 && (to == A3 || to == C3 || to == D2))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // G1 specific move
        else if (from == G1 && (to == F3 || to == H3 || to == E2))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // B8 specific move
        else if (from == B8 && (to == A6 || to == C6 || to == D7))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // G8 specific move
        else if (from == G8 && (to == F6 || to == H6 || to == E7))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // H7 specific move
        else if (from == H7 && (to == F8 || to == F6 || to == G5))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // A7 specific move
        else if (from == A7 && (to == B5 || to == C6 || to == C8))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // A2 specific move
        else if (from == A2 && (to == B4 || to == C3 || to == C1))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // H2 specific move
        else if (from == H2 && (to == F1 || to == F3 || to == G4))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // B2 specific move
        else if (from == B2 && (to == A4 || to == C4 || to == D3 || to == D1))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // G2 specific move
        else if (from == G2 && (to == F4 || to == H4 || to == E3 || to == E1))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // B7 specific move
        else if (from == B7 && (to == A5 || to == C5 || to == D6 || to == D8))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // G7 specific move
        else if (from == G7 && (to == F5 || to == H5 || to == E6 || to == E8))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // 1st rank
        else if (from / 1 == 0 && (to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // 2nd rank
        else if (from / 2 == 1 && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from + 15 || to == from + 17))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // 7th rank
        else if (from / 7 == 6 && (to == from - 10 || to == from - 6 || to == from + 6 || to == from + 10 || to == from - 15 || to == from - 17))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // 8th rank
        else if (from / 8 == 7 && (to == from - 6 || to == from - 10 || to == from - 15 || to == from - 17))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // A file
        else if (from % 8 == 0 && (to == from + 17 || to == from - 6 || to == from + 10 || to == from - 15))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // B file
        else if (from % 8 == 1 && (to == from + 17 || to == from - 6 || to == from + 15 || to == from + 10 || to == from - 15 || to == from - 17))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // G file
        else if (from % 8 == 6 && (to == from + 17 || to == from + 6 || to == from + 15 || to == from - 10 || to == from - 15 || to == from - 17))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // H file
        else if (from % 8 == 7 && (to == from - 17 || to == from + 6 || to == from - 10 || to == from + 15))
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        // other places
        else if (to == from - 6 || to == from + 6 || to == from - 10 || to == from + 10 || to == from - 15 || to == from + 15 || to == from - 17 || to == from + 17)
        {
            board._whitePices[Knights] ^= fromMask;
            board._whitePices[Knights] |= toMask;
        }
        
    }
    // If there is no knight
    else
    {
        std::cout << "There is no knight";
        return;
    }
}