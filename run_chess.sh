g++ -c main.cpp
g++ -c Piece.cpp
g++ -c Board.cpp
g++ -c Validator.cpp
g++ -o main_app main.o Piece.o Board.o Validator.o -lsfml-graphics -lsfml-window -lsfml-system
./main_app   
