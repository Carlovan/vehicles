/*
 * Define useful operations for working with 2D float vectors
 */
#ifndef VEHICLES_VECTORMATH_H
#define VEHICLES_VECTORMATH_H

#include <SFML/System/Vector2.hpp>

namespace vecmath {
	using Vec2 = sf::Vector2f;

	Vec2 i2f(const sf::Vector2i);

	/* Returns the angle (in degrees) of the vector to respect to the x-axis.
	 */
	float directionDeg(const Vec2&);
	
	/* Returns the normalized version of the given vector */
	Vec2 normalized(const Vec2&);

	/* Returns the magnitude of the given vector
	 */ 
	float magnitude(const Vec2&);

	/* Return a new vector with the same direction of the given one but the given magnitude */
	Vec2 withMagnitude(const Vec2&, const float magnitude);

	/* Returns a copy of the given vector with magnitude set to `maxMagnitude` if it was longer,
	 * untouched otherwise
	 */
	Vec2 limited(const Vec2&, const float maxMagnitude);
};


#endif
