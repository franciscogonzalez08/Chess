#include "Validator.h"
 //Remove this, just for debugging
#include <iostream>

Validator::Validator(int x, int y): board_dims(x, y) {}

void Validator::draw_square(sf::RenderWindow & window, int x, int y) {
    /*
    This function draws a square on the board.
    Arguments:
        window: window where the square will be drawn
        x: x position of the square
        y: y position of the square
    */
    std::pair < int, int > square_dims = compute_square_width_height();
    int square_widht = square_dims.first;
    int square_height = square_dims.second;
    sf::RectangleShape square(sf::Vector2f(square_widht, square_height));
    square.setFillColor(sf::Color(0, 255, 0, 128));
    square.setPosition(x, y);
    window.draw(square);
}

std::string Validator::transform_name(std::string piece_name) {
    /*
    This function transforms the name of the piece to a more readable name.
    Pieces are named like pawn 2 or pawn 1, this function transforms the name to pawn. 
    Arguments:
        piece_name: name of the piece
    */
    std::string new_name = piece_name.substr(0, piece_name.size() - 2);
    return new_name;
}

std::pair < int, int > Validator::add_position(std::pair < int, int > piece_possition, std::pair < int, int > new_position) {
    /*
    This function adds the new position to the piece position.
    Given the piece position and the new position, this function returns the new position of the piece,
    in relative coordinates, for example if the piece is in the position (0,0) and the new position is (1,1)
    the function will coords to (1,1), but if piece is in (5,5), then new coords will be (6,6).
    Arguments:
        piece_possition: position of the piece
        new_position: new position of the piece
    Returns:
        a pair of ints with the new position of the piece
    */
    std::pair < int, int > square_dims = compute_square_width_height();
    int new_x_position, new_y_position;
    new_x_position = piece_possition.first + new_position.first * square_dims.first;
    new_y_position = piece_possition.second + new_position.second * square_dims.second;
    return std::make_pair(new_x_position, new_y_position);
}

std::pair < int, int > Validator::compute_square_width_height() {
    /*
    This function computes the width and height of the square.
    The width and height of the square are computed based on the width and height of the board.
    Arguments:
        None
    Returns:
        a pair of ints with the width and height of the square
    */
    return std::make_pair(static_cast < int > (board_dims.first / 8), static_cast < int > (board_dims.second / 8));
}
//Maybe pass the whole object ?? I am using all attributes.
std::vector < std::pair < int, int >> Validator::show_possible_moves(sf::RenderWindow & window, std::string piece_name, std::string piece_color, int piece_x_position, int piece_y_position,
    std::vector < std::tuple < int, int, std::string >> pieces_info) {
    /*
    This function shows the possible moves of the piece.
    Arguments:
        window: window where the possible moves will be drawn
        piece_name: name of the piece
        piece_color: color of the piece
        piece_x_position: x position of the piece
        piece_y_position: y position of the piece
        pieces: vector with the pieces of the board
    */

    std::vector < std::pair < int, int >> possible_moves = compute_possible_moves(piece_name, piece_x_position, piece_y_position, pieces_info, piece_color);
    draw_possible_moves(window, possible_moves);
    return possible_moves;
}

std::vector < std::pair < int, int >> Validator::compute_possible_moves(std::string full_piece_name,
    int x, int y, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function computes the possible moves of the piece.
    Given the name of the piece, the x and y position of the piece, this function returns a vector with the possible moves of the piece.
    Arguments:
        full_piece_name: name of the piece
        x: x position of the piece
        y: y position of the piece
    Returns:
        a vector with the possible moves of the piece
    */
    std::vector < std::pair < int, int >> possible_moves;
    std::string piece_name = transform_name(full_piece_name);

    if (piece_name == "pawn") {
        possible_moves = assing_pawn_moves(x, y, pieces_info, piece_color);
        return possible_moves;
    }

    if (piece_name == "rook") {
        possible_moves = assing_rook_moves(x, y, pieces_info, piece_color);
        return possible_moves;
    }
    if (piece_name == "knight") {
        possible_moves = assing_knight_moves(x, y, pieces_info, piece_color);
        return possible_moves;
    }
    if (piece_name == "bishop") {
        possible_moves = assing_bishop_moves(x, y, pieces_info, piece_color);
        return possible_moves;
    }
    if (piece_name == "queen") {
        possible_moves = assing_queen_moves(x, y, pieces_info, piece_color);
        return possible_moves;
    }
    if (piece_name == "king") {
        possible_moves = assing_king_moves(x, y, pieces_info, piece_color);
        return possible_moves;
    }
    //Here is a warning because this may return nothing, not sure if this is a problem
}

std::vector < std::pair < int, int >> Validator::assing_pawn_moves(int x_postion, int y_position, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function computes the possible moves of the pawn.
    Arguments:
        x_postion: x position of the pawn
        y_position: y position of the pawn
        pieces_info: vector with the pieces of the board
    Returns:
        a vector with the possible moves of the pawn
    */
    std::vector < std::pair < int, int >> possible_moves;
    possible_moves = stack_moves(x_postion, y_position, 1, 1, pieces_info, possible_moves, piece_color);
    possible_moves = stack_moves(x_postion, y_position, 5, 1, pieces_info, possible_moves, piece_color);
    return possible_moves;
}

std::vector < std::pair < int, int >> Validator::assing_queen_moves(int x_postion, int y_position, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function computes the possible moves of the queen.
    Arguments:
        x_postion: x position of the queen
        y_position: y position of the queen
        pieces_info: vector with the pieces of the board
    Returns:
        a vector with the possible moves of the queen
    */
    std::vector < std::pair < int, int >> possible_moves;
    for (int i {
            1
        }; i <= 8; ++i) {
        possible_moves = stack_moves(x_postion, y_position, i, 8, pieces_info, possible_moves, piece_color);
    }
    return possible_moves;
}

std::vector < std::pair < int, int >> Validator::assing_king_moves(int x_postion, int y_position, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function computes the possible moves of the king.
    Arguments:
        x_postion: x position of the king
        y_position: y position of the king
        pieces_info: vector with the pieces of the board
    Returns:
        a vector with the possible moves of the king
    */
    std::vector < std::pair < int, int >> possible_moves;
    for (int i {
            1
        }; i <= 8; ++i) {
        possible_moves = stack_moves(x_postion, y_position, i, 1, pieces_info, possible_moves, piece_color);
    }
    return possible_moves;
}

std::vector < std::pair < int, int >> Validator::assing_bishop_moves(int x_postion, int y_position, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function computes the possible moves of the bishop.
    Arguments:
        x_postion: x position of the bishop
        y_position: y position of the bishop
        pieces_info: vector with the pieces of the board
    Returns:
        a vector with the possible moves of the bishop
    */
    std::vector < std::pair < int, int >> possible_moves;
    possible_moves = stack_moves(x_postion, y_position, 2, 8, pieces_info, possible_moves, piece_color);
    possible_moves = stack_moves(x_postion, y_position, 4, 8, pieces_info, possible_moves, piece_color);
    possible_moves = stack_moves(x_postion, y_position, 6, 8, pieces_info, possible_moves, piece_color);
    possible_moves = stack_moves(x_postion, y_position, 8, 8, pieces_info, possible_moves, piece_color);
    return possible_moves;
}

std::vector < std::pair < int, int >> Validator::assing_knight_moves(int x_postion, int y_position, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function computes the possible moves of the knight.
    Arguments:
        x_postion: x position of the knight
        y_position: y position of the knight
        pieces_info: vector with the pieces of the board
    Returns:
        a vector with the possible moves of the knight
    */
    std::vector < std::pair < int, int >> possible_moves;
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(1, 2)));
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(1, -2)));
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(-1, 2)));
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(-1, -2)));
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(2, 1)));
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(2, -1)));
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(-2, 1)));
    possible_moves.push_back(add_position(std::make_pair(x_postion, y_position), std::make_pair(-2, -1)));
    return possible_moves;
}

std::vector < std::pair < int, int >> Validator::stack_moves(int x_postion,
    int y_position,
    int direction,
    int number_of_moves,
    std::vector < std::tuple < int, int, std::string >> pieces_info,
    std::vector < std::pair < int, int >> original_possible_moves,
    std::string piece_color) {
    /*
    This function stack moves in a given direction.
    This diagram shows how the directions are given.
                      6   5  4                         
                      7   P  3
                      8   1  2
    So, if the direction is 1, and number of moves 2 then this function returns
    a vector with two moves in direction 1.
    Arguments:
        x_postion: x position of the piece
        y_position: y position of the piece
        direction: direction of the moves
        number_of_moves: number of moves in the given direction
    Returns:
        a vector with the possible moves of the piece
    */
    std::vector < std::pair < int, int >> possible_moves;
    std::pair < int, int > possible_move;
    int status;
    if (direction == 1) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(0, i));
            status = check_colision(possible_move, pieces_info, piece_color);
            //-- This part of the code repeat a lot, maybe it can be a function, but I am not sure how to do it --
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
        }
        //------------------------------------------------------------------------------------------------------
    }
    if (direction == 2) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(i, i));
            status = check_colision(possible_move, pieces_info, piece_color);
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
            break;
        }
    }
    if (direction == 3) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(i, 0));
            status = check_colision(possible_move, pieces_info, piece_color);
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
        }
    }
    if (direction == 4) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(i, -i));
            status = check_colision(possible_move, pieces_info, piece_color);
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
        }
    }
    if (direction == 5) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(0, -i));
            status = check_colision(possible_move, pieces_info, piece_color);
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
        }
    }
    if (direction == 6) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(-i, -i));
            status = check_colision(possible_move, pieces_info, piece_color);
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
        }
    }
    if (direction == 7) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(-i, 0));
            status = check_colision(possible_move, pieces_info, piece_color);
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
        }
    }
    if (direction == 8) {
        for (int i {
                0
            }; i <= number_of_moves; ++i) {
            possible_move = add_position(std::make_pair(x_postion, y_position), std::make_pair(-i, i));
            status = check_colision(possible_move, pieces_info, piece_color);
            if (status == 1) {
                break;
            } else if (status == 2) {
                possible_moves.push_back(possible_move);
                break;
            } else if (status == 0) {
                possible_moves.push_back(possible_move);
            }
        }
    }
    possible_moves.insert(possible_moves.end(), original_possible_moves.begin(), original_possible_moves.end());
    return possible_moves;
}

int Validator::check_colision(std::pair < int, int > new_move, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function checks if the new move of the piece is on top of another piece.
    Arguments:
        new_move: new move of the piece
        pieces_info: vector with the pieces of the board
        piece_color: color of the piece
    Returns:
        1 if the piece is on top of another piece of the same color
        2 if the piece is on top of another piece of the opposite color
        0 if there is no colision
    */
    for (std::tuple < int, int, std::string > piece_info: pieces_info) {
        if (std::get < 0 > (piece_info) == new_move.first && std::get < 1 > (piece_info) == new_move.second) {
            if (std::get < 2 > (piece_info) == piece_color) {
                return 1;
            } else {
                return 2;
            }
        }
    }
    return 0;
}

std::vector < std::pair < int, int >> Validator::assing_rook_moves(int x_postion, int y_position, std::vector < std::tuple < int, int, std::string >> pieces_info, std::string piece_color) {
    /*
    This function computes the possible moves of the rook.
    Arguments:
        x_postion: x position of the rook
        y_position: y position of the rook
        pieces_info: vector with the pieces of the board
    Returns:
        a vector with the possible moves of the rook
    */
    std::vector < std::pair < int, int >> possible_moves;
    std::pair < int, int > possible_move;
    //This looks like can be done in another method
    possible_moves = stack_moves(x_postion, y_position, 1, 8, pieces_info, possible_moves, piece_color);
    possible_moves = stack_moves(x_postion, y_position, 3, 8, pieces_info, possible_moves, piece_color);
    possible_moves = stack_moves(x_postion, y_position, 5, 8, pieces_info, possible_moves, piece_color);
    possible_moves = stack_moves(x_postion, y_position, 7, 8, pieces_info, possible_moves, piece_color);
    return possible_moves;
}

void Validator::draw_possible_moves(sf::RenderWindow & window, std::vector < std::pair < int, int >> possible_moves) {
    /*
    This function draws the possible moves of the piece on the board.
    Arguments:
        window: window where the possible moves will be drawn
        possible_moves: vector with the possible moves of the piece
    */
    for (std::pair < int, int > moves: possible_moves) {
        draw_square(window, moves.first, moves.second);
    }
}