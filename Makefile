isValidMove.o: isValidMove.cpp isValidMove.h
	g++ -c $<
othelloBoard.o: othelloBoard.cpp othelloBoard.h
	g++ -c $<
interface.o: interface.cpp interface.h othelloBoard.h
	g++ -c $<
listAllValidMoves.o: listAllValidMoves.cpp listAllValidMoves.h isValidMove.h
	g++ -c $<
game.o: game.cpp listAllValidMoves.o interface.o othelloBoard.o isValidMove.o
	g++ -c $^
game: game.o listAllValidMoves.o interface.o othelloBoard.o isValidMove.o
	g++ $^ -o game