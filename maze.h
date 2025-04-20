#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include "entity.h"
using namespace std;

class Maze {
private:
    static const int SIZE = 10;
    char grid[SIZE][SIZE];
    vector<Entity*> entities;
    int score;
    int moves;
    int currentLevel;
    bool gameOver;
    bool gameWon;

    void initializeEmptyMaze();
    void placeEntities();
    void moveEnemies();

public:
    Maze();
    ~Maze();

    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;
    void generateRandomMaze();
    void nextLevel();
    void reset();

    bool isGameOver() const { return gameOver; }
    bool isGameWon() const { return gameWon; }
    int getScore() const { return score; }
    int getMoves() const { return moves; }
    int getLevel() const { return currentLevel; }

    void display() const;
    bool isValidMove(int x, int y) const;
    void movePlayer(char direction);
    void update();
};

#endif
