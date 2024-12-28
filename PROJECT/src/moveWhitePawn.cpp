#include "move.h"

const int FORWARD_ONE = 8;
const int FORWARD_TWO = 16;
const int CAPTURE_LEFT = 7;
const int CAPTURE_RIGHT = 9;

void moveWhitePawn(Board &board, int from, int to)
{
    if (board.permission == 1)
    {
        printError();
        return;
    }
    bool validMove = false;

    // Setting masks
    U64 from_Mask = 1ULL << from;
    U64 to_Mask = 1ULL << to;
    U64 inBetween_Mask = 1ULL << (from + FORWARD_ONE);

    int from_file = from % 8;
    int from_rank = from / 8;
    int to_file = to % 8;
    int to_rank = to / 8;

    bool isAtPointedSquare = from_Mask & board._whitePieces[Pawns];
    bool isInBetween = inBetween_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board));
    bool isAtToSquare = to_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board));

    // Checking if there is a piece on pointed square and there is no white piece on toSquare
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
    // Move forward
    if (to == from + FORWARD_ONE && (!isAtToSquare))
    {
        validMove = true;
    }
    // Move forward twice
    else if ((from / 8 == 1) && (from + FORWARD_TWO == to) && (!isAtToSquare) && (!isInBetween))
    {
        validMove = true;
    }
    // En passant
    else if (((from + CAPTURE_RIGHT == to) || (from + CAPTURE_LEFT == to)) && board._previousMove.pieceType == Pawns && board._previousMove.from - FORWARD_TWO == board._previousMove.to && std::abs(from - board._previousMove.to) == 1)
    {
        pieceToCaptureBlack(board._previousMove.to, board);
        validMove = true;
    }
    // Captures
    else if (((from + CAPTURE_RIGHT == to) || (from + CAPTURE_LEFT == to)) && (to_Mask & NS_mask::blackPiecesMask(board)))
    {
        pieceToCaptureBlack(to_Mask, board);
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
        board._whitePieces[Pawns] ^= from_Mask;
        board._whitePieces[Pawns] |= to_Mask;

        flipSide(board);
        board._previousMove.pieceType = Pawns;
        board._previousMove.from = from;
        board._previousMove.to = to;
    }
    // Promotion
    if (to_rank == 7 && validMove)
    {
        int n = 0;
        std::cout << "What should be pawn promoted to? 1 - Queen, 2 - Rook, 3 - Bishop, 4 - Knight" << std::endl;
        std::cin >> n;
        std::cout << "Succesfully promoted to: " << n << std::endl;

        board._whitePieces[Pawns] ^= to_Mask;

        switch (n)
        {
        case 1:
            board._whitePieces[Queen] |= to_Mask;
            break;
        case 2:
            board._whitePieces[Rooks] |= to_Mask;
            break;
        case 3:
            board._whitePieces[Bishops] |= to_Mask;
            break;
        case 4:
            board._whitePieces[Knights] |= to_Mask;
            break;
        default:
            std::cout << "Invalid choice for promotion." << std::endl;
            return;
        }
    }
}