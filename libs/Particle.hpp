#ifndef VEHICLES_PARTICLE_H
#define VEHICLES_PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle : public Object {
public:
	Particle(const float x, const float y) : Object(x,y) {}

	std::unique_ptr<sf::Shape> getShape() const override {
		auto circle = std::make_unique<sf::CircleShape>(20);
		circle->setFillColor(sf::Color::Red);
		circle->setPosition(position);
		circle->setOrigin(circle->getRadius(), circle->getRadius());
		return circle;
	}
};

class Particle2 : public Object {
public:
	Particle2(const float x, const float y) : Object(x,y) {}

	std::unique_ptr<sf::Shape> getShape() const override {
		auto circle = std::make_unique<sf::CircleShape>(30);
		circle->setFillColor(sf::Color::Blue);
		circle->setPosition(position);
		circle->setOrigin(circle->getRadius(), circle->getRadius());
		return circle;
	}
};

class ParticlesInteraction : public BaseInteraction<Particle, Particle2> {
protected:
	void interact(Particle& a, Particle2& b) override final {
		const auto diff = b.position - a.position;
		a.position += diff / 10.0f;
	}
};

#endif
