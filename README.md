# Tic-tac-toe
Tic Tac Toe Game in C

A simple two-player Tic Tac Toe game implemented in C. Players take turns marking cells in a 3×3 grid, aiming to align three of their symbols horizontally, vertically, or diagonally. The game detects wins, ties, and allows replay.

Features

Turn-based gameplay for two players

Dynamic board display using ❌ and ⭕ emojis

Win, lose, and tie detection

Replay option after each game

Input validation to prevent overwriting occupied positions

How to Play

Compile the program:

gcc tic_tac_toe.c -o tic_tac_toe


Run the executable:

./tic_tac_toe


Enter the names of Player 1 and Player 2.

Players select positions by specifying the row and column (example: 0 2).

The game continues until a player wins or all positions are filled (tie).

Optionally, choose to play again after the game ends.

Example Board
-------------------------
|       |  ❌   |       |
-------------------------
|  ⭕   |       |  ❌   |
-------------------------
|       |  ⭕   |       |
-------------------------

Functions

print_table() – Displays the current board with symbols

match_check() – Checks for a win or tie
