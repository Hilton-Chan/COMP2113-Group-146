#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRST";


bool boardEmpty(vector < vector<int> > board);
vector < vector<int> > boardInitalize(int size);
void printBoard(vector < vector<int> > board);
void showPossibleMoves(vector < vector<int> > board, vector < vector<int> > validMovesArr);
vector < vector<int> > findAllPossibleMoves(vector < vector<int> > board, int player);
vector < vector<int> > isValidMove(vector < vector<int> > board, int position[], int player);
void makeMove(vector < vector<int> > board, int position[], int player);
int* botMove(vector < vector<int> > board, vector < vector<int> > validMovesArr, int player);
bool noPossibleMoves(vector < vector<int> > validMovesArr);

bool isNumber(string s) {
    for (int i=0; i<s.length(); i++) {
        if (isdigit(s[i]) == 0) {
            return 0;
        }
    }
    return 1;
}


void printPage(vector < vector<int> > board) {
    // add UI
    printBoard(board);
}

void printPageWithHints(vector < vector<int> > board, int player) {
    // add UI, specify player if vs player
    vector < vector<int> > validMovesArr = findAllPossibleMoves(board, player);
    showPossibleMoves(board, validMovesArr);
}

bool validMoveInput(string input) {
    if (input.length() != 2) {
        return 0;
    }
    if (isNumber(input.substr(1)) && alphabet.find(input[0]) != -1) {
        if (stoi(input.substr(1)) <= 19) {
            return 1;
        }
    }
    return 0;
}

int main() {
    vector < vector<int> > board;
    string sizeInput;
    int size = -1;

    cout << "Pick your board size: ";
    cin >> size;
    while (size == -1) {
        if (isNumber(sizeInput) && stoi(sizeInput) % 2 == 0 && stoi(sizeInput) <= 20) {
            size = stoi(sizeInput);
        } else {
            cout << "Please pick a valid even number again: ";
            cin >> sizeInput;
        }
    }

    string player_choice;
    int player_turn;
    // Pick Vs. Bot or Player
    // Add invalid choice
    cout << "Bot or Player";
    cin >> player_choice;
    if (player_choice == "1") {
        player_turn = 1;
    } else {
        player_turn = -1;
    }

    boardInitalize(size);
    // add Scoreboard over here and additional UI related sttuff (e.g. save file & undo indicating key)
    printBoard(board);
    
    bool show_hint_flag = 0;
    bool bot_next_flag = 0;
    // print who's turn it is right now over here

    while (boardEmpty(board)) {
        string userInput;
        cin >> userInput;
        if (userInput == "") { // decide which key
            // save file over here
        } else if (userInput == "") { // decide which key
            // undo move
        } else if (userInput == "" && show_hint_flag != 0) { // show move key
            printPageWithHints(board, player_turn);
            show_hint_flag = 1;
        } else if (userInput == "" && show_hint_flag != 0) {
            printBoard(board);
            show_hint_flag = 0;
        } else if (validMoveInput(userInput)) {
            int row = alphabet.find(userInput[0]);
            int col = stoi(userInput.substr(1));
            int position[2] = {row, col};
            vector<vector<int> > flip_tiles = isValidMove(board, position, player_turn);
            if (flip_tiles.empty()) {
                cout << "Invalid Move" << endl;
            } else {
                if (player_turn == 1) {
                    makeMove(board, position, player_turn);
                    player_turn = 2;
                } else if (player_turn == 2) {
                    makeMove(board, position, player_turn);
                    player_turn = 1;
                } else {
                    makeMove(board, position, 1);
                    bot_next_flag = 1;
                }
                flip_tiles.clear();
            }
        } 

        if (bot_next_flag && player_turn == -1) {
            vector < vector<int> > botMoves = findAllPossibleMoves(board, 2);
            if (!noPossibleMoves(botMoves)) {
                int* bot_position = botMove(board, botMoves, 2);
            } else {
                cout << "No Possible Moves can be made by Bot" << endl;
                // add more text
            }
            bot_next_flag = 0;
            botMoves.clear();
        }
        if (player_turn == 1 || player_turn == 2) {
            vector < vector<int> > nextMoves = findAllPossibleMoves(board, player_turn);
            if (noPossibleMoves(nextMoves)) {
                cout << "No Possible Moves can be made by Player " << player_turn << endl;
                if (player_turn == 1) {
                    player_turn = 2;
                } else {
                    player_turn = 1;
                }
            }
        }
        
        cin >> userInput; 
    }

    // Game Ends here
    // Print out scoreboard and asks if player wants to replay again
}
