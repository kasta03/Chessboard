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
            U64 positionMask = 1ULL;
            if ((positionMask <<= (file + rank * 8)) & picesType)
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
            if ((rank + file ) % 2 == 0)
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
}