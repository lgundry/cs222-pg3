Welcome to my CS220 Maze Solver Program:
This program is designed to solve a maze using a recursive backtracking algorithm. The program will read a maze from command prompt input

Rules:

    Valid Characters:
        - ' ' (space) - represents a valid path/empty space
        - '*' (asterisk) - represents a wall

    The top leftmost square is the starting position and the bottom rightmost square is the ending position

    You can only move in 2 cardinal directions: Down and Right - any maze requiring left or upward movements will not be solved

Have Fun!

---------------------------------------------------------------------------------

Known bugs:
    - On some mazes, solution is found but some rows are shifted in solution (the path is usually still correct). I have not been able to find what is causing it but it only happens on specific mazes.