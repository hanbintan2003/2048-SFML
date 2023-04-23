#include <SFML/Graphics.hpp>
#include <ctime>
#include "includes/Game2048.h"
#include "includes/config/config.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Game2048 game;

    sf::RenderWindow window(sf::VideoMode(660, 660), "2048 Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window        .pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                bool moved = false;
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        moved = game.move(Direction::UP);
                        break;
                    case sf::Keyboard::Down:
                        moved = game.move(Direction::DOWN);
                        break;
                    case sf::Keyboard::Left:
                        moved = game.move(Direction::LEFT);
                        break;
                    case sf::Keyboard::Right:
                        moved = game.move(Direction::RIGHT);
                        break;
                    default:
                        break;
                }

                if (moved) {
                    game.addNewTile();
                }
            }
        }

        window.clear(sf::Color(200, 200, 200));

        game.draw(window,config.get_font(ARIAL));
        window.display();
    }

    return 0;
}

