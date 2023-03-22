#include "Validator.h"
 //Remove this, just for debugging
#include <iostream>

Validator::Validator(int x, int y): board_dims(x, y) {}

void Validator::draw_square(sf::RenderWindow & window, int x, int y) {
    /*
    This function draws a square on the board.
    Arguments:
        window: window where the square will be drawn
        x: x position of the square
        y: y position of the square
    */
    std::pair<int,int> square_dims = compute_square_width_height();
    int square_widht = square_dims.first;
    int square_height = square_dims.second;
    sf::RectangleShape square(sf::Vector2f(square_widht, square_height));
    square.setFillColor(sf::Color(0, 255, 0, 128));
    square.setPosition(x, y);
    window.draw(square);
}

std::string Validator::transform_name(std::string piece_name) {
    /*
    This function transforms the name of the piece to a more readable name.
    Arguments:
        piece_name: name of the piece
    */
    std::string new_name = piece_name.substr(0, piece_name.size() - 2);
    return new_name;
}

std::pair<int,int> Validator::add_position(std::pair<int,int> piece_possition, int new_position)
{
    std::pair<int,int> square_dims = compute_square_width_height();
    int new_x_position, new_y_position;
    if (new_position == 1)
    {
        //Test case for white piece when moving forwards.
        new_x_position = piece_possition.first;
        new_y_position = piece_possition.second - square_dims.second;
        return std::make_pair(new_x_position, new_y_position); 
    }
}

std::pair<int,int> Validator::compute_square_width_height()
{
    return std::make_pair(static_cast <int> ( board_dims.first/8 ) , static_cast <int> (board_dims.second/8));
}
//Maybe pass the whole object ?? I am using all attributes.
void Validator::show_possible_moves(sf::RenderWindow& window, std::string piece_name, std::string piece_color, int piece_x_position, int piece_y_position,
                                        std::vector<std::tuple<int, int,std::string>>)
{
    std::vector<std::pair<int,int>> possible_moves = compute_possible_moves(piece_name, piece_x_position, piece_y_position);
    draw_possible_moves(window, possible_moves);    
}

std::vector<std::pair<int,int>> Validator::compute_possible_moves(std::string full_piece_name, int x, int y)
{
    std::vector<std::pair<int,int>> possible_moves;
    std::string piece_name = transform_name(full_piece_name);
    if (piece_name == "pawn")
    {
        possible_moves = assing_pawn_moves(x,y);
        return possible_moves;
    }
}

std::vector<std::pair<int,int>> Validator::assing_pawn_moves(int x_postion, int y_position)
{
    std::vector<std::pair<int,int>> possible_moves;
    possible_moves.push_back(add_position(std::make_pair(x_postion,y_position), 1));
    return possible_moves;    
}

void Validator::draw_possible_moves(sf::RenderWindow & window ,std::vector<std::pair<int,int>> possible_moves)
{
    for(std::pair<int,int> moves : possible_moves)
    {
        draw_square(window ,moves.first, moves.second);
    }
}