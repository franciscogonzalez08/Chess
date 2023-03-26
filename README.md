# Chess in C++
This is a chess game written in C++ as my final proyect for object oriented programming.
## Classes.

- Board : Displays the board.
- Piece : Control how pieces are displayed.
- Validator : Verify and show valid moves for each piece.
- ChessGame : Manages the game and check for events.

Each class has a different role, a brief description of each one.
 -> Board : This is a simple class, it only needs a window to display a classic chess board, it do not control how pieces moves.
 -> Piece : This class display the pieces and control how they look in the window, it also checks for dimension of the board to scale pieces, contains relevant info like coords, color, alive status and name.
 -> Validator : This class is really important, when a piece is selected this class computes possible moves for that piece and show the possible moves on the board.
 -> Chess game: This class use all above classes and implement them in different methods, also manage events like a click on a piece or when a piece eat another.
 
