#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
	// create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	// create a circle
	sf::CircleShape circle;
	circle.setRadius(150);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5);

    // run the program as long as the window is open
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

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
		circle.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
        window.draw(circle);

        // end the current frame
        window.display();
	}

}
