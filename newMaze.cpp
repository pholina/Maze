/*
Selina Nguyen HW 3
This file (maze.cpp) is used to define variables and functions
within the maze.h file. All of the code within this file is used to
create the maze and all of its features, it provides specifics about the maze.
It is the body of the maze.
*/

#include "newMaze.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Maze::Maze(string fileName){ //constructor that takes in a file name and creates the maze based on attributes listed in that file

    ifstream mazeFile; 
    string myTxt;
    mazeFile.open(fileName); 

    if (mazeFile.is_open()){ //check if file is open
        mazeFile >> width; //reads and stores width
        mazeFile >> height; //reads and stores height
        mazeFile >> exRow; //reads and stores the row in which the exit is located
        mazeFile >> exCol; //reads and stores the column in which the exit is located
    
        getline(mazeFile, myTxt);

        for (int i = 0; i < height; i++) { //reads and stores the maze itself
            string str; 
            getline(mazeFile, str); //gets the next line in the file
            for (int j = 0; j < width; j++) {
                mazeSize[i][j] = str[j]; 
            }
        }
    }
    else {
        cout<<"Could not read file"<<endl; //used to handle cases in which the file was not able to be opened
        return;
    }
    mazeFile.close();
}

bool Maze::IsClear(int row, int col) const { //checks to see if the path is space, indicating that that direction is clear/safe
    if (mazeSize[row][col] == ' ') { //checks for a space, this means creature can move here
        return true;
    } 
    return false;
}


bool Maze::IsWall(int row, int col) const { //checks to see if the path is within the maze and is not a "wall", a wall is an "X" 
    if (mazeSize[row][col] == 'x' || mazeSize[row][col] == 'X') { //checks for lower and uppercase "X"
        return true;
    }
    return false;
}

bool Maze::IsPath(int row, int col) const { //checks for a star, meaning that that position is part of the path to the exit
    if (mazeSize[row][col] == '*') { //checks if spot is a star
        return true;
    }
    return false;
}


bool Maze::IsVisited(int row, int col) const { //checks for a plus, meaning that that position has already been visited
    if (mazeSize[row][col] == '+') { //checks if spot is a plus
        return true;
    }
    return false;
}

bool Maze::IsExit(int row, int col) const { //checks if creature is in the row and column spot that the exit is positioned at
    if (row == exRow && col == exCol) { //checks if the creature's row and column is equal to the exit row and column
        return true;
    }
    return false;
}

void Maze::MarkAsPath(int row, int col) { //used to mark the location the creature is on as a path, the path can be used to find the exit
    mazeSize[row][col] = '*'; //set the spot of the creature to a star to indicate it is part of the path
}


void Maze::MarkAsVisited(int row, int col) { //used to mark the location the creature is on as visited, visited means that the creature has been in that spot before and that spot did not lead to exit
    mazeSize[row][col] = '+'; //set the spot of the creature to a plus to indicate that it was a spot that did not lead to the exit
}

int Maze::myHeight() const { //gives the creature class the ability to use height which is private
    return height;
}

int Maze:: myWidth() const { //gives the creature class the ability to use width which is private
    return width;
}

int Maze::myExRow() const { //gives the creature class the ability to use the exit height which is private
    return exRow;
}

int Maze::myExCol() const { //gives the creature class the ability to use the exit width which is private
    return exCol;
}

ostream &operator<<(ostream &out, const Maze &maze) { //overloaded operator used to print attributes of the maze
 for (int i = 0; i < maze.height; i++){ //loops through the maze
        for (int j = 0; j < maze.width; j++){
            out << maze.mazeSize[i][j]; 
        }
        out << endl;
    } 
    return out;
}