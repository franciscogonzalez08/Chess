#include <string>
#include <SFML/Graphics.hpp>

#ifndef PIECE_H
#define PIECE_H

/*
* Piece class
* This class is responsible for drawing the pieces on the board.
* Arguments:
*   x: x position of the piece  
*   y: y position of the piece
*   name: name of the piece
*   color: color of the piece
*   images_path: path to the images folder
*/ 

class Piece
{
private:
    int x_postion, y_postion;
    std::string m_name;
    std::string m_color;
    std::string m_images_path;

    std::string map_name();

public:
    Piece();

    Piece(
        int x, 
        int y, 
        std::string name, 
        std::string color, 
        std::string images_path
        );

    void draw_piece(sf::RenderWindow& window);
    void follow_mouse(sf::RenderWindow& window);
    void set_position(int x, int y);
    int get_x_position();
    int get_y_position();
};

#endif