/*
PIC 10B 2A, Homework 1
Purpose: Tic-tac-toe game
Author: Anthony Katrdzhyan
Date: 01/22/2020
*/


#ifndef Player_H
#define Player_H
#include <iostream>
#include <stdio.h>
#define ROW 15 // Maximum number or rows
#define COL 15 // Maximum number or columns
using namespace std;

// Defines a class for Player to store player name and score
class Player
{
    string name;
    int score;
    
public:
// Prototype of member functions
    Player(string);
    string getName();
    int getScore();
    void setName(string);
    void setScore();
};

#endif // Player_H
