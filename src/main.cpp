#include <SFML/Graphics.hpp>

// Components

// Entities

int main()
{

        // create the window
        sf::RenderWindow window(sf::VideoMode(640, 480), "Shape Visualizer");
        window.setFramerateLimit(60);

        ///////////////////////////////////////

        int window_W = window.getSize().x;
        int window_H = window.getSize().y;

        sf::Texture circleTexture;
        circleTexture.loadFromFile("../sprites/Circle-Sprite.png");
        sf::Sprite circle(circleTexture);
        circle.setColor(sf::Color(75, 255, 100, 255));
        sf::Vector2u size = circleTexture.getSize();
        circle.setOrigin(size.x / 2, size.y / 2);
        sf::Vector2f increment(0.8f, 0.8f);

        // sf::Clock deltaClock;
        //  run the program as long as the window is open
        while (window.isOpen())
        {
                // check all the window's events that were triggered since the last iteration of the loop
                sf::Event event;
                while (window.pollEvent(event))
                {

                        // "close requested" event: we close the window
                        if (event.type == sf::Event::Closed)
                                window.close();
                }

                // draw everything here...

                if ((circle.getPosition().x + (size.x / 2) >
                         window_W &&
                     increment.x > 0) ||
                    (circle.getPosition().x - (size.x / 2) < 0 &&
                     increment.x < 0))
                {
                        // reverse direction in axis X
                        increment.x = -increment.x;
                }
                if ((circle.getPosition().y + (size.y / 2) >
                         window_H &&
                     increment.y > 0) ||
                    (circle.getPosition().y - (size.y / 2) < 0 &&
                     increment.y < 0))
                {
                        // reverse direction in axis Y
                        increment.y = -increment.y;
                }

                circle.setPosition(circle.getPosition() + increment);

                // clear the window with black color
                window.clear(sf::Color::Black);
                window.draw(circle);

                // end the current frame
                window.display();
        }
}
