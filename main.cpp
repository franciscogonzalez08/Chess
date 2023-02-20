#include "Piece.h"
#include "Board.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chessboard");
    Piece pawn(0, 0, "pawn", "white", "images");
    Piece rook(50, 0, "rook", "white", "images");
    Board board(400, 400);
    board.draw_board(window);
    pawn.draw_piece(window);
    rook.draw_piece(window);

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
