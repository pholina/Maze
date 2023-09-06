/*
Selina Nguyen HW3
This file (newMaze.h) is used to declare variables and functions
relevant to the maze aspect of the assignment.
It is the shell of the maze. 
*/

#ifndef NEWMAZE_H
#define NEWMAZE_H

#include <iostream>
#include <string>
using namespace std;

class Maze {
     private:
        int height; //initialize height (row)
        int width; //initialize width (col)
        int exRow; //initialize row where exit is
        int exCol; //initialize col where exit is
        char mazeSize[100][100]; //intialize the max size of the 2D array

    public:
        explicit Maze(string fileName); //maze constructor that takes in a file name as a string to read later on
        bool IsClear(int row, int col) const; //checks if creature is not being blocked by a wall
        bool IsWall(int row, int col) const; //checks if creature is blocked by wall
        bool IsPath(int row, int col) const; //checks if creature is on a path
        bool IsExit(int row, int col) const; //checks if creature is at the exit
        bool IsVisited(int row, int col) const; //checks if creature is in a spot it has visted
        void MarkAsPath(int row, int col); //allows creature's spot to be marked as a path 
        void MarkAsVisited(int row, int col); //allows creature's spot to be marked as a spot that it has already been to
        int myHeight() const; //gives access to the private height variable
        int myWidth() const; //gives access to the private width variable
        int myExRow() const; //gives access to the private variable that stores the exit row
        int myExCol() const; //gives access to the private variable that stores the exit column
        friend ostream &operator<<(ostream &out, const Maze &maze); //used for output
};

#endif