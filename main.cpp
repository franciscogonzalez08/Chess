//Check constructors, for me no sense default arguments 
#include <cassert>
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
        // x/8 because chess board in 8x8, substract to center the piece a little. 
        int square_size = static_cast<int>(board.get_height()*x/8 - board.get_height()/50);
        return square_size;
    }

    void place_pawns(sf::RenderWindow& window)
    {
        for (int i = 0; i < 8; i++)
        {
            int y_cordinate = transform_pixeles_squares(1);
            int x_cordinate = transform_pixeles_squares(i);
            pieces[i] = Piece(x_cordinate, y_cordinate, "pawn","black","images");
            pieces[i].draw_piece(window);
        }

        for (int i = 8; i < 16; i++)
        {
            int y_cordinate = transform_pixeles_squares(6);
            int x_cordinate = transform_pixeles_squares(i - 8);
            pieces[i] = Piece(x_cordinate, y_cordinate, "pawn","white","images");
            pieces[i].draw_piece(window);
        }
    }


    void place_rooks(sf::RenderWindow& window)
    {
        int x_cordinate = transform_pixeles_squares(0);
        int y_cordinate = transform_pixeles_squares(7);
        pieces[16] = Piece(x_cordinate, y_cordinate, "rook","white","images");
        x_cordinate = transform_pixeles_squares(7);
        pieces[17] = Piece(x_cordinate, y_cordinate, "rook","white","images");
        x_cordinate = transform_pixeles_squares(0);
        y_cordinate = transform_pixeles_squares(0);
        pieces[18] = Piece(x_cordinate, y_cordinate, "rook","black","images");
        x_cordinate = transform_pixeles_squares(7);
        pieces[19] = Piece(x_cordinate, y_cordinate, "rook","black","images");
        pieces[18].draw_piece(window);
        pieces[19].draw_piece(window);
        pieces[16].draw_piece(window);
        pieces[17].draw_piece(window);

    }

    void place_kings(sf::RenderWindow& window)
    {
        int x_cordinate = transform_pixeles_squares(4);
        int y_cordinate = transform_pixeles_squares(0);
        pieces[20] = Piece(x_cordinate, y_cordinate, "king","black","images");
        x_cordinate = transform_pixeles_squares(4);
        y_cordinate = transform_pixeles_squares(7);
        pieces[21] = Piece(x_cordinate, y_cordinate, "king","white","images");
        pieces[20].draw_piece(window);
        pieces[21].draw_piece(window);
    }

    void place_queens(sf::RenderWindow& window)
    {
        int x_cordinate = transform_pixeles_squares(3);
        int y_cordinate = transform_pixeles_squares(0);
        pieces[22] = Piece(x_cordinate, y_cordinate, "queen","black","images");
        x_cordinate = transform_pixeles_squares(3);
        y_cordinate = transform_pixeles_squares(7);
        pieces[23] = Piece(x_cordinate, y_cordinate, "queen","white","images");
        pieces[22].draw_piece(window);
        pieces[23].draw_piece(window);
    }

    void place_knights(sf::RenderWindow& window)
    {
        int x_cordinate = transform_pixeles_squares(1);
        int y_cordinate = transform_pixeles_squares(0);
        pieces[24] = Piece(x_cordinate, y_cordinate, "knight","black","images");
        x_cordinate = transform_pixeles_squares(6);
        pieces[25] = Piece(x_cordinate, y_cordinate, "knight","black","images");
        x_cordinate = transform_pixeles_squares(1);
        y_cordinate = transform_pixeles_squares(7);
        pieces[26] = Piece(x_cordinate, y_cordinate, "knight","white","images");
        x_cordinate = transform_pixeles_squares(6);
        pieces[27] = Piece(x_cordinate, y_cordinate, "knight","white","images");
        pieces[24].draw_piece(window);
        pieces[25].draw_piece(window);
        pieces[26].draw_piece(window);
        pieces[27].draw_piece(window);
    }
    
    void place_bishops(sf::RenderWindow& window)
    {
        int x_cordinate = transform_pixeles_squares(2);
        int y_cordinate = transform_pixeles_squares(0);
        pieces[28] = Piece(x_cordinate, y_cordinate, "bishop","black","images");
        x_cordinate = transform_pixeles_squares(5);
        pieces[29] = Piece(x_cordinate, y_cordinate, "bishop","black","images");
        x_cordinate = transform_pixeles_squares(2);
        y_cordinate = transform_pixeles_squares(7);
        pieces[30] = Piece(x_cordinate, y_cordinate, "bishop","white","images");
        x_cordinate = transform_pixeles_squares(5);
        pieces[31] = Piece(x_cordinate, y_cordinate, "bishop","white","images");
        pieces[28].draw_piece(window);
        pieces[29].draw_piece(window);
        pieces[30].draw_piece(window);
        pieces[31].draw_piece(window);
    }

    void place_pieces_start(sf::RenderWindow& window)
    {
        board.draw_board(window);
        place_pawns(window);
        place_rooks(window);
        place_kings(window);
        place_queens(window);
        place_knights(window);
        place_bishops(window);
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
