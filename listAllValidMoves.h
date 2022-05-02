#ifndef LISTALLVALIDMOVES_H
#define LISTALLVALIDMOVES_H

#include <vector>

using namespace std;

void makeMove(vector < vector<int> > &board, int row, int col, int player);

void botMove(vector < vector<int> > &board, int bot_position[] ,vector < vector<int> > validMovesArr, int player);

vector < vector<int> > findAllPossibleMoves(vector < vector<int> > board, int player);

bool noPossibleMoves(vector < vector<int> > validMovesArr);

#endif