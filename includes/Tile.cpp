#include "Tile.h"
#include <sstream>

Tile::Tile() : value(0) {}

void Tile::setValue(int value) {
    this->value = value;
}

int Tile::getValue() const {
    return value;
}

bool Tile::isEmpty() const {
    return value == 0;
}

void Tile::draw(sf::RenderWindow& window, const sf::Font& font, int x, int y, int size) const {
    if (isEmpty()) return;

    sf::RectangleShape shape(sf::Vector2f(size - 4, size - 4));
    shape.setFillColor(sf::Color(255, 255, 255));
    shape.setPosition(x + 2, y + 2);
    window.draw(shape);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    std::ostringstream oss;
    oss << value;
    text.setString(oss.str());
    text.setPosition(x + (size - text.getGlobalBounds().width) / 2, y + (size - text.getGlobalBounds().height) / 2);
    window.draw(text);
}

