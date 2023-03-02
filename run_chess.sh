g++ -c main.cpp
g++ -c Piece.cpp
g++ -c Board.cpp
g++ -o main_app main.o Piece.o Board.o -lsfml-graphics -lsfml-window -lsfml-system
./main_app   
