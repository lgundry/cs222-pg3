#pragma once
#include "queue.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

class maze {
    queue<queue<char>*> myMaze;
    int height, width;
    public:
    maze();
    maze(string blueprint, int height, int width); // constructor
    ~maze();
    queue<queue<char>*> solveMaze();
    int* getSpaces(queue<char>* row);
    char peek(queue<char>* row);
    queue<char>* peek();
    void print();
};