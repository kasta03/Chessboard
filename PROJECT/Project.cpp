#include "Board.h"
#include "move.h"
#include "Graphic.h"

#define U64 unsigned long long

int main()
{    
    const int BOARD_SIZE = 8;
    const int SQUARE_SIZE = 80;
    sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * SQUARE_SIZE, BOARD_SIZE * SQUARE_SIZE), "Chess Game");
    Board board;
    graphicBoard();

    U64 mask = NS_mask::blackPiecesMask(board) | NS_mask::whitePiecesMask(board);
    printPiecePosition(mask);
    
    drawBoard(window, board);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
                
        // Draw chess board
        drawBoard(window, board);
        
        // Display changes
        window.display();
    }

    return 0;
}
