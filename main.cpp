//Check constructors, for me no sense default arguments 
#include "Piece.h"
#include "Board.h"

class ChessGame {
private:
    Board board;
    //Chess has 32 pieces.
    Piece pieces[32];
    std::string chess_pieces[6] = {
        "king", "queen", "bishiop", 
        "knight", "rook", "pawn"
        };
    int transform_pixeles_squares(int x)
    {
        // x/8 because chess board in 8x8. 
        int square_size = static_cast<int>(400*x/8) - 8;
        return square_size;
    }
    void place_pieces_start(sf::RenderWindow& window)
    {
        board.draw_board(window);

        int accumulator = 0;
        for (int i = 0; i < 8; i++)
        {
            int y_cordinate = transform_pixeles_squares(1);
            int x_cordinate = transform_pixeles_squares(i);
            pieces[i] = Piece(x_cordinate, y_cordinate, "pawn","black","images");
            pieces[i].draw_piece(window);
        }
    }
    
public:
    ChessGame()
    {}
    
    void start_game(sf::RenderWindow& window)
    {
        place_pieces_start(window);
    }    
};

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chessboard");
    ChessGame chess;
    chess.start_game(window);
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
