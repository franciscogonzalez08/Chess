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
    int check_colision(std::pair<int,int> new_move, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::string transform_name(std::string piece_name);
    std::pair<int,int> add_position(std::pair<int,int> piece_possition, std::pair<int,int> new_position);
    std::pair<int,int> compute_square_width_height();
    std::vector<std::pair<int,int>> compute_possible_moves(std::string piece_name, int x, int y, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::vector<std::pair<int,int>> assing_pawn_moves(int x_postion, int y_position, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::vector<std::pair<int,int>> assing_knight_moves(int x_postion, int y_position, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::vector<std::pair<int,int>> assing_bishop_moves(int x_postion, int y_position, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::vector<std::pair<int,int>> assing_queen_moves(int x_postion, int y_position, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::vector<std::pair<int,int>> assing_king_moves(int x_postion, int y_position, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::vector<std::pair<int,int>> assing_rook_moves(int x_postion, int y_position, std::vector<std::tuple<int, int,std::string>> pieces_info, std::string piece_color);
    std::vector<std::pair<int,int>> stack_moves(int x_postion, int y_position, int direction, int number_of_moves, 
    std::vector<std::tuple<int, int,std::string>> pieces_info, std::vector<std::pair<int,int>> original_possible_moves, std::string piece_color);
    void draw_square(sf::RenderWindow& window, int x, int y);
    void draw_possible_moves(sf::RenderWindow & window, std::vector<std::pair<int,int>> possible_moves);

    public: Validator(int x, int y);
    std::vector<std::pair<int,int>> show_possible_moves(sf::RenderWindow& window, std::string piece_name, std::string piece_color, int piece_x_position, int piece_y_position,
                            std::vector<std::tuple<int, int,std::string>>);

};

#endif