# comp2113-group146

Team Members: Chan Hilton Tsz Chau (3035740831), Lee Tin Long Donald (3035664714)

Game: Othello

## Description & Rules:
  - The player starts as black, and plays against a bot that plays as white

  - Black always makes the first move. Each turn, the player places one piece of their colour on the board, after which the bot then responds with its own move

  - The initial board state begins with 2 black pieces on D5 and E5, and 2 white pieces on E4 and D5

  - Each piece played must be laid adjacent to an opponent's piece so that the opponent's piece or a row of opponent's pieces is flanked by the new piece and another piece of the player's colour. All of the opponent's pieces between these two pieces are 'captured' and turned over to match the player's colour

  - It can happen that a piece is played so that pieces or rows of pieces in more than one direction are trapped between the new piece played and other pieces of the same colour. In this case, all the pieces in all viable directions are turned over

  - If the player or bot does not have a legal move on a given turn, they cannot do anything and so their turn is skipped
  
  - The game is over when neither player nor bot has a legal move (i.e. a move that captures at least one opposing piece) or when the board is full
  

## List of Features:

Generation of random game sets or events

  - Playing against a simple bot which responds to player moves by picking a random move out of its possible playable moves
  
Data structures for storing game status

  - The board is stored as a nested vector
  
Dynamic memory management

  - When a piece is placed onto a valid position it is dynamically inserted into the board vector, and the contents of the board vector are also dynamically updated to account for the flipping of pieces

File input/output (e.g., for loading/saving game status)

  - Saving the board state into a gamefile.txt, and allowing the player to load their gamefile in the game menu or during the game
  
Program codes in multiple files

  - Separating code files for fundamental Othello gameplay, graphics and bot programming
  - Implementing hotkeys by calling functions in other code files. Namely: "s" for saving gamefile, "l" for loading gamefile, "h" for displaying/hiding hints and "p" for viewing a log of previous player and bot moves
