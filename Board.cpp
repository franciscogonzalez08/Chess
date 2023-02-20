#include "Board.h"

Board::Board(int widht, int height)
    : m_widht {widht}, m_height {height}
    {

    }

void Board::draw_board(sf::RenderWindow& window){
        sf::RectangleShape square(sf::Vector2f(50, 50));
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                // Alternate between black and white squares
                if ((row + col) % 2 == 0) {
                    square.setFillColor(sf::Color::Black);
                } else {
                    square.setFillColor(sf::Color::White);
                }
                // Squares are 50x50 pixels
                square.setPosition((col * 50) , (row * 50));
                window.draw(square);
                }
            }
        }