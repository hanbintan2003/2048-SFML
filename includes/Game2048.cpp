#include "Game2048.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Game2048::Game2048() : gridSize(4) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            grid[i][j] = Tile();
        }
    }
    addNewTile();
    addNewTile();
}

bool Game2048::move(Direction direction) {
    switch (direction) {
        case Direction::UP:
            moveUp();
            break;
        case Direction::DOWN:
            moveDown();
            break;
        case Direction::LEFT:
            moveLeft();
            break;
        case Direction::RIGHT:
            moveRight();
            break;
    }
    return true;
}

void Game2048::addNewTile() {
    int x, y;
    do {
        x = std::rand() % gridSize;
        y = std::rand() % gridSize;
    } while (!grid[x][y].isEmpty());

    grid[x][y].setValue((std::rand() % 2 + 1) * 2
);
}

void Game2048::draw(sf::RenderWindow& window, const sf::Font& font) const {
    int tileSize = 150;
    int margin = 10;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            int x = i * (tileSize + margin) + margin;
            int y = j * (tileSize + margin) + margin;
            grid[i][j].draw(window, font, x, y, tileSize);
        }
    }
}


void Game2048::rotateGrid() {
    Tile temp[4][4];
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            temp[i][j] = grid[gridSize - j - 1][i];
        }
    }
    std::memcpy(grid, temp, sizeof(grid));
}

void Game2048::moveRow(int row) {
    int prevCol = 0;
    for (int col = 1; col < gridSize; ++col) {
        if (grid[row][col].isEmpty()) continue;
        if (grid[row][prevCol].isEmpty() || grid[row][prevCol].getValue() == grid[row][col].getValue()) {
            grid[row][prevCol].setValue(grid[row][prevCol].getValue() + grid[row][col].getValue());
            grid[row][col].setValue(0);
            prevCol += (grid[row][prevCol].getValue() != 0);
        } else if (grid[row][prevCol + 1].isEmpty()) {
            grid[row][prevCol + 1].setValue(grid[row][col].getValue());
            if (col != prevCol + 1) grid[row][col].setValue(0);
        } else {
            prevCol++;
            if (col != prevCol) {
                grid[row][prevCol].setValue(grid[row][col].getValue());
                grid[row][col].setValue(0);
            }
        }
    }
}

void Game2048::moveUp() {
    for (int col = 0; col < gridSize; ++col) {
        for (int row = 0; row < gridSize; ++row) {
            moveRow(row);
        }
    }
}

void Game2048::moveDown() {
    rotateGrid();
    rotateGrid();
    moveUp();
    rotateGrid();
    rotateGrid();
}

void Game2048::moveLeft() {
    rotateGrid();
    rotateGrid();
    rotateGrid();
    moveUp();
    rotateGrid();
}

void Game2048::moveRight() {
    rotateGrid();
    moveUp();
    rotateGrid();
    rotateGrid();
    rotateGrid();
}

