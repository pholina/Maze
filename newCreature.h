/*
Selina Nguyen HW3
This file (newCreature.h) is used to declare variables and functions
relevant to the creature of the assignment.
It is the shell of the creature. 
*/

#ifndef NEWCREATURE_H
#define NEWCREATURE_H

#include <iostream>
#include <string>
#include "newMaze.h"

using namespace std;

class Creature {
        private:
        int height; //height represents the rows of the maze
        int width; //width represents the columns of the maze
        int strtRow; //represents the starting row position of the creature
        int strtCol; //represents the starting column position of the creature

        string path; //used to store the path of the creature

        bool isBoundary(int row, int col, Maze &maze); //checks if the creature is going outside the walls of the maze

    public:
        Creature(int row, int col); //creates a creature object that takes in a starting position
        string Solve(Maze &maze); //used to call all directions to shift creature's position, returns the path that the creature took to get to exit
        bool goNorth(Maze &maze); //moves the position of the creature one row up
        bool goEast(Maze &maze); //moves the position of the creature one row to the right
        bool goWest(Maze &maze); //moves the position of the creature one row to the left
        bool goSouth(Maze &maze); //moves the position of the creature one row down

        friend ostream &operator<<(ostream &out, const Creature &creature); //overloaded output operator used to print creature's position
};

#endif