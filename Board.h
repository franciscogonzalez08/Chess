#include <SFML/Graphics.hpp>

#ifndef BOARD_H
#define BOARD_H

/*
* Board class
* This class is responsible for drawing the chessboard
* and the pieces on the board.
* The board is a 8x8 grid of squares.
*/

class Board
{
private:
    int m_widht;
    int m_height;

public:
    Board();
    Board(
        int widht, 
        int height
        );
    void draw_board(sf::RenderWindow& window);


};

#endif