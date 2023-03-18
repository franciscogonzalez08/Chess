#include <utility>
#include <SFML/Graphics.hpp>
#include "Validator.h"

Validator::Validator(int x, int y) : board_dims(x, y) {}

void Validator::draw_square(sf::RenderWindow& window, int x, int y)
{
    int square_widht = static_cast<int>(board_dims.first/8);
    int square_height = static_cast<int>(board_dims.second/8);
    sf::RectangleShape square(sf::Vector2f(square_widht, square_height));
    square.setFillColor(sf::Color(0, 255, 0, 128)); 
    square.setPosition(x,y);
    window.draw(square);
}
