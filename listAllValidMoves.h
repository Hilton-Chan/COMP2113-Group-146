#ifndef LISTALLVALIDMOVES_H
#define LISTALLVALIDMOVES_H

#include <vector>

using namespace std;

vector < vector<int> > findAllPossibleMoves(vector < vector<int> > board, int player);
void makeMove(vector < vector<int> > board, int position[], int player);
void botMove(vector < vector<int> > board, int bot_position[], vector < vector<int> > validMovesArr, int player);
bool noPossibleMoves(vector < vector<int> > validMovesArr);
#endif