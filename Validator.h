#include <utility>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#ifndef VALIDATOR_H
#define VALIDATOR_H

class Validator
{
private:
    std::pair<int,int> board_dims;
    std::string transform_name(std::string piece_name);
    //void draw_square(sf::RenderWindow& window, int x, int y);

public:
    Validator(int x, int y);
    void draw_square(sf::RenderWindow& window, int x, int y);
    std::vector <std::pair<int,int>> pawn_movements(int x, int y, std::string color);
    void show_possible_movements(sf::RenderWindow& window, std::string name, std::string color, int x, int y);
};

#endif