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

class Validator {
    private: std::pair < int,
    int > board_dims;
    std::string transform_name(std::string piece_name);
    void draw_square(sf::RenderWindow& window, int x, int y);
    std::pair<int,int> add_position(std::pair<int,int> piece_possition, int new_position);
    std::pair<int,int> compute_square_width_height();
    std::vector<std::pair<int,int>> assing_pawn_moves(int x_postion, int y_position);
    std::vector<std::pair<int,int>> compute_possible_moves(std::string piece_name, int x, int y);
    void draw_possible_moves(sf::RenderWindow & window, std::vector<std::pair<int,int>> possible_moves);

    public: Validator(int x, int y);
    void show_possible_moves(sf::RenderWindow& window, std::string piece_name, std::string piece_color, int piece_x_position, int piece_y_position,
                            std::vector<std::tuple<int, int,std::string>>);

};

#endif