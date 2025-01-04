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
            if (positionMask  & picesType)
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
                square.setFillColor(sf::Color::White);
            }
            else
            {
                square.setFillColor(sf::Color::Red);
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
                std::cout << "White piece: " << pieceType << " at position: " << pos << std::endl;
            }
            if (mask & board._blackPieces[pieceType])
            {
                sprites[pieceType + 6].setPosition(file * SQUARE_SIZE, rank * SQUARE_SIZE);
                window.draw(sprites[pieceType + 6]);
            }
        }
    }
}