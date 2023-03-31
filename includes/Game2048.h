#ifndef PROJECT_NAME_GAME2048_H
#define PROJECT_NAME_GAME2048_H


#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Direction.h"

class Game2048 {
public:
    Game2048();
    bool move(Direction direction);
    void addNewTile();
    void draw(sf::RenderWindow& window, const sf::Font& font) const;

private:
    Tile grid[4][4];
    int gridSize;

    void rotateGrid();
    void moveRow(int row);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};



#endif //PROJECT_NAME_GAME2048_H
