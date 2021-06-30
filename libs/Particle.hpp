#ifndef VEHICLES_PARTICLE_H
#define VEHICLES_PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle : public Object {
public:
	Particle(const float x, const float y) : Object(x,y) {}

	std::unique_ptr<sf::Shape> getShape() override {
		auto circle = std::make_unique<sf::CircleShape>(20);
		circle->setFillColor(sf::Color::Red);
		circle->setPosition(position);
		return circle;
	}
};

class Particle2 : public Object {
public:
	Particle2(const float x, const float y) : Object(x,y) {}

	std::unique_ptr<sf::Shape> getShape() override {
		auto circle = std::make_unique<sf::CircleShape>(20);
		circle->setFillColor(sf::Color::Blue);
		circle->setPosition(position);
		return circle;
	}
};

#endif
