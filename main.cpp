#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <World.hpp>
#include <Particle.hpp>
#include <Vehicle.hpp>

const float FPS = 30;

int main() {
	// create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	auto vehicle = std::make_shared<Vehicle>(100, 100);
	World world;
	world.objects.add(vehicle);

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

		vehicle->velocity = vecmath::i2f(sf::Mouse::getPosition(window)) - vehicle->position;
		world.perform_interactions();

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
		for (const auto& obj : world.objects) {
			window.draw(*obj->getShape());
		}

        // end the current frame
        window.display();
		sf::sleep(sf::seconds(1) / FPS);
	}

}
