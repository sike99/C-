#ifndef GAME_H
#define GAME_H

#include "maze.h"

class Game {
private:
    Maze maze;
    bool running;

public:
    Game();
    void run();
    void processInput(char input);
};

#endif
