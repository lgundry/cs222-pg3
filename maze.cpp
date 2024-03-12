#include "maze.h"

using namespace std;


maze::maze(string blueprint, int newHeight, int newWidth) {

    // initialize maze components
    queue<char> *row = new queue<char>;
    height = newHeight;
    width = newWidth;

    // verify blueprint
    assert(blueprint.length() == height * width);

    // start create maze
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 && j == 0)
                row->push('S');
            else if (i == height-1 && j == width-1)
                row->push('E');
             else 
                row->push(blueprint[i*width+j]);
        }
        myMaze.push(row);
        row = nullptr;
        row = new queue<char>;
    }
    // end create maze
    
}

char maze::peek(queue<char>* row) {
    char ans = row->pop();
    row->push(ans);
    return ans;
}

queue<char>* maze::peek() {
    queue<char> *ans = myMaze.pop();
    myMaze.push(ans);
    return ans;
}

queue<queue<char>*> maze::solveMaze() {
    queue<pair<int, int>> path;
    
}
void maze::print() {
    queue<char> *row;
    for (int i = 0; i < height; i++) {
        row = peek();
        for (int j = 0; j < width; j++) {
            cout << peek(row);
        }
        cout << endl;
    }
}