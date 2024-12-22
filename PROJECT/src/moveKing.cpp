#include "move.h"

void moveWhiteKing(Board &board, int from, int to)
{
    if (board.permission == 1)
    {
        printError();
        return;
    }
    if (board.whiteShortCastle == true && from == 4 && to == 6)
    {
        U64 kingPath = (1ULL << 5) | (1ULL << 6);
        if (kingPath & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
        board._whitePieces[King] <<= 2;
        board._whitePieces[Rooks] ^= (1ULL << 7);
        board._whitePieces[Rooks] |= (1ULL << 5);
        board.whiteShortCastle = false;
        board.whiteLongCastle = false;
        flipSide(board);
        return;
    }
    else if (board.whiteLongCastle == true && from == 4 && to == 2)
    {
        U64 kingPath = (1ULL << 3) | (1ULL << 2) | (1ULL << 1);
        if (kingPath & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
        board._whitePieces[King] >>= 2;
        board._whitePieces[Rooks] ^= (1ULL << 0);
        board._whitePieces[Rooks] |= (1ULL << 3);
        board.whiteLongCastle = false;
        board.whiteShortCastle = false;
        flipSide(board);
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

    if (diff_rank > 1 || diff_file > 1)
    {
        printError();
        return;
    }
    if (from_Mask & board._whitePieces[King] && to_Mask ^ NS_mask::whitePiecesMask(board))
    {
        board._whitePieces[King] ^= from_Mask;
        board._whitePieces[King] |= to_Mask;
        flipSide(board);
        board.whiteShortCastle = false;
        board.whiteLongCastle = false;
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

void moveBlackKing(Board &board, int from, int to)
{
    if (board.permission == 0)
    {
        printError();
        return;
    }
    if (board.blackShortCastle == true && from == 60 && to == 62)
    {
        U64 kingPath = (1ULL << 61) | (1ULL << 62);
        if (kingPath & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
        board._blackPieces[King] <<= 2;
        board._blackPieces[Rooks] ^= (1ULL << 63);
        board._blackPieces[Rooks] |= (1ULL << 61);
        board.blackShortCastle = false;
        board.blackLongCastle = false;
        flipSide(board);
        return;
    }
    else if (board.blackLongCastle == true && from == 60 && to == 58)
    {
        U64 kingPath = (1ULL << 57) | (1ULL << 58) | (1ULL << 59);
        if (kingPath & (NS_mask::whitePiecesMask(board) | NS_mask::blackPiecesMask(board)))
        {
            printError();
            return;
        }
        board._blackPieces[King] >>= 2;
        board._blackPieces[Rooks] ^= (1ULL << 56);
        board._blackPieces[Rooks] |= (1ULL << 59);
        board.blackLongCastle = false;
        board.blackShortCastle = false;
        flipSide(board);
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

    if (diff_rank > 1 || diff_file > 1)
    {
        printError();
        return;
    }
    if (from_Mask & board._blackPieces[King] && to_Mask ^ NS_mask::blackPiecesMask(board))
    {
        board._blackPieces[King] ^= from_Mask;
        board._blackPieces[King] |= to_Mask;
        flipSide(board);
        board.blackShortCastle = false;
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