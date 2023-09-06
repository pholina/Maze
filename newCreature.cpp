/*
Selina Nguyen HW 3
This file (newCreature.cpp) is used to define variables and functions
within the creature.h file. All of the code within this file is used to
create the creature and all of its features, it provides specifics about the creature.
It is the body of the creature.
*/

#include "newCreature.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Creature::Creature(int row, int col) { //creature constructor that initializes the creature's starting row and column position
    height = row;
    width = col;
    path = ""; //create an empty string for the path
}

bool Creature:: isBoundary(int row, int col, Maze &maze) { //checks if creature is within the boundaries of the maze (not going too far out)
    int myHeight = maze.myHeight()-1; 
    int myWidth = maze.myWidth()-1;
    if (row>= 0 && row <= myHeight && col>=0 && col <= myWidth){
        return true; //checks if position is outside of the maze walls
    }
    return false;
}

bool Creature::goNorth(Maze &maze) { //moves creature one spot up
    int newRow = height - 1; //changes the row to move up
    int newCol = width;
    if (!isBoundary(newRow, newCol, maze) || !maze.IsClear(newRow, newCol)) { //checks if creature is not within the boundary and not clear to move
        return false;
    }
    height = newRow;
    width = newCol;
    path += "N"; //adding to path
    maze.MarkAsPath(height, width); //setting position to a star
    if (maze.IsExit(height, width)) { //check if at exit
        return true;
    }
    if (goNorth(maze)) { //used for backtracking, check if can go north
        return true;
    }
    if (goWest(maze)) { //check if can go west
        return true;
    }
    if (goEast(maze)) { //check if can go east
        return true;
    }
    maze.MarkAsVisited(height, width); //mark as a plus if visited position does not lead to exit
    height++; //increments to next row
    path.pop_back(); //removes last string entry
    return false;
}
    
bool Creature::goEast(Maze &maze) { //moves creature one spot to the right
    int newRow = height;
    int newCol = width + 1; //changes the column to move to the right
    if (!isBoundary(newRow, newCol, maze) || !maze.IsClear(newRow, newCol)) { //checking if not within boundary and if spot is not clear
        return false;
    }
    height = newRow;
    width = newCol;
    path += "E"; //adding to path
    maze.MarkAsPath(height, width); //mark creature position as a star
    if (maze.IsExit(height, width)) { //checks if at exit
        return true;
    }
    if (goEast(maze)) { //used for backtracking, check if can go east
        return true;
    }
    if (goNorth(maze)) { //check if can go north
        return true;
    }
    if (goSouth(maze)) { //check if can go south
        return true;
    }
    maze.MarkAsVisited(height, width); //mark as a plus to inidicate spot is not part of path to exit
    width--; //move to the left by one
    path.pop_back();
    return false;
}
    
bool Creature::goWest(Maze &maze) { //moves creature one spot to the left
    int newRow = height;
    int newCol = width - 1; //changes creatures spot to the left by one
    if (!isBoundary(newRow, newCol, maze) || !maze.IsClear(newRow, newCol)) { //checking for not in boundary and not clear
        return false;
    }
    height = newRow;
    width = newCol;
    path += "W"; //adding to string
    maze.MarkAsPath(height, width); //setting position to a star
    if (maze.IsExit(height, width)) { //check if at exit
        return true;
    }
    if (goWest(maze)) { //backtracking, checks if can go west
        return true;
    }
    if (goNorth(maze)) { //checks if can go north
        return true;
    }
    if (goSouth(maze)) { //checks if can go south
        return true;
    }
    maze.MarkAsVisited(height, width); //mark as a plus to indicate not part of path to exit
    width++; //move to the right by one
    path.pop_back(); 
    return false;
}

bool Creature::goSouth(Maze &maze) { //moves creature one spot down
    int newRow = height + 1; //changes creatures position to go down one
    int newCol = width;
    if (!isBoundary(newRow, newCol, maze) || !maze.IsClear(newRow, newCol)) { //checks for creature being outside of the maze of on an "X"
        return false;
    }
    height = newRow;
    width = newCol;
    path += "S"; //adding to path
    maze.MarkAsPath(height, width); //marking as a star to include into path
    if (maze.IsExit(height, width)) { //check if at exit
        return true;
    }
    if (goSouth(maze)) { //backtracking, check if can go south
        return true;
    }
    if (goEast(maze)) { //check if can go east
        return true;
    }
    if (goWest(maze)) { //check if can go west
        return true;
    }
    maze.MarkAsVisited(height, width); //mark as visited to indicate that it is not part of path
    height--; //move down up one level
    path.pop_back();
    return false;
}

string Creature::Solve(Maze& maze) { //used to call all directions and checks if creature is at exit, return path
    if (maze.IsExit(height, width)) { //check if creature is at exit
        return path; //return string path
    }
    if (goNorth(maze) || goEast(maze) || goSouth(maze) || goWest(maze)) { //checks if creature was able to find path in all directions
        return path; //return string path
    }
    return path += "X"; //if none successful, return an X as path
}

ostream &operator<<(ostream &out, const Creature &creature) { //overloaded operator that prints current height and width postion for each move made to get to exit as it goes through maze
    out << creature.height << ", "<< creature.width <<endl;
    return out;

}