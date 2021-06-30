#ifndef VEHICLES_VEHICLE_H
#define VEHICLES_VEHICLE_H

#include <Object.hpp>
#include <VectorMath.hpp>

/*
 * This vehicle model is heavily inspired by http://www.red3d.com/cwr/steer/gdc99/
 */
class Vehicle : public Object {
	const float maxSpeed = 5;
	const float maxForce = 1;


public:
	Vehicle(const float x, const float y);

	/* void update() override; */
	void applyForce(vecmath::Vec2);

	std::unique_ptr<sf::Shape> getShape() const override;

public:
	vecmath::Vec2 velocity{0,0};
};

#endif
