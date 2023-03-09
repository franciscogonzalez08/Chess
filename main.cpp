//Check constructors, for me no sense default arguments 
#include <cassert>
#include "Piece.h"
#include "Board.h"
#include<iostream>

struct Config
{
    /*
    Config struct
    This struct contains the configuration of the game.
    Members:
        b_width: width of the board
        b_height: height of the board
        w_width: width of the window
        w_height: height of the window
        w_title: title of the window
        fps: frames per second
        Vsync: vertical sync
    */
    int b_width = 400;
    int b_height = 400;
    int w_width = 400;
    int w_height = 400;
    std::string w_title = "Chess game";
    int fps = 60;
    bool Vsync = true;
};

class ChessGame {
private:
    Board board;
    //Chess has 32 pieces
    int number_of_pieces = 32;
    Piece* pieces = new Piece[number_of_pieces];
    std::string chess_pieces[6] = {
        "king", "queen", "bishiop", 
        "knight", "rook", "pawn"
        };
    Piece *selected_piece = nullptr;
    Config game_config;    

    int give_pixel_position_of_square(int x)
    {
        /*
        This function transforms the position of the squares
        in pixeles.
        Arguments:
            x: position of the square
        */
        int square_size = static_cast<int>(board.get_height()*x/8);
        return square_size;
    }

    int from_pixel_to_square(int x)
    {
        //Given pixel in x or y direction return the square where that pixel is.
        int square_number = static_cast<int>(x * 1/50);
        return square_number;
    }

    int center_in_square(int pixel)
    {
        /*
        This function centers the pieces in the squares.
        Arguments:
            pixel: position of the piece
        */
        int square_size = static_cast<int>(board.get_height()/8);
        int square_number = static_cast<int>(pixel/square_size);
        int center = static_cast<int>(square_number*square_size);
        return center;
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
            std::string name {"pawn " + std::to_string(i + 1)};
            int y_cordinate = center_in_square(give_pixel_position_of_square(1));
            int x_cordinate = center_in_square(give_pixel_position_of_square(i));
            pieces[i] = Piece(x_cordinate, y_cordinate, name, "black","images");
            pieces[i].draw_piece(window);
        }

        for (int i = 8; i < 16; i++)
        {
            std::string name {"pawn " + std::to_string(i - 7)};
            int y_cordinate = center_in_square(give_pixel_position_of_square(6));
            int x_cordinate = center_in_square(give_pixel_position_of_square(i - 8));
            pieces[i] = Piece(x_cordinate, y_cordinate, name,"white","images");
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
        int x_cordinate = center_in_square(give_pixel_position_of_square(0));
        int y_cordinate = center_in_square(give_pixel_position_of_square(7));
        pieces[16] = Piece(x_cordinate, y_cordinate, "rook 1","white","images");
        x_cordinate = give_pixel_position_of_square(7);
        pieces[17] = Piece(x_cordinate, y_cordinate, "rook 2","white","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(0));
        y_cordinate = center_in_square(give_pixel_position_of_square(0));
        pieces[18] = Piece(x_cordinate, y_cordinate, "rook 3","black","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(7));
        pieces[19] = Piece(x_cordinate, y_cordinate, "rook 4","black","images");
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
        int x_cordinate = center_in_square(give_pixel_position_of_square(4));
        int y_cordinate = center_in_square(give_pixel_position_of_square(0));
        pieces[20] = Piece(x_cordinate, y_cordinate, "king 2","black","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(4));
        y_cordinate = center_in_square(give_pixel_position_of_square(7));
        pieces[21] = Piece(x_cordinate, y_cordinate, "king 1","white","images");
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
        int x_cordinate = center_in_square(give_pixel_position_of_square(3));
        int y_cordinate = center_in_square(give_pixel_position_of_square(0));
        pieces[22] = Piece(x_cordinate, y_cordinate, "queen 2","black","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(3));
        y_cordinate = center_in_square(give_pixel_position_of_square(7));
        pieces[23] = Piece(x_cordinate, y_cordinate, "queen 1","white","images");
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
        int x_cordinate = center_in_square(give_pixel_position_of_square(1));
        int y_cordinate = center_in_square(give_pixel_position_of_square(0));
        pieces[24] = Piece(x_cordinate, y_cordinate, "knight 3","black","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(6));
        pieces[25] = Piece(x_cordinate, y_cordinate, "knight 4","black","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(1));
        y_cordinate = center_in_square(give_pixel_position_of_square(7));
        pieces[26] = Piece(x_cordinate, y_cordinate, "knight 1","white","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(6));
        pieces[27] = Piece(x_cordinate, y_cordinate, "knight 2","white","images");
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
        int x_cordinate = center_in_square(give_pixel_position_of_square(2));
        int y_cordinate = center_in_square(give_pixel_position_of_square(0));
        pieces[28] = Piece(x_cordinate, y_cordinate, "bishop 3","black","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(5));
        pieces[29] = Piece(x_cordinate, y_cordinate, "bishop 4","black","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(2));
        y_cordinate = center_in_square(give_pixel_position_of_square(7));
        pieces[30] = Piece(x_cordinate, y_cordinate, "bishop 1","white","images");
        x_cordinate = center_in_square(give_pixel_position_of_square(5));
        pieces[31] = Piece(x_cordinate, y_cordinate, "bishop 2","white","images");
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
        place_pawns(window);
        place_rooks(window);
        place_kings(window);
        place_queens(window);
        place_knights(window);
        place_bishops(window);
    }

    void create_window(sf::RenderWindow& window)
    {
        /*
        This function creates the window where the game will be played.
        Arguments:
            window: window where the game will be played
        */
        window.create(sf::VideoMode(game_config.w_width,game_config.w_height),game_config.w_title);
        window.setVerticalSyncEnabled(game_config.Vsync);
        window.setFramerateLimit(game_config.fps);
        board = Board(game_config.b_width, game_config.b_height);
        board.draw_board(window);
    }

    void check_mouse_click_on_piece(sf::Event::MouseButtonEvent mouseButtonEvent)
    {
        /*
        This function checks if the mouse click is on a piece.
        Arguments:
            mouseButtonEvent: event of the mouse button
        */
        if(mouseButtonEvent.button == sf::Mouse::Left)
        {
            for(int i{0}; i < number_of_pieces ; ++i)
            {
                int pxp {pieces[i].get_x_position()};
                int pyp {pieces[i].get_y_position()};
                if(piece_is_there(mouseButtonEvent.x,mouseButtonEvent.y,pxp,pyp))
                {
                    selected_piece = &pieces[i];
                    break;
                }
            }
        }
    }

    void check_mouse_button_released(sf::Event::MouseButtonEvent mouseButtonEvent)
    {
        /*
        This function checks if the mouse button is released.
        Arguments:
            mouseButtonEvent: event of the mouse button
        */
        if (mouseButtonEvent.button == sf::Mouse::Left) {
            int x {mouseButtonEvent.x};
            int y {mouseButtonEvent.y};
            std::cout << "x: " << x << " y: " << y << std::endl;
            std::cout << " centered x: " << center_in_square(x) << " centered y: " << center_in_square(y) << std::endl;
            if (selected_piece != nullptr) 
            {
            //if piece is selected, place it in the square
            selected_piece->set_position(center_in_square(x), center_in_square(y));
            check_if_piece_is_there(x,y);
            selected_piece = nullptr;
            }
        }
                        
    }

    void check_moved_mouse(sf::Event::MouseButtonEvent mouseButtonEvent, sf::RenderWindow& window)
    {
        /*
        This function checks if the mouse is moved.
        Arguments:
            mouseButtonEvent: event of the mouse button
            window: window where the game is played
        */
        if (selected_piece != nullptr) 
        {
        //if piece is selected, follow the mouse
        selected_piece->follow_mouse(window);
        }
    }

    void handle_events(sf::Event& event, sf::RenderWindow& window)
    {
        /*
        This function handles the events of the game.
        Arguments:
            event: event of the game
            window: window where the game is played
        */
        switch (event.type) 
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                check_mouse_click_on_piece(event.mouseButton);                        
                break;
            case sf::Event::MouseButtonReleased:
                check_mouse_button_released(event.mouseButton);
                break;
            case sf::Event::MouseMoved:
                check_moved_mouse(event.mouseButton, window);
                break;
        }          
    }

    void check_if_piece_is_there(int x, int y)
    {
        int square_x = from_pixel_to_square(x);
        int square_y = from_pixel_to_square(y);
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Mouse cords : " << square_x << " " << square_y << std::endl;
        std::cout << "Moved piece : " << selected_piece->get_name() << std::endl;
        std::cout << "New cords : " << selected_piece->get_x_position() << " " << selected_piece->get_y_position() << std::endl;
        std::cout << "New square cords : " << from_pixel_to_square(selected_piece->get_x_position()) << " " << from_pixel_to_square(selected_piece->get_y_position()) << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        for(int i{0}; i < number_of_pieces; ++i)
        {
            //Here we check if the piece is the same as the piece we are moving
            if(&pieces[i]!=selected_piece)
            {
                int piece_square_x = from_pixel_to_square(pieces[i].get_x_position());
                int piece_square_y = from_pixel_to_square(pieces[i].get_y_position());
                //If piece we are moving goes into another piece, then eat.
                if(piece_square_x == square_x && piece_square_y == square_y)
                {
                    pieces[i].set_position(0,0);
                }

            }
        }
    }

public:

    ChessGame()
    {}

    void run() {
        // create a window and display it
        sf::RenderWindow window;
        create_window(window);
        place_pieces_start(window);

        // main event loop
        while (window.isOpen()) {
            sf::Event event;
            
            while (window.pollEvent(event)) 
            {
                handle_events(event, window);
            }
            
            // clear the window
            window.clear(sf::Color::White);
            
            // draw the board and the pieces
            board.draw_board(window);
            for (int i = 0; i < number_of_pieces; i++) {
                pieces[i].draw_piece(window);
            }
            
            // display the window
            window.display();
            //slep for 10 seconds
        }
    }
};










int main() {
    
    ChessGame game;
    game.run();

    return 0;
}
