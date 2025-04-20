#include "game.h"
#include <iostream>
using namespace std;

Game::Game() : running(true) {}

void Game::run() {
    char input;
    while (running) {
        maze.display();
        cin >> input;
        processInput(input);
    }
}

void Game::processInput(char input) {
    switch (toupper(input)) {
        case 'W':
        case 'A':
        case 'S':
        case 'D':
            maze.movePlayer(input);
            break;
        case 'Q':
            running = false;
            break;
        case 'R':
            if (maze.isGameOver()) {
                if (maze.isGameWon() && maze.getLevel() < 3) {
                    maze.nextLevel();
                } else {
                    maze.reset();
                }
            }
            break;
        case 'L':
            maze.loadFromFile("mazes/saved_maze.txt");
            break;
        case 'K':
            maze.saveToFile("mazes/saved_maze.txt");
            break;
    }
}
