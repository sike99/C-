#ifndef ENTITY_H
#define ENTITY_H

#include <utility>
using namespace std;

class Entity {
protected:
    char symbol;
    pair<int, int> position;

public:
    Entity(char sym, int x, int y) : symbol(sym), position({x, y}) {}
    virtual ~Entity() {}

    char getSymbol() const { return symbol; }
    pair<int, int> getPosition() const { return position; }
    int getX() const { return position.first; }
    int getY() const { return position.second; }

    void setPosition(int x, int y) { position = {x, y}; }
    virtual void move(int dx, int dy) = 0;
};

class Player : public Entity {
public:
    Player(int x, int y) : Entity('P', x, y) {}
    void move(int dx, int dy) override { setPosition(getX() + dx, getY() + dy); }
};

class Enemy : public Entity {
public:
    Enemy(int x, int y) : Entity('X', x, y) {}
    void move(int dx, int dy) override { setPosition(getX() + dx, getY() + dy); }
};

class Collectible : public Entity {
public:
    Collectible(int x, int y) : Entity('*', x, y) {}
    void move(int, int) override {}
};

#endif
