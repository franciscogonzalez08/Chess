#include <utility>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#ifndef VALIDATOR_H
#define VALIDATOR_H

/*
* Validator class
* This class is responsible for validating the movements of the pieces.
* Arguments:
*   x: x position of the piece
*   y: y position of the piece
*/

class Validator
{
private:
    std::pair<int,int> board_dims;
    std::string transform_name(std::string piece_name);
    template <typename T> T absolute_value(T val) const;
    //void draw_square(sf::RenderWindow& window, int x, int y);

public:
    Validator(int x, int y);
    void draw_square(sf::RenderWindow& window, int x, int y);
    std::vector <std::pair<int,int>> pawn_movements(int x, int y, std::string color);
    std::vector <std::pair<int,int>> queen_movements(int x, int y, std::string color);
    std::vector <std::pair<int,int>> king_movements(int x, int y, std::string color);
    std::vector <std::pair<int,int>> bishop_movements(int x, int y, std::string color);
    //std::vector <std::pair<int,int>> knight_movements(int x, int y, std::string color);
    std::vector <std::pair<int,int>> rook_movements(int x, int y, std::string color);
    std::vector <std::pair<int,int>> check_movements(std::vector <std::pair<int,int>> possible_movements);
    void show_possible_movements(sf::RenderWindow& window, std::string name, std::string color, int x, int y);
    
};

#endif