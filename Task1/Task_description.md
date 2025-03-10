Introduction

Reversi, also known as Othello, is played on a board with 64 squares arranged in rows numbered 1 to 8 and columns labeled from a to h. Squares are named by first indicating the column (letter) and then the row (number).

In Reversi, two players compete using two-sided pieces—one side black and the other white. Each square may contain at most one piece. If a piece is currently showing its black side upward, it is referred to as a black piece; if it is showing its white side, it is called a white piece.

A game of Reversi begins with white pieces on squares d4 and e5 and black pieces on squares d5 and e4. All other squares are empty.

Two players participate in the game, known as Black and White, according to the color of the pieces they use. The Black player makes the first move.

Players, taking turns, make a move by placing one piece of their own color on the board. If, on any line (i.e., row, column, or diagonal), all the pieces between the newly placed piece and another piece of the same color belong to the opponent, those pieces flip to show the moving player's color. Placing a single piece on the board may cause several lines of pieces to be flipped simultaneously.

A move is legal only if it results in at least one opponent piece being flipped. If, at any moment, a player cannot make a legal move, they forfeit their turn and do not place a piece on the board.

Although not consistent with standard Reversi rules, in this task we allow a player to forgo a move even if a legal move is available.

Another rule, which is also not followed in our version, states that the game automatically ends when neither player can make a legal move. The winner is then the player who has more pieces of their own color on the board.

Task

Write a program that allows two players to play Reversi. In a loop, the program should:
• Display a prompt indicating which player's turn it is, along with the legal moves available to them.
• Read the current player's command.
• If the command indicates to stop the game, then terminate the program.
• If the command indicates to forgo the move, then return to the beginning of the loop.
• If the command indicates to execute a move, then perform that move and return to the beginning of the loop.
The program should not terminate before receiving the command to stop the game, even if it detects that neither player can make a legal move. It is also not considered an error if the user decides to forgo a move or requests to stop the game even when a legal move is available.
