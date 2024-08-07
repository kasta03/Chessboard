#include "Graphic.h"


void graphicBoard()
{
    for (int rank = 0; rank < 8; rank++)
    {
        std::cout << rank + 1 << " ";
        for (int file = 0; file < 8; file++)
        {
            std::cout << std::setw(3) << rank * 8 + file << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << " ";
    for (auto i = 'A'; i <= 'H'; i++)
    {
        std::cout << "  " << i << " ";
    }
}



void printPicePosition(U64 &picesType)
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
