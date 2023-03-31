#ifndef PROJECT_NAME_TILE_H
#define PROJECT_NAME_TILE_H


#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
    Tile();
    void setValue(int value);
    int getValue() const;
    bool isEmpty() const;
    void draw(sf::RenderWindow& window, const sf::Font& font, int x, int y, int size) const;

private:
    int value;
};



#endif //PROJECT_NAME_TILE_H
