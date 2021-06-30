#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Color.hpp>

#include <Vehicle.hpp>

Vehicle::Vehicle(const float x, const float y) : Object(x, y) {}

void update() {}
void applyForce(vecmath::Vec2) {}

std::unique_ptr<sf::Shape> Vehicle::getShape() const {
	const int size = 20;
	auto shape = std::make_unique<sf::ConvexShape>(3);
	shape->setPoint(0, {0,0});
	shape->setPoint(1, {-size, size/2});
	shape->setPoint(2, {-size, -size/2});
	shape->setFillColor(sf::Color::White);
	shape->setPosition(position);
	shape->setRotation(vecmath::directionDeg(velocity));
	return shape;
}
