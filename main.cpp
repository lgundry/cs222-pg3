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

    cout 
        << "\nWelcome to the maze solver. You will be asked the following: \n" 
        << "Height: All real integers accepted\n" 
        << "Width: All real integers accepted\n" 
        << "Maze construction: Characters accepted are '*' and ' '. The top leftmost slot is the\n"
        << "\tstarting point, while the bottom rightmost slot is the end point. If you go past the\n"
        << "\tend of the maze boundaries, the end will simply be cut off.\n"
        << "Final Rule: The solver cannot follow paths moving upwards, so make sure your maze only requires\n"
        << "\tdownward and lateral movements to solve\n\n"
        << endl;

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
    // myMaze->solveMaze();
    myMaze->print();
}