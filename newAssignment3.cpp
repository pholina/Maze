/*
Selina Nguyen HW 3
This file is used to test the maze and creature.
It helps identiify problem areas within the code aswell. 
*/
#include <iostream>
#include <fstream>

#include "newMaze.h"
#include "newCreature.h"
using namespace std;

void test(std::string fileName, int startRow, int startCol) //creating a test function that takes in the file's name, and a starting postion for the creature
{
    std::cout << std::endl << "File Name: " << fileName << std::endl; //prints file information
    Maze *maze = new Maze(fileName); //creatues a new maze with the new file
    //maze->print();
    Creature *creature = new Creature(startRow, startCol); //creates a new crearture with the new starting positions
    std::cout << "\nCreature starts at: " << startRow << ", " << startCol << std::endl; //prints creature's information
    std::string path = creature->Solve(*maze); //calls the solve method where the recusion happens to navigate the maze

    cout << *maze; //prints the maze
    std::cout << "Creature's Path: " << path << endl; //prints the path that the creature took to make it to the exit
    delete maze; //deletes the maze to avoid leaks
    delete creature; //deletes creature to avoid leaks
}


int main()
{
    //testing a maze that does not have a way out
    cout << endl << "!!! MAZE WITH NO EXIT !!!" << endl;
    test("mazeNoExit1.txt", 10, 8 ); //calls test function with updated file name and creature's positions

    //testing a simple maze that is less prone to errors
    cout << "_______________________________" <<endl;
    cout << endl <<"!!! SIMPLE MAZE !!!" << endl;
    test("mazeSimple.txt", 3, 4);

    // testing a maze that starts an a location that is outside of the maze walls
    cout <<"_______________________________" <<endl;
    cout << endl <<"!!! OUT OF BOUNDS !!!" << endl;
    test("maze2.txt", 10, 8);

    //testing a maze that starts on a wall
        cout << "_______________________________" <<endl;
    cout << endl << "!!! BAD LOCATION !!!" <<endl;
    test("maze.txt", 0, 0);

    // testing a different maze variation this helps us identify if the path and updated maze prints out correctly and works
    cout << "_______________________________" <<endl;
    cout << endl <<"!!! MAZE 1 !!!" << endl;
    test("maze1.txt", 4, 8);
    
    //testing second maze variation
    cout << "_______________________________" <<endl;
    cout << endl <<"!!! MAZE 2 !!!" << endl;
    test("maze2.txt", 1, 8);



    return 0;
}