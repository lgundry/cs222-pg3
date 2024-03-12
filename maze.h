#pragma once
#include "queue.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

class maze {
    queue<queue<char>*>* myMaze;
    queue<queue<char>*>* solution;
    queue<pair<int, int>> path;
    queue<pair<int, int>> pointsVisited;
    int height, width;


    public:
    maze();
    maze(string blueprint, int height, int width); // constructor
    ~maze();
    char checkcurrent(pair<int, int> current, maze *m); // return true if current is a valid move
    char checkleft(pair<int, int> current, maze *m); // return true if left is a valid move
    char checkright(pair<int, int> current, maze *m); // return true if right is a valid move
    char checkdown(pair<int, int> current, maze *m); // return true if down is a valid move
    char checkup(pair<int, int> current, maze *m); // return true if up is a valid move
    bool findPath(pair<int, int> current);
    void generateSolution();
    void solveMaze();
    int* getSpaces(queue<char>* row);
    char peek(queue<char>* row);
    queue<char>* peek();
    void print();
};