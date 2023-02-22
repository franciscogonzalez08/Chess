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

    Piece *selected_piece = nullptr;

    int transform_pixeles_squares(int x)
    {
        /*
        This function transforms the position of the squares
        in pixeles.
        Arguments:
            x: position of the square
        */
        int square_size = static_cast<int>(board.get_height()*x/8 - board.get_height()/50);
        return square_size;
    }

    bool piece_is_there(int x, int y, int p_x, int p_y)
    {
        /*
        This function checks if there is a piece in the square
        where the mouse is pointing.
        Arguments:
            x: x position of the mouse
            y: y position of the mouse
            p_x: x position of the piece
            p_y: y position of the piece
        */
        if (x >= p_x && x <= p_x + 50 && y >= p_y && y <= p_y + 50)
        {
            return true;
        }
        return false;
        
    }

    void place_pawns(sf::RenderWindow& window)
    {
        /*
        This function places the pawns in the board.
        Arguments:
            window: window where the pieces will be drawn
        */
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
        /*
        This function places the rooks in the board.
        Arguments:
            window: window where the pieces will be drawn
        */
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
        /*
        This function places the kings in the board.
        Arguments:
            window: window where the pieces will be drawn
        */
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
        /*
        This function places the queens in the board.
        Arguments:
            window: window where the pieces will be drawn
        */
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
        /*
        This function places the knights in the board.
        Arguments:
            window: window where the pieces will be drawn
        */
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
        /*
        This function places the bishops in the board.
        Arguments:
            window: window where the pieces will be drawn
        */
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
        /*
        This function places the pieces in the board.
        Arguments:
            window: window where the pieces will be drawn
        */
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

    void run() {
        /*
        This function runs the game.
        */
       
        // create a window and display it
        sf::RenderWindow window(sf::VideoMode(600, 600), "Chess Game");
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
        
        // place the pieces on the board
        place_pawns(window);
        place_rooks(window);
        place_kings(window);
        place_queens(window);
        place_knights(window);
        place_bishops(window);

        // main event loop
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // handle events
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::MouseButtonPressed:
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // check if the click is inside any piece
                            for (int i = 0; i < 32; i++) {
                                if (piece_is_there(event.mouseButton.x, event.mouseButton.y, pieces[i].get_x_position(), pieces[i].get_y_position())) {
                                    selected_piece = &pieces[i];
                                    break;
                                }
                            }
                        }
                        break;
                    case sf::Event::MouseButtonReleased:
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // drop the selected piece if it's over a valid square
                            int x = event.mouseButton.x;
                            int y = event.mouseButton.y;
                            if (selected_piece != nullptr) {
                                selected_piece->set_position(x, y);
                                selected_piece = nullptr;
                            }
                        }
                        break;
                    case sf::Event::MouseMoved:
                        // move the selected piece with the mouse
                        if (selected_piece != nullptr) {
                            selected_piece->follow_mouse(window);
                        }
                        break;
                }
            }
            
            // clear the window
            window.clear(sf::Color::White);
            
            // draw the board and the pieces
            board.draw_board(window);
            for (int i = 0; i < 32; i++) {
                pieces[i].draw_piece(window);
            }
            
            // display the window
            window.display();
        }
    }
};










int main() {
    
    ChessGame game;
    game.run();

    return 0;
}
