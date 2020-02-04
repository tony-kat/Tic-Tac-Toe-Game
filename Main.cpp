/*
Main Code for Tic Tac Toe Game
*/

#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"
using namespace std;

Player::Player(string na) {
    name = na;
    score = 0;
}

string Player::getName() {
    return name;
}

int Player::getScore() {
    return score;
    }

void Player::setName(string na) {
    name = na;
}

void Player::setScore() {
    score++;
}

void Game::resetBoard() {
    for(int r = 0; r < 3; r++)

            for(int c = 0; c < 3; c++)
            Board[r][c] = ' ';
}

void Game::moveX(string name) {

    int posRow, posCol;
    cout<<"\n "<<name<<" turn.";
    cout<<"\n Where do you want your X placed? ";
    
    cout<<"\n Please enter row number and column number separated by a space: ";
    cin >> posRow >> posCol;
    cout<<"\n You have entered row #"<<posRow<<"\n\t and column #"<<posCol;
    
posRow--; posCol--;

// Checks if the board row and column position is not null
if(Board[posRow][posCol] != ' ') {
    cout<<"\n Invalid move, try again.";
    moveX(name);
}
    
else

    Board[posRow][posCol] = 'X';
}

void Game::moveO(string name) {
    int posRow, posCol;
    cout<<"\n "<<name<<" turn.";
    cout<<"\n Where do you want your O placed? ";
    cout<<"\n Please enter row number and column number separated by a space: ";
    cin >> posRow >> posCol;
    cout<<"\n You have entered row #"<<posRow<<"\n\t and column #"<<posCol;
posRow--; posCol--;

// Checks if the board row and column position is not null
if(Board[posRow][posCol] != ' ') {
cout<<"\n Invalid move, try again.";

moveO(name);
}
else
Board[posRow][posCol] = 'O';
}

// Function to check the empty column for a given row as a parameter
int Game::emptyColumn(int r) {
    for (int c = 0; c < 3; ++c) {
            if (Board[r][c] == ' ')
                return c;
    }
    return -1;}

int Game::emptyRow(int c) {
for (int r = 0; r < 3; ++r) {
    if (Board[r][c] == ' ')
        return r;
}
    return -1;

}

// Function to check winning possibility for player 'O' move
bool Game::winnable(int mat[3][3]) {
    char a, b, c, d, e, f, g, h, i;
        a = mat[0][0];
        b = mat[0][1];
        c = mat[0][2];
        d = mat[1][0];
        e = mat[1][1];
        f = mat[1][2];
        g = mat[2][0];
        h = mat[2][1];
        i = mat[2][2];

if ( (a=='O' && b=='O' && c!='X') || (b=='O' && c=='O' && a!='X') || (a=='O' && c=='O' && b!='X') ) {
    row = 1;
    return true;
}
    
if ( (d=='O' && e=='O' && f!='X') || (e=='O' && f=='O' && d!='X') || (d=='O' && f=='O' && e!='X') ) {
    row = 2;
    return true;
}
    
if ( (g=='O' && h=='O' && i!='X') || (h=='O' && i=='O' && g!='X') || (g=='O' && i=='O' && h!='X') ) {
    row = 3;
    return true;
}


if ( (a=='O' && d=='O' && g!='X') || (d=='O' && g=='O' && a!='X') || (a=='O' && g=='O' && d!='X') ) {
    column = 1;
    return true;
}
    
if ( (b=='O' && e=='O' && h!='X') || (e=='O' && h=='O' && b!='X') || (b=='O' && h=='O' && e!='X') ) {
    column = 2;
    return true;
}
    
if ( (c=='O' && f=='O' && i!='X') || (f=='O' && i=='O' && c!='X') || (c=='O' && i=='O' && f!='X') ) {
    column = 3;
    return true;
}


if ( (a=='O' && e=='O' && i!='X') || (e=='O' && i=='O' && a!='X') || (a=='O' && i=='O' && e!='X') ) {
diagonal = 1;
return true;
}


if ( (g=='O' && e=='O' && c!='X') || (e=='O' && c=='O' && g!='X') || (g=='O' && c=='O' && e!='X') ) {
    diagonal = 2;
    return true;
}
return false;
    
}

// Function to check winning possibility for player 'X' move
bool Game::vulnerable(int mat[3][3]) {
    char a, b, c, d, e, f, g, h, i;
        a = mat[0][0];
        b = mat[0][1];
        c = mat[0][2];
        d = mat[1][0];
        e = mat[1][1];
        f = mat[1][2];
        g = mat[2][0];
        h = mat[2][1];
        i = mat[2][2];

    
if ( (a=='X' && b=='X' && c!='O') || (b=='X' && c=='X' && a!='O') || (a=='X' && c=='X' && b!='O') ) {
    row = 1;
    return true;
}
    
if ( (d=='X' && e=='X' && f!='O') || (e=='X' && f=='X' && d!='O') || (d=='X' && f=='X' && e!='O') ) {
    row = 2;
    return true;
}
    
if ( (g=='X' && h=='X' && i!='O') || (h=='X' && i=='X' && g!='O') || (g=='X' && i=='X' && h!='O') ) {
    row = 3;
    return true;
}

if ( (a=='X' && d=='X' && g!='O') || (d=='X' && g=='X' && a!='O') || (a=='X' && g=='X' && d!='O') ) {
    column = 1;
    return true;
}
    
if ( (b=='X' && e=='X' && h!='O') || (e=='X' && h=='X' && b!='O') || (b=='X' && h=='X' && e!='O') ) {
    column = 2;
    return true;
}
    
if ( (c=='X' && f=='X' && i!='O') || (f=='X' && i=='X' && c!='O') || (c=='X' && i=='X' && f!='O') ) {
    column = 3;
    return true;
}


if ( (a=='X' && e=='X' && i!='O') || (e=='X' && i=='X' && a!='O') || (a=='X' && i=='X' && e!='O') ) {
    diagonal = 1;
    return true;
}


if ( (g=='X' && e=='X' && c!='O') || (e=='X' && c=='X' && g!='O') || (g=='X' && c=='X' && e!='O') ) {
    diagonal = 2;
    return true;
}
    
return false;
}


void Game::printBoard()
{
    cout<<endl;

for(int c = 0; c < 3; c++)
{
    cout << " " << char(Board[c][0]) << " | " << char(Board[c][1]) << " | " << char(Board[c][2]);
if(c != 2)
    cout << "\n---|---|---\n";
}
    cout << endl;
}// End of function


char Game::check() {
    for(int r = 0; r < 3; r++)
        if(Board[r][0] == Board[r][1] && Board[r][0] == Board[r][2])
            return Board[r][0];

    for(int r = 0; r < 3; r++)
        if(Board[0][r] == Board[1][r] && Board[0][r] == Board[2][r])
            return Board[0][r];

    if(Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
        return Board[0][0];

    if(Board[0][2] == Board[1][1] && Board[1][1]==Board[2][0])
        return Board[0][2];

    return ' ';
}

// Function to return if still some vacant places are there in the board to move
bool Game::getGameState(int Bo[][COL]) {
    for (int r = 0; r < 3; ++r){
        for (int c = 0; c < 3; ++c) {
            if (Bo[r][c] == ' ')
                return false;
        }
}

return true;
}

// Reset the row, column and diagonal values for next game
void Game::reset() {
    row = 0;
    column = 0;
    diagonal = 0;
}

// main function definition
int main(void) {
char done; char c;
bool CONTINUE = true;
Game fb;
string name;
    
// Accepts first player name
cout<<"\n Enter player name for symbol X: ";
cin>>name;
// Creates an object of the class Player using parameterized constructor to set player name
Player player1(name);

// Accepts second player name
cout<<"\n Enter player name for symbol O: ";
cin>>name;
// Creates an object of the class Player using parameterized constructor to set player name
Player player2(name);

// Loops till CONTINUE value is true
while (CONTINUE)
{

cout<<"\n Player vs. Player Tac Toe."<<endl;
done = ' ';
// Calls the function to create board for playing
fb.resetBoard();

do {
    fb.printBoard();
    fb.moveX(player1.getName());
    done = fb.check();
    if(done != ' ')
        break;
        fb.printBoard();
        fb.moveO(player2.getName());
        done = fb.check();
        if(done!= ' ')
            break;
            if (fb.getGameState(fb.Board)) {
                fb.printBoard();
                cout << endl;
                cout<<"\n Game Draw";
                break;
}

    fb.reset();
} while(done == ' ');

if(done == 'X') {
    cout<<"\n "<<player1.getName()<<" wins this round";
    player1.setScore();
}
else if(done == 'O') {
        cout<<"\n "<<player2.getName()<<" wins this round";
        player2.setScore();
    }

else {
cout<<"\n This round is a draw";
}

// Calls the function to display final board values
fb.printBoard();
cout<<"\n Player "<<player1.getName()<<"'s score: "<<player1.getScore();
cout<<"\n Player "<<player2.getName()<<"'s score: "<<player2.getScore();
// Accepts user choice to whether continue or not
cout << "\n Play again? Y/N" << endl;
cin >> c;
// If user choice is 'N or 'n'
if ( c=='N' || c=='n')
CONTINUE = false;
fb.reset();
}
return 0;
}
