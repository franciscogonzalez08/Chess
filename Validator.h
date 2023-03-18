#include <utility>
#include <SFML/Graphics.hpp>

#ifndef VALIDATOR_H
#define VALIDATOR_H

class Validator
{
private:
    std::pair<int,int> board_dims;
    //void draw_square(sf::RenderWindow& window, int x, int y);

public:
    Validator(int x, int y);
    void draw_square(sf::RenderWindow& window, int x, int y);

};

#endif