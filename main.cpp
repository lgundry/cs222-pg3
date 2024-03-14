#include "queue.h"
#include "maze.h"

using namespace std;

/*
    Ensures that the string contains valid data. What is considered valid is decided by type.
    options for type:
        0: int
        1: '*' or ' '   -- for maze building
*/
bool verify(string input, int type) {
    switch(type) {
        case 0:
            for (int i : input) {
                if (!isdigit(i)){
                    cout << ("Invalid input: \"" + input + "\" is not an integer") << endl;
                    return false;
                }
            }
            return true;
        case 1:
            for (int i : input) {
                if (i != '*' && i != ' '){
                    cout << ("Invalid input: \"" + input + "\" contains invalid characters") << endl;
                    return false;
                }
            }
    }
    return 0;
}

int main(){

    cout << "Welcome to my CS220 Maze Solver Program:\n\n"
         << "This program is designed to solve a maze using a recursive backtracking algorithm. The program will read a maze from command prompt input\n\n"

        << "Rules:\n\n"

        << "\tValid Characters:\n"
        << "\t\t- ' ' (space) - represents a valid path/empty space\n"
        << "\t\t- '*' (asterisk) - represents a wall\n\n"

        << "\tThe top leftmost square is the starting position and the bottom rightmost square is the ending position\n\n"

        << "\tYou can only move in 2 cardinal directions: Down and Right - any maze requiring left or upward movements will not be solved\n\n"

        << "Have Fun!\n" 
        << "============================================================================\n" << endl;

    int height;
    int width;
    string mazeBlueprint = "";
    string input = "";

    cout << "Enter the height of the maze: ";
    getline(cin, input);
    if (!verify(input, 0)) return 0;
    height = stoi(input);

    cout << "Enter the width of the maze: ";
    getline(cin, input);
    if (!verify(input, 0)) return 0;
    width = stoi(input);

    cout << "Please enter the maze below:" << endl;
    for (int i = 0; i < height; i++) {
        getline(cin, input);

        // verify input contains legal characters
        if (verify(input, 1)) return 0;

        // if the user doesn't give enough characters
        while (input.length() < width) {
            input += " ";
        }
        
        // if the user gives too many characters
        if (input.length() > width)
            input.erase(width, input.length() - (width));
        mazeBlueprint += input;
    }
    cout << "Solving maze..." << endl;

    maze *myMaze = new maze(mazeBlueprint, height, width);
    myMaze->solveMaze();
    myMaze->print();
}