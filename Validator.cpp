#include "Validator.h"
//Remove this, just for debugging
#include <iostream>
Validator::Validator(int x, int y) : board_dims(x, y) {}

void Validator::draw_square(sf::RenderWindow& window, int x, int y)
{
    /*
    This function draws a square on the board.
    Arguments:
        window: window where the square will be drawn
        x: x position of the square
        y: y position of the square
    */
    int square_widht = static_cast<int>(board_dims.first/8);
    int square_height = static_cast<int>(board_dims.second/8);
    sf::RectangleShape square(sf::Vector2f(square_widht, square_height));
    square.setFillColor(sf::Color(0, 255, 0, 128)); 
    square.setPosition(x,y);
    window.draw(square);
}

std::vector <std::pair<int,int>> Validator::pawn_movements(int x, int y, std::string color)
{
    /*
    This function returns a vector with the possible movements of a pawn.
    Arguments:
        x: x position of the pawn
        y: y position of the pawn
        color: color of the pawn
    */
    std::vector <std::pair<int,int>> possible_movements;
    possible_movements.push_back({x,y});

    for (int i{0}; i < 2 ; ++i)
    {
        
        int x_movement, y_movement;
        if (color == "white")
        {
            x_movement = x ;
            y_movement = y + (i - 2) * static_cast<int>(board_dims.first/8);
        }
        else
        {
            x_movement = x;
            y_movement = y + (i + 1) * static_cast<int>(board_dims.second/8);
        } 
        
        std::pair <int,int> movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
    }
    return check_movements(possible_movements);
}

std::vector <std::pair<int,int>> Validator::king_movements(int x, int y, std::string color)
{
    /*
    This function returns a vector with the possible movements of a king.
    Arguments:
        x: x position of the king
        y: y position of the king
        color: color of the king
    */
    std::vector <std::pair<int,int>> possible_movements;
    possible_movements.push_back({x,y});
    int x_movement, y_movement;
    x_movement = x;
    y_movement = y - static_cast<int>(board_dims.second/8);
    std::pair <int,int> movement_coords = {x_movement, y_movement};
    possible_movements.push_back(movement_coords);
    x_movement = x;
    y_movement = y + static_cast<int>(board_dims.second/8);
    movement_coords = {x_movement, y_movement};
    possible_movements.push_back(movement_coords);
    x_movement = x - static_cast<int>(board_dims.first/8);
    y_movement = y;
    movement_coords = {x_movement, y_movement};
    possible_movements.push_back(movement_coords);
    x_movement = x + static_cast<int>(board_dims.first/8);
    y_movement = y;
    movement_coords = {x_movement, y_movement};
    possible_movements.push_back(movement_coords);
    return check_movements(possible_movements);
}

std::vector <std::pair<int,int>> Validator::bishop_movements(int x, int y, std::string color)
{
    
    /*
    This function returns a vector with the possible movements of a bishop.
    Arguments:
        x: x position of the bishop
        y: y position of the bishop
        color: color of the bishop
    */
    std::vector <std::pair<int,int>> possible_movements;
    possible_movements.push_back({x,y});
    int x_movement, y_movement;
    for (int i{0}; i<8; ++i)
    {
        x_movement = x + (i - 8) * static_cast<int>(board_dims.first/8);
        y_movement = y + (i - 8) * static_cast<int>(board_dims.first/8);
        std::pair <int,int> movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
        x_movement = x + i * static_cast<int>(board_dims.first/8);
        y_movement = y + i * static_cast<int>(board_dims.first/8);
        movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
        x_movement = x - i  * static_cast<int>(board_dims.first/8);
        y_movement = y + i * static_cast<int>(board_dims.first/8);
        movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
        x_movement = x + i * static_cast<int>(board_dims.first/8);
        y_movement = y - i * static_cast<int>(board_dims.first/8);
        movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
    }
    return check_movements(possible_movements);
}


std::vector <std::pair<int,int>> Validator::queen_movements(int x, int y, std::string color)
{
    /*
    This function returns a vector with the possible movements of a queen.
    Arguments:
        x: x position of the queen
        y: y position of the queen
        color: color of the queen
    */
    std::vector <std::pair<int,int>> possible_movements, bishop_movements, rook_movements;
    possible_movements.push_back({x,y});
    bishop_movements = this->bishop_movements(x,y,color);
    rook_movements = this->rook_movements(x,y,color);
    possible_movements.insert(possible_movements.end(), bishop_movements.begin(), bishop_movements.end());
    possible_movements.insert(possible_movements.end(), rook_movements.begin(), rook_movements.end());
    return check_movements(possible_movements);
}

/*
std::vector <std::pair<int,int>> Validator::knight_movements(int x, int y, std::string color)
{
    std::vector <std::pair<int,int>> possible_movements;
    possible_movements.push_back({x,y});
    int x_movement, y_movement;
}
*/
std::vector <std::pair<int,int>> Validator::rook_movements(int x, int y, std::string color)
{
    /*
    This function returns a vector with the possible movements of a rook.
    Arguments:
        x: x position of the rook
        y: y position of the rook
        color: color of the rook
    */
    std::vector <std::pair<int,int>> possible_movements;
    possible_movements.push_back({x,y});
    int x_movement, y_movement;
    for (int i{0}; i<8; ++i)
    {
        x_movement = x + (i - 8) * static_cast<int>(board_dims.first/8);
        y_movement = y;
        std::pair <int,int> movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
        x_movement = x + i * static_cast<int>(board_dims.first/8);
        y_movement = y;
        movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
        x_movement = x ;
        y_movement = y + i * static_cast<int>(board_dims.first/8);;
        movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
        x_movement = x ;
        y_movement = y + (i - 8) * static_cast<int>(board_dims.first/8);
        movement_coords = {x_movement, y_movement};
        possible_movements.push_back(movement_coords);
        
    }
    return check_movements(possible_movements);
}




std::vector <std::pair<int,int>> Validator::check_movements(std::vector <std::pair<int,int>> possible_movements)
{
    /*
    This function checks if the possible movements are valid.
    Arguments:
        possible_movements: vector with the possible movements of a piece
    */
    std::vector <std::pair<int,int>> valid_movements;
    for (std::pair<int,int> movement : possible_movements)
    {
        if (
            absolute_value(movement.first) <= board_dims.first && 
            absolute_value(movement.second) <= board_dims.second
            )
        {
            valid_movements.push_back(movement);
        }
    }
    return valid_movements;
}

void Validator::show_possible_movements(sf::RenderWindow& window, std::string piece_name, std::string piece_color, int x, int y)
{
    /*
    This function shows the possible movements of a piece.
    Arguments:
        window: window where the movements will be shown
        piece_name: name of the piece
        piece_color: color of the piece
        x: x position of the piece
        y: y position of the piece
    */
    std::string new_name = transform_name(piece_name);
    std::vector <std::pair<int,int>> possible_movements;

    if (new_name == "pawn") 
    {
        possible_movements = pawn_movements(x,y,piece_color);
        for (std::pair<int,int> movement : possible_movements)
        {
            draw_square(window, movement.first, movement.second);
        }
    }

    else if (new_name == "king")
    {
        possible_movements = king_movements(x,y,piece_color);
        for (std::pair<int,int> movement : possible_movements)
        {
            draw_square(window, movement.first, movement.second);
        }
    }

    else if (new_name == "rook")
    {
        possible_movements = rook_movements(x,y,piece_color);
        for (std::pair<int,int> movement : possible_movements)
        {
            draw_square(window, movement.first, movement.second);
        }
    }

    else if (new_name == "bishop")
    {
        possible_movements = bishop_movements(x,y,piece_color);
        for (std::pair<int,int> movement : possible_movements)
        {
            draw_square(window, movement.first, movement.second);
        }
    }


    else if (new_name == "queen")
    {
        possible_movements = queen_movements(x,y,piece_color);
        for (std::pair<int,int> movement : possible_movements)
        {
            draw_square(window, movement.first, movement.second);
        }
    }

    /*
    else if (new_name == "knight")
    {
        possible_movements = knight_movements(x,y,piece_color);
        for (std::pair<int,int> movement : possible_movements)
        {
            draw_square(window, movement.first, movement.second);
        }
    }
    */
    
}


std::string Validator::transform_name(std::string piece_name)
{
    /*
    This function transforms the name of the piece to a more readable name.
    Arguments:
        piece_name: name of the piece
    */
    std::string new_name = piece_name.substr(0, piece_name.size() - 2);
    return new_name;
}

template <typename T>
T Validator::absolute_value(T val) const {
  if (val < 0) {
    return -val;
  }
  return val;
}