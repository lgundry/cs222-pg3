#include "maze.h"

using namespace std;


maze::maze(string blueprint, int newHeight, int newWidth) {

    // initialize maze components
    queue<char> *row = new queue<char>;
    myMaze = new queue<queue<char>*>;
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
        myMaze->push(row);
        row = nullptr;
        row = new queue<char>;
    }
    // end create maze
    
}

maze::~maze() {
    delete myMaze;
}

char maze::peek(queue<char>* row) {
    char ans = 0;
    if (!row->isEmpty()) {
        ans = row->pop();
        row->push(ans);
    }
    return ans;
}

queue<char>* maze::peek() {
    queue<char> *ans = nullptr;
    if (!myMaze->isEmpty()) {
        ans = myMaze->pop();
        myMaze->push(ans);
    }
    return ans;
}

bool visited(pair<int, int> location, maze *m, queue<pair<int, int>> &path) {
    bool ans = false;
    //loop through pop it off and push it both to make a copy - Haskel
    pair<int, int> first = path.pop();
    pair<int, int> temp;
    path.push(first);
    int count = 0;
    if (first == location) {
        ans =  true;
    }
    while (temp = path.pop(), temp != first) {
        path.push(temp);
        if (temp == first) {
            break;
        }
        else if (temp == location) {
            ans = true;
        }
        count++;
    }
    path.push(first);
    for (int i = 0; i < count; i++) {
        temp = path.pop();
        path.push(temp);
    }
    return ans;
}

char maze::checkcurrent(pair<int, int> current, maze *m) {
    queue<char> *row = new queue<char>;
    char ans = ' ';
    if (current.second < 0 || current.first < 0 || current.second > width || current.first > height) {
        return false;
    }
    for (int i = 0; i < current.first; i++) {
        row = m->peek();
    }
    for (int j = 0; j < current.second; j++) {
        ans = peek(row);
    }
    for (int i = 0; i < width - current.second; i++) {
        peek(row);
    }
    for (int i = 0; i < height - current.first; i++) {
        m->peek();
    }
    return ans;
}
char maze::checkright(pair<int, int> current, maze *m) {
    queue<char> *row = new queue<char>;
    char ans = ' ';
    if (current.second < 0 || current.first < 0 || current.second > width || current.first > height) {
        return false;
    }
    if (visited(make_pair(current.first, current.second + 1), m, pointsVisited)) {
        return 0;
    }
    for (int i = 0; i < current.first; i++) {
        row = m->peek();
    }
    for (int j = 0; j <= current.second; j++) {
        ans = peek(row);
    }
    for (int i = 0; i < width - current.second - 1; i++) {
        peek(row);
    }
    for (int i = 0; i < height - current.first; i++) {
        m->peek();
    }
    return ans;
}
char maze::checkdown(pair<int, int> current, maze *m) {
    queue<char> *row = new queue<char>;
    char ans = ' ';
    if (current.second < 0 || current.first < 0 || current.second > width || current.first > height) {
        return false;
    }
    if (visited(make_pair(current.first + 1, current.second), m, pointsVisited)) {
        return 0;
    }
    for (int i = 0; i <= current.first; i++) {
        row = m->peek();
    }
    for (int j = 0; j < current.second; j++) {
        ans = peek(row);
    }
    for (int i = 0; i < width - current.second; i++) {
        peek(row);
    }
    for (int i = 0; i <= height - current.first - 2; i++) {
        m->peek();
    }
    return ans;
}

bool maze::findPath(pair<int, int> current) {
    bool ans = false;
    if (current.second <= 0 || current.first <= 0 || current.second > width || current.first > height) {
        return false;
    }
    pointsVisited.push(current);
    if (checkcurrent(current, this) == 'E') {
        path.push(current);
        return true;
    }
    else if ((checkright(current, this) != '*') && findPath(make_pair(current.first, current.second + 1))) {
        path.push(current);
        return true;
    }
    else if ((checkdown(current, this) != '*') && findPath(make_pair(current.first + 1, current.second))) {
        path.push(current);
        return true;
    }
    return false;
}

void maze::generateSolution() {
    queue<char> *row;
    while (!path.isEmpty()) {
        pair<int, int> current = path.pop();
        row = new queue<char>;
        for (int i = 0; i < current.first - 1; i++) {
            peek();
        }
        row = myMaze->pop();
        for (int i = 0; i < current.second - 1; i++) {
            peek(row);
        }
        row->pop();
        row->push('X');
        for (int i = 0; i < width - current.second; i++) {
            peek(row);
        }
        myMaze->push(row);
        for (int i = 0; i < height - current.first; i++) {
            peek();
        }
        row = nullptr;
    }
}

void maze::solveMaze() {
    queue<queue<char>*> ans;
    if (!findPath(make_pair(1, 1))) {
        perror("No path found");
        exit(0);
    }
    generateSolution();
}

void maze::print() {
    queue<char> *row;
    for (int i = 0; i < height; i++) {
        row = peek();
        for (int j = 0; j < width; j++) {
            if (!row->isEmpty())
                cout << peek(row);
            else
                break;
        }
        cout << endl;
    }
}