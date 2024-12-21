#include "move.h"


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
    if (to / 8 == 7) 
    {
        int n = 0;
        std::cout << "What should be pawn promoted to? 1 - Queen, 2 - Rook, 3 - Bishop, 4 - Knight" << std::endl;
        std::cin << n << std::endl;
        std::cout << "Succesfully promoted to: " << n << std::endl;

        switch (n)
        {
            board._whitePieces[Pawns] ^= to_Mask;
            case 1:
                board._whitePieces[Queen] ^= to_Mask;
            case 2:
                board._whitePieces[Rooks] ^= to_Mask;
            case 3:
                board._whitePieces[Bishops] ^= to_Mask;
            case 4:
                board._whitePieces[Knights] ^= to_Mask;
        }
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
    if (to / 8 == 0) 
    {
        int n = 0;
        std::cout << "What should the pawn be promoted to? 1 - Queen, 2 - Rook, 3 - Bishop, 4 - Knight" << std::endl;
        std::cin >> n;
        std::cout << "Successfully promoted to: " << n << std::endl;

        switch (n)
        {
            board._blackPieces[Pawns] ^= to_Mask;
            case 1:
                board._blackPieces[Queen] ^= to_Mask;
                break;
            case 2:
                board._blackPieces[Rooks] ^= to_Mask;
                break;
            case 3:
                board._blackPieces[Bishops] ^= to_Mask;
                break;
            case 4:
                board._blackPieces[Knights] ^= to_Mask;
                break;
            default:
                std::cout << "Invalid choice for promotion." << std::endl;
                return;
        }
    }    
}