#include "maze.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Maze::Maze() : score(0), moves(0), currentLevel(1), gameOver(false), gameWon(false) {
    initializeEmptyMaze();
    generateRandomMaze();
}

Maze::~Maze() {
    for (Entity* entity : entities) {
        delete entity;
    }
}

void Maze::initializeEmptyMaze() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = ' ';
        }
    }
}

void Maze::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
       cerr << "Error opening file: " << filename <<endl;
        return;
    }

    for (Entity* entity : entities) {
        delete entity;
    }
    entities.clear();

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            file >> grid[i][j];

            switch (grid[i][j]) {
                case 'P':
    entities.push_back(new Player(i, j));
    break;
case 'X':
    entities.push_back(new Enemy(i, j));
    break;
case '*':
    entities.push_back(new Collectible(i, j));
    break;
            }
        }
    }
    file.close();
}

void Maze::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename <<endl;
        return;
    }

    char tempGrid[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tempGrid[i][j] = grid[i][j];
        }
    }

    for (Entity* entity : entities) {
        tempGrid[entity->getX()][entity->getY()] = entity->getSymbol();
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            file << tempGrid[i][j];
        }
        file << '\n';
    }
    file.close();
}

void Maze::generateRandomMaze() {

    srand(time(0));


    for (Entity* entity : entities) {
        delete entity;
    }
    entities.clear();

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1) {
                grid[i][j] = '#';
            } else {

                grid[i][j] = (rand() % 10 < 3) ? '#' : ' ';
            }
        }
    }

    grid[1][1] = ' ';
    grid[SIZE-2][SIZE-2] = 'E';


    entities.push_back(new Player(1, 1));



    for (int i = 0; i < 5; ++i) {
        int x, y;
        do {
            x = 1 + rand() % (SIZE-2);
            y = 1 + rand() % (SIZE-2);
        } while (grid[x][y] != ' ' || (x == 1 && y == 1));

        entities.push_back(new Collectible(x, y));
    }


    for (int i = 0; i < currentLevel; ++i) {
        int x, y;
        do {
            x = 1 + rand() % (SIZE-2);
            y = 1 + rand() % (SIZE-2);
        } while (grid[x][y] != ' ' || (x == 1 && y == 1));
        entities.push_back(new Enemy(x, y));
    }
}

void Maze::display() const {
    system("cls");

    char tempGrid[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tempGrid[i][j] = grid[i][j];
        }
    }

    for (Entity* entity : entities) {
        tempGrid[entity->getX()][entity->getY()] = entity->getSymbol();
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << tempGrid[i][j];
        }
        cout << '\n';
    }

    cout << "\nLevel: " << currentLevel
              << " | Score: " << score
              << " | Moves: " << moves << "\n";
   cout << "WASD to move, Q to quit\n";

    if (gameOver) {
        cout << (gameWon ? "You won! Press R to restart.\n" : "Game Over! Press R to restart.\n");
    }
}

bool Maze::isValidMove(int x, int y) const {

    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && grid[x][y] != '#';
}

void Maze::movePlayer(char direction) {
    if (gameOver) return;

    Entity* player = nullptr;
    for (Entity* entity : entities) {
        if (entity->getSymbol() == 'P') {
            player = entity;
            break;
        }
    }
    if (!player) return;

    int dx = 0, dy = 0;
    switch (toupper(direction)) {
        case 'W': dx = -1; break;
        case 'A': dy = -1; break;
        case 'S': dx = 1; break;
        case 'D': dy = 1; break;
        default: return;
    }

    int newX = player->getX() + dx;
    int newY = player->getY() + dy;

    if (isValidMove(newX, newY)) {
        player->setPosition(newX, newY);
        moves++;

        for (auto it = entities.begin(); it != entities.end(); ) {
            if ((*it)->getSymbol() == '*' && (*it)->getX() == newX && (*it)->getY() == newY) {
                score += 10;
                delete *it;
                it = entities.erase(it);
            } else {
                ++it;
            }
        }

        if (grid[newX][newY] == 'E') {
            gameOver = true;
            gameWon = true;
        }
    }

    for (Entity* entity : entities) {
        if (entity->getSymbol() == 'X' &&
            entity->getX() == player->getX() &&
            entity->getY() == player->getY()) {
            gameOver = true;
            gameWon = false;
            break;
        }
    }

    moveEnemies();
}

void Maze::moveEnemies() {
    srand(time(0));
    for (Entity* entity : entities) {
        if (entity->getSymbol() == 'X') {

            int direction = rand() % 4;
            int dx = 0, dy = 0;
            switch (direction) {
                case 0: dx = -1; break;
                case 1: dx = 1; break;
                case 2: dy = -1; break;
                case 3: dy = 1; break;
            }

            int newX = entity->getX() + dx;
            int newY = entity->getY() + dy;

            if (isValidMove(newX, newY)) {
                entity->setPosition(newX, newY);
            }
        }
    }
}

void Maze::update() {

    Entity* player = nullptr;
    for (Entity* entity : entities) {
        if (entity->getSymbol() == 'P') {
            player = entity;
            break;
        }
    }

    if (player) {
        for (Entity* entity : entities) {
            if (entity->getSymbol() == 'X' &&
                entity->getX() == player->getX() &&
                entity->getY() == player->getY()) {
                gameOver = true;
                gameWon = false;
                break;
            }
        }
    }
}

void Maze::nextLevel() {
    currentLevel++;
    score += 50;
    moves = 0;
    gameOver = false;
    gameWon = false;
    generateRandomMaze();
}

void Maze::reset() {
    currentLevel = 1;
    score = 0;
    moves = 0;
    gameOver = false;
    gameWon = false;
    generateRandomMaze();
}
