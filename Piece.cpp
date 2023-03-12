#include "Piece.h"
Piece::Piece(): x_position {0}, y_position {0}, m_name {"pawn"}, m_color {"white"}, m_images_path {"images"}, alive {true} {}


Piece::Piece(
    int x = 0, 
    int y = 0, 
    std::string name = "pawn", 
    std::string color = "white",
    std::string images_path = "images"
    ):  x_position {x}, y_position {y}, 
        m_name {name}, m_color {color},
        m_images_path {images_path}, alive {true}
{

}

void Piece::draw_piece(sf::RenderWindow& window, int height)
{
    sf::Texture pieceTexture;
    if (!pieceTexture.loadFromFile(map_name()))
    {
        //add error handling
    }
    if (alive)
    {
    // Suppose the height of the window is 800 pixels
    // Square size is 100 pixels
    // 
    int square_size = static_cast<int>(height/8);
    int square_number_x = static_cast<int>(x_position/square_size);
    int square_number_y = static_cast<int>(y_position/square_size);
    int center_x = square_number_x*square_size - square_size/8 ;
    int center_y = square_number_y*square_size - square_size/8;
    sf::Sprite pieceSprite(pieceTexture);
    pieceSprite.setPosition(sf::Vector2f(center_x, center_y));
    window.draw(pieceSprite);
    }
    else
    {
        //do nothing
    }

}

std::string Piece::map_name()
{
    std::string piece_name = m_name.substr(0, m_name.size() - 2);
    if (m_color == "white") {
        return m_images_path + "/w_" + piece_name + ".png";
    } else {
        return m_images_path + "/b_" + piece_name + ".png";
    }
    return "";
}

void Piece::follow_mouse(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        x_position = mousePos.x;
        y_position = mousePos.y;
    }
}

void Piece::set_position(int x, int y)
{
    x_position = x;
    y_position = y;
}

int Piece::get_x_position() const
{
    return x_position;
}

int Piece::get_y_position() const
{
    return y_position;
}

std::string Piece::get_name() const
{
    return m_name;
}

