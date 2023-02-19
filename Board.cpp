#include <SFML/Graphics.hpp>

/*
* Board class
* This class is responsible for drawing the chessboard
* and the pieces on the board.
* The board is a 8x8 grid of squares.
*/

class Board
{
private:
    int m_widht;
    int m_height;

public:
    Board(int widht = 400, int height = 400)
        : m_widht {widht}, m_height {height}
        {

        }

    void draw_board(sf::RenderWindow& window){
        sf::RectangleShape square(sf::Vector2f(50, 50));
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                // Alternate between black and white squares
                if ((row + col) % 2 == 0) {
                    square.setFillColor(sf::Color::Black);
                } else {
                    square.setFillColor(sf::Color::White);
                }
                // Squares are 50x50 pixels
                square.setPosition((col * 50) , (row * 50));
                window.draw(square);
                }
            }
        }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chessboard");
    Board board;
    board.draw_board(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
        sf::sleep(sf::milliseconds(50)); 
    }

    return 0;
}
