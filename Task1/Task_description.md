# Introduction

Reversi, also known as Othello, is played on a board with 64 fields arranged in rows numbered from 1 to 8 and columns labeled from a to h. A field is identified by specifying first the column (from a to h) followed by the row number.

In Reversi, two-sided black and white pieces are used. Each field can hold at most one piece. If a piece is currently facing up with the black side, it is called a black piece; if it is facing up with the white side, it is called a white piece.

A game of Reversi begins with white pieces on fields d4 and e5, and black pieces on fields d5 and e4. All other fields are empty.

Two players participate in the game, referred to as Black and White, according to the color of the pieces they play with. The game starts with the Black player.

Players take turns making a move by placing a piece of their color on the board. A move is considered legal if, in at least one line (row, column, or diagonal) between the newly placed piece and another piece of the same color, all intermediate pieces are of the opposing color; in this case, all such pieces are flipped (i.e., their colors are reversed). A single move may result in flipping pieces along several lines simultaneously.

A move is legal only if it causes at least one piece on the board to change color. If at any moment a player is unable to make a legal move, they must pass their turn and place no piece on the board.

Although not in accordance with the official rules of Reversi, in this assignment the player is allowed to pass even when a legal move exists.

Another rule, which also does not apply here, states that the game automatically ends when neither player can make a legal move. At that point, the winner is the player who has more pieces of their color on the board.

---

# Task

Write a program that enables two players to play Reversi.

The program, in a loop:

- Displays a prompt indicating which player's turn it is and listing the legal moves that the player can make.
- Reads a command from the current player.
- If the player enters the game-termination command, the program ends.
- If the player enters the command to pass their turn, the program goes back to the beginning of the loop.
- If the player enters the command to perform a move, the program executes that move and then returns to the beginning of the loop.

The program should not terminate before receiving the game-termination command, even if it determines that neither player can make a legal move. Similarly, it does not consider it an error if the user passes or elects to terminate the game even though a legal move is available.

---

# Data Format

The program receives commands from the players as input. Each command occupies one line. All commands have the correct format. Commands for making a move indicate a legal move. After the game-termination command, any additional text is ignored by the program.

- The game-termination command is a line with the text:  
  `=`

- The command to pass a turn is a line with the text:  
  `-`

- The command to make a move is a line containing a field name.

---

# Output Format

The program outputs a sequence of prompts, one per line.

Each prompt starts with an indicator for the player whose turn it is:  
- The letter `C` indicates the Black player.  
- The letter `B` indicates the White player.

The remainder of the prompt line is a sequence of field names indicating all the fields where the current player can legally place their piece. The field names are sorted lexicographically, and each name is preceded by a space.
