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
    U64 fromMask = 1ULL << from;
    U64 toMask = 1ULL << to;
    U64 inBetweenMask = 1ULL << (from + FORWARD_ONE);

    int from_file = from % 8;
    int from_rank = from / 8;
    int to_file = to % 8;
    int to_rank = to / 8;

    bool isAtPointedSquare = from_Mask & board._whitePieces[Pawns];
    bool isInBetween = inBetween_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board));
    bool isAtToSquare = to_Mask & (NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board));

    // Checking if there is a piece on pointed square and there is no white piece on toSquare
    if (!isAtPointedSquare || isAtToSquare)
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
    if (to == from + FORWARD_ONE)
    {
        validMove = true;
    }
    // Move forward twice
    else if ((from / 8 == 1) && (from + FORWARD_TWO == to) && (!isAtToSquare) && (!isInBetween))
    {
        validMove = true;
    }
    // En passant
    else if (((from + CAPTURE_RIGHT == to) || (from + CAPTURE_LEFT == to)) && board.previousMove.pieceType == Pawns && board.previousMove.from - FORWARD_TWO == board.previousMove.to && std::abs(from - board.previousMove.to) == 1)
    {
        pieceToCaptureBlack(board.previousMove.to, board);
        validMove = true;
    }
    // Captures
    else if (((from + CAPTURE_RIGHT == to) || (from + CAPTURE_LEFT) == to) && (to_Mask & NS_mask::blackPiecesMask(board)))
    {
        pieceToCaptureBlack(to_Mask, board);
        validMove = true;
    }
    // if there is no pawn
    else
    {
        printError();
        return;
    }
    // perform move
    if (validMove)
    {
        board._whitePieces[Pawns] ^= from_Mask;
        board._whitePieces[Pawns] |= to_Mask;

        flipSide(board);
        board.previousMove.pieceType = Pawns;
        board.previousMove.from = from;
        board.previousMove.to = to;
    }

    if (to_rank == CAPTURE_LEFT && validMove)
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


void moveBlackPawn(Board &board, int from, int to)
{
    if (board.permission == 0)
    {
        printError();
        return;
    }
    // Checking if the piece is at pointed
    U64 from_Mask = 1ULL;
    U64 to_Mask = 1ULL;
    from_Mask <<= from;
    to_Mask <<= to;

    if ((from_Mask & board._blackPieces[Pawns]) && (to_Mask ^ NS_mask::blackPiecesMask(board)))
    {
        // Checking captures from h to a and from a to h
        if ((from_file == 7 && to_file == 0) || (to_file == 7 && from_file == 0))
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
        printError();
        return;
    }

    flipSide(board);

    if (to / 8 == 0)
    {
        int n = 0;
        std::cout << "What should the pawn be promoted to? 1 - Queen, 2 - Rook, 3 - Bishop, 4 - Knight" << std::endl;
        std::cin >> n;
        std::cout << "Successfully promoted to: " << n << std::endl;

        board._blackPieces[Pawns] ^= to_Mask;

        switch (n)
        {
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