#pragma once
#include <iostream>
#include <iomanip>
#include "Board.h"
#include <SFML/Graphics.hpp>

#define U64 unsigned long long

void printPiecePosition(const U64 &piecesType);

void graphicBoard();

void drawBoard(sf::RenderWindow &window, Board &board);