#include "Graphic.h"

void graphicBoard()
{
    for (int rank = 7; rank >= 0; --rank)
    {
        std::cout << "\033[32m" << rank + 1 << " " << "\033[32m";
        for (int file = 0; file < 8; ++file)
        {
            std::cout << "\033[37m" << std::setw(3) << rank * 8 + file << " " << "\033[0m";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (auto i = 'A'; i <= 'H'; i++)
    {
        std::cout << "\033[32m" << "  " << i << " " << "\033[0m";
    }
    std::endl(std::cout);
}

void printPiecePosition(const U64 &picesType)
{
    for (int rank = 7; rank >= 0; --rank)
    {
        for (int file = 0; file < 8; ++file)
        {
            U64 positionMask = 1ULL << file + rank * 8;
            if (positionMask & picesType)
            {
                std::cout << "1 ";
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void drawBoard(sf::RenderWindow &window, Board &board)
{
    const int BOARD_SIZE = 8;
    const int SQUARE_SIZE = 80;

    for (int rank = 7; rank >= 0; --rank)
    {
        for (int file = 0; file < 8; ++file)
        {
            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            square.setPosition(file * SQUARE_SIZE, rank * SQUARE_SIZE);
            if ((rank + file) % 2 == 0)
            {
                square.setFillColor(sf::Color(155, 155, 155));
            }
            else
            {
                square.setFillColor(sf::Color::Blue);
            }
            window.draw(square);
        }
        std::cout << std::endl;
    }
    std::string path = PROJECTPATH;
    std::vector<sf::Texture> textures(12);
    textures[0].loadFromFile(path + "/img/WhitePawn.png");
    textures[1].loadFromFile(path + "/img/WhiteKnight.png");
    textures[2].loadFromFile(path + "/img/WhiteBishop.png");
    textures[3].loadFromFile(path + "/img/WhiteRook.png");
    textures[4].loadFromFile(path + "/img/WhiteQueen.png");
    textures[5].loadFromFile(path + "/img/WhiteKing.png");
    textures[6].loadFromFile(path + "/img/BlackPawn.png");
    textures[7].loadFromFile(path + "/img/BlackKnight.png");
    textures[8].loadFromFile(path + "/img/BlackBishop.png");
    textures[9].loadFromFile(path + "/img/BlackRook.png");
    textures[10].loadFromFile(path + "/img/BlackQueen.png");
    textures[11].loadFromFile(path + "/img/BlackKing.png");

    std::vector<sf::Sprite> sprites(12);
    for (int i = 0; i < 12; ++i)
    {
        sprites[i].setTexture(textures[i]);
        double scaleX = (double)SQUARE_SIZE / textures[i].getSize().x;
        double scaleY = (double)SQUARE_SIZE / textures[i].getSize().y;
        sprites[i].setScale(scaleX, scaleY);
    }

    for (int pieceType = 0; pieceType < 6; ++pieceType)
    {
        for (int pos = 0; pos < 64; pos++)
        {
            U64 mask = 1ULL << pos;
            int rank = 7 - (pos / 8); // Zmiana: odwrócenie rzędu
            int file = pos % 8;
            if (mask & board._whitePieces[pieceType])
            {
                sprites[pieceType].setPosition(file * SQUARE_SIZE, rank * SQUARE_SIZE);
                window.draw(sprites[pieceType]);
            }
            if (mask & board._blackPieces[pieceType])
            {
                sprites[pieceType + 6].setPosition(file * SQUARE_SIZE, rank * SQUARE_SIZE);
                window.draw(sprites[pieceType + 6]);
            }
        }
    }

    sf::Event event;
    struct selectedPiece
    {
        int pieceType;
        int pos;
        bool isWhite;
        bool selected = false;
    };

    static selectedPiece piece = {-1, -1, false};

    static U64 to_square = -1;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            int file = mousePosition.x / SQUARE_SIZE;
            int rank = 7 - (mousePosition.y / SQUARE_SIZE) % 8;
            for (int pieceType = 0; pieceType < 6; ++pieceType)
            {
                U64 mask = 1ULL << file + rank * 8;
                if (mask & board._whitePieces[pieceType])
                {
                    piece = {pieceType, file + rank * 8, true, true};
                    std::cout << piece.pos << std::endl;
                }
                else if (mask & board._blackPieces[pieceType])
                {
                    piece = {pieceType, file + rank * 8, false, true};
                }
            }
            if (piece.selected == true)
            {
                to_square = file + rank * 8;
            }
            if (piece.isWhite && to_square != piece.pos) 
            {
                switch (piece.pieceType)
                {
                case Pawns:
                    moveWhitePawn(board, piece.pos, to_square);
                    break;
                case Knights:
                    moveWhiteKnight(board, piece.pos, to_square);
                    break;
                case Bishops:
                    moveWhiteBishop(board, piece.pos, to_square);
                    break;
                case Rooks:
                    moveWhiteRook(board, piece.pos, to_square);
                    break;
                case Queen:
                    moveWhiteQueen(board, piece.pos, to_square);
                    break;
                case King:
                    moveWhiteKing(board, piece.pos, to_square);
                    break;
                }
                std::cout << to_square << std::endl;
                U64 mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
                printPiecePosition(mask);

                piece = {-1, -1, false, false};
                to_square = -1;
            }
            else if (!piece.isWhite && to_square != piece.pos) 
            {
                switch (piece.pieceType)
                {
                case Pawns:
                    moveBlackPawn(board, piece.pos, to_square);
                    std::cout << "Black pawn" << std::endl;
                    break;
                case Knights:
                    moveBlackKnight(board, piece.pos, to_square);
                    break;
                case Bishops:
                    moveBlackBishop(board, piece.pos, to_square);
                    break;
                case Rooks:
                    moveBlackRook(board, piece.pos, to_square);
                    break;
                case Queen:
                    moveBlackQueen(board, piece.pos, to_square);
                    break;
                case King:
                    moveBlackKing(board, piece.pos, to_square);
                    break;
                }
                std::cout << to_square << std::endl;
                U64 mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
                printPiecePosition(mask);

                piece = {-1, -1, false, false};
                to_square = -1;
            }
        }
    }
}