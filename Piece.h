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
    int x_position, y_position;
    std::string m_name;
    std::string m_color;
    std::string m_images_path;
    std::string map_name();

public:
    Piece();
    bool alive;

    Piece(
        int x, 
        int y, 
        std::string name, 
        std::string color, 
        std::string images_path
        );

    void draw_piece(sf::RenderWindow& window, int height);
    void follow_mouse(sf::RenderWindow& window);
    void set_position(int x, int y);
    int get_x_position() const;
    int get_y_position() const;
    std::string get_name() const;
    std::string get_color() const;
};

#endif