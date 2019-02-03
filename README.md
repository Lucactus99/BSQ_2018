The program finds the largest possible square on a board while avoiding obstacles.

The board is represented by a file passed as the program’s argument, respecting those constraints:

• its first line contains the number of lines on the board (and only that),

• "." (representing an empty place) and "o" (representing an obstacle) are the only two allowed characters for the
other lines,

• all of the lines will be the same length (except the first one),

• there will always be at least one line,

• each line is terminated by ’\n’.

The program prints the board, with some "." replaced by "x" to represent the largest square it founds.

If ever there are several solutions, the program represents only the highest square. If they are still several
solutions, the program will print the square to the left.

Mark: 18/20
