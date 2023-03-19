#include "Validator.h"
//Remove this, just for debugging
#include <iostream>
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

std::vector <std::pair<int,int>> Validator::pawn_movements(int x, int y, std::string color)
{
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
        for (std::pair<int,int> movement : possible_movements)
        {
            std::cout << movement.first << " " << movement.second << std::endl;
        }

    }
    return possible_movements;
}

void Validator::show_possible_movements(sf::RenderWindow& window, std::string piece_name, std::string piece_color, int x, int y)
{
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
}


std::string Validator::transform_name(std::string piece_name)
{
    std::string new_name = piece_name.substr(0, piece_name.size() - 2);
    return new_name;
}

