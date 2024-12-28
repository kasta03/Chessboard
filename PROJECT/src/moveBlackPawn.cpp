#include "move.h"

const int BACKWARD_ONE = -8;
const int BACKWARD_TWO = -16;
const int CAPTURE_LEFT_BLACK = -9;
const int CAPTURE_RIGHT_BLACK = -7;

void moveBlackPawn(Board &board, int from, int to)
{
    if (board.permission == 0)
    {
        printError();
        return;
    }
    bool validMove = false;

    // Setting masks
    U64 from_Mask = 1ULL << from;
    U64 to_Mask = 1ULL << to;
    U64 inBetween_Mask = 1ULL << (from + BACKWARD_ONE);

    int from_file = from % 8;
    int from_rank = from / 8;
    int to_file = to % 8;
    int to_rank = to / 8;

    bool isAtPointedSquare = from_Mask & board._blackPieces[Pawns];
    bool isInBetween = inBetween_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board));
    bool isAtToSquare = to_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board));

    // Checking if there is a piece on pointed square and there is no black piece on toSquare
    if (!isAtPointedSquare)
    {
        printError();
        return;
    }
    // Checking captures from h to a and from a to h
    if ((from_file == 7 && to_file == 0) || (to_file == 7 && from_file == 0))
    {
        printError();
        return;
    }
    // Move forward (downward for black)
    if (to == from + BACKWARD_ONE && (!isAtToSquare))
    {
        validMove = true;
    }
    // Move forward twice
    else if ((from / 8 == 6) && (from + BACKWARD_TWO == to) && (!isAtToSquare) && (!isInBetween))
    {
        validMove = true;
    }
    // En passant
    else if (((from + CAPTURE_RIGHT_BLACK == to) || (from + CAPTURE_LEFT_BLACK == to)) && board._previousMove.pieceType == Pawns && board._previousMove.from - BACKWARD_TWO == board._previousMove.to && std::abs(from - board._previousMove.to) == 1)
    {
        pieceToCaptureWhite(board._previousMove.to, board);
        validMove = true;
    }
    // Captures
    else if (((from + CAPTURE_RIGHT_BLACK == to) || (from + CAPTURE_LEFT_BLACK == to)) && (to_Mask & NS_mask::whitePiecesMask(board)))
    {
        pieceToCaptureWhite(to_Mask, board);
        validMove = true;
    }
    // If there is no pawn
    else
    {
        printError();
        return;
    }
    // Perform move
    if (validMove)
    {
        board._blackPieces[Pawns] ^= from_Mask;
        board._blackPieces[Pawns] |= to_Mask;

        flipSide(board);
        board._previousMove.pieceType = Pawns;
        board._previousMove.from = from;
        board._previousMove.to = to;
    }
    // Promotion
    if (to_rank == 0 && validMove)
    {
        int n = 0;
        std::cout << "What should be pawn promoted to? 1 - Queen, 2 - Rook, 3 - Bishop, 4 - Knight" << std::endl;
        std::cin >> n;
        std::cout << "Successfully promoted to: " << n << std::endl;

        board._blackPieces[Pawns] ^= to_Mask;

        switch (n)
        {
        case 1:
            board._blackPieces[Queen] |= to_Mask;
            break;
        case 2:
            board._blackPieces[Rooks] |= to_Mask;
            break;
        case 3:
            board._blackPieces[Bishops] |= to_Mask;
            break;
        case 4:
            board._blackPieces[Knights] |= to_Mask;
            break;
        default:
            std::cout << "Invalid choice for promotion." << std::endl;
            return;
        }
    }
}