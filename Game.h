
#ifndef Game_H
#define Game_H
#include <iostream>
#include <stdio.h>
#define ROW 15 // Maximum number or rows
#define COL 15 // Maximum number or columns
using namespace std;


// Defines class for the game
class Game
{

    int row, column, diagonal;

public:
// Declares a board of 5 x 5 matrix
    int Board[ROW][COL];
// Function to create a matrix for board and initializes each cell to null
    void resetBoard();
// Functions for players move
    void moveX(string);
// Function for computers move
    void moveO(string);
// Function to check winning possibility for 'O' move
    bool winnable(int mat[3][3]);
// Function to check the empty column for a given row as a parameter
    int emptyColumn(int r);
// Function to check the empty row for a given column as a parameter
    int emptyRow(int c);
// Function to check board values for winning
    bool vulnerable(int mat[3][3]);
// Displays board
    void printBoard();
// Function to identifying winner
    char check();
// Function to return if still some vacant places are there in the board to move
    bool getGameState(int [][COL]);
// Reset the row, column and diagonal values for next game
    void reset();
}; // End of class
#endif // Game_H
