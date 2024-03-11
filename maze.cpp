#include "maze.h"

using namespace std;


maze::maze(string blueprint, int height, int width) {

    // initialize maze components
    queue<char> row;

    // verify blueprint
    assert(blueprint.length() == height * width);
    assert(blueprint[0] == ' ');

    // start create maze
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 && j == 0)
                row.push('S');
            else if (i == height-1 && j == width-1)
                row.push('E');
             else 
                row.push(blueprint[i+j]);
        }
        myMaze.push(row);
    }
    // end create maze
    
}

char maze::peek(queue<char> row) {
    char ans = row.pop();
    row.push(ans);
    return ans;
}

queue<char> maze::peek(queue<queue<char>> maze) {
    queue<char> ans = maze.pop();
    maze.push(ans);
    return ans;
}

int* maze::getSpaces(queue<char> row) {
    int* spaces = 0;
    int spaceindex = 0;
    for (int i = 0; i < width; i++) {
        if (peek(row) == ' ') {
            spaces[spaceindex] = i;
            spaceindex++;
        }
    }
    return spaces;
}

queue<queue<char>> maze::solveMaze() {

    queue<char> row;
    queue<int*> spaces;
    queue<queue<char>> ans;
    queue<queue<char>> tempPath;
    int failcount = 0;
    int* tempSpaces = 0;
    bool solved = false;

    int tempSpace1;
    int tempSpace2;

    for (int i = 0; i < height; i++) {
            spaces.push(getSpaces(peek(myMaze)));
    }
    while (!solved) {
        switch(failcount) {

        }
    }
    return ans;

}
