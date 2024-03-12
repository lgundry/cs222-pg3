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

char maze::peek(queue<char>* row) {
    char ans = row->pop();
    row->push(ans);
    return ans;
}

queue<char>* maze::peek() {
    queue<char> *ans = myMaze->pop();
    myMaze->push(ans);
    return ans;
}

bool visited(pair<int, int> location, maze *m, queue<pair<int, int>> path) {
    while (!path.isEmpty()) {
        pair<int, int> temp = path.pop();
        if (temp == location) {
            path.push(temp);
            return true;
        }
        path.push(temp);
    }
    return false;
}

char maze::checkcurrent(pair<int, int> current, maze *m) {
    queue<char> *row = new queue<char>;
    char ans = ' ';
    for (int i = 0; i <= current.first; i++) {
        row = m->peek();
    }
    for (int j = 0; j < current.second + width - 1; j++) {
        peek(row);
    }
    char temp = peek(row);
    if (temp == '*') {
        ans = 0;
    }
    else 
        ans = temp;
    for (int i = 0; i < width - current.second; i++) {
        peek(row);
    }
    for (int i = 0; i < height - current.first; i++) {
        m->peek();
    }
    return ans;
}

char maze::checkleft(pair<int, int> current, maze *m) {
    queue<char> *row = new queue<char>;
    char ans = ' ';
    if (visited(current, m, pointsVisited)) {
        return 0;
    }
    for (int i = 0; i <= current.first; i++) {
        row = m->peek();
    }
    for (int j = 0; j < current.second + width - 2; j++) {
        peek(row);
    }
    char temp = peek(row);
    if (temp == '*') {
        ans = false;
    }
    else 
        ans = temp;
    for (int i = 0; i < width - current.second + 1; i++) {
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
    if (visited(current, m, pointsVisited)) {
        return 0;
    }
    for (int i = 0; i <= current.first; i++) {
        row = m->peek();
    }
    for (int j = 0; j < current.second + width; j++) {
        peek(row);
    }
    char temp = peek(row);
    if (temp == '*') {
        ans = false;
    }
    else 
        ans = temp;
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
    if (visited(current, m, pointsVisited)) {
        return 0;
    }
    for (int i = 0; i <= current.first + 1; i++) {
        row = m->peek();
    }
    for (int j = 0; j < current.second + width - 1; j++) {
        peek(row);
    }
    char temp = peek(row);
    if (temp == '*') {
        ans = false;
    }
    else 
        ans = temp;
    for (int i = 0; i < width - current.second; i++) {
        peek(row);
    }
    for (int i = 0; i < height - current.first - 1; i++) {
        m->peek();
    }
    return ans;
}
char maze::checkup(pair<int, int> current, maze *m) {
    queue<char> *row = new queue<char>;
    char ans = ' ';
    if (visited(current, m, pointsVisited)) {
        return 0;
    }
    for (int i = 0; i <= current.first - 1; i++) {
        row = m->peek();
    }
    for (int j = 0; j < current.second + width - 1; j++) {
        peek(row);
    }
    char temp = peek(row);
    if (temp == '*') {
        ans = false;
    }
    for (int i = 0; i < width - current.second; i++) {
        peek(row);
    }
    for (int i = 0; i < height - current.first + 1; i++) {
        m->peek();
    }
    return ans;
}

bool maze::findPath(pair<int, int> current) {
    bool ans = false;
    pointsVisited.push(current);
    if (current.second < 0 || current.first < 0 || current.second > width || current.first > height) {
        return false;
    }
    else if (checkcurrent(current, this) == 'E') {
        path.push(current);
        return true;
    }
    else if (checkright(current, this) && findPath(make_pair(current.first, current.second + 1))) {
        path.push(current);
        return true;
    }
    else if (checkleft(current, this) && findPath(make_pair(current.first, current.second - 1))) {
        path.push(current);
        return true;
    }
    else if (checkdown(current, this) && findPath(make_pair(current.first + 1, current.second))) {
        path.push(current);
        return true;
    }
    else if (checkup(current, this) && findPath(make_pair(current.first - 1, current.second))) {
        path.push(current);
        return true;
    }
    return false;
}

void maze::generateSolution() {
    queue<char> *row = new queue<char>;
    while (!path.isEmpty()) {
        pair<int, int> current = path.pop();
        for (int i = 0; i < current.first; i++) {
            peek();
        }
        row = myMaze->pop();
        for (int i = 0; i < current.second; i++) {
            peek(row);
        }
        row->pop();
        row->push('X');
        for (int i = 0; i < width - current.second - 1; i++) {
            peek(row);
        }
        myMaze->push(row);
        for (int i = 0; i < height - current.first - 1; i++) {
            peek();
        }
    }
}

void maze::solveMaze() {
    queue<queue<char>*> ans;
    if (!findPath(make_pair(0, 0))) {
        perror("No path found");
        exit(0);
    }
    generateSolution();
    myMaze = solution;
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