#include "Piece.h"
Piece::Piece(
    int x = 0, 
    int y = 0, 
    std::string name = "pawn", 
    std::string color = "white",
    std::string images_path = "images"
    ):  x_postion {x}, y_postion {y}, 
        m_name {name}, m_color {color},
        m_images_path {images_path}
{

}

void Piece::draw_piece(sf::RenderWindow& window)
{
    sf::Texture pieceTexture;
    if (!pieceTexture.loadFromFile(map_name()))
    {
        //add error handling
    }
    sf::Sprite pieceSprite(pieceTexture);
    pieceSprite.setPosition(sf::Vector2f(x_postion, y_postion));
    window.draw(pieceSprite);
}

std::string Piece::map_name()
{
    if (m_color == "white") {
        return m_images_path + "/w_" + m_name + ".png";
    } else {
        return m_images_path + "/b_" + m_name + ".png";
    }
    return "";
}