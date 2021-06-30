#include <cmath>
#include <numbers>

#include <VectorMath.hpp>

namespace vecmath {
	Vec2 i2f(const sf::Vector2i ivec) {
		return static_cast<Vec2>(ivec);
	}

	float rad2deg(const float rad) {
		return 180.0f / std::numbers::pi_v<float> * rad;
	}

	Vec2 normalized(const Vec2& vec) {
		return vec / magnitude(vec);
	}

	float magnitude(const Vec2& vec) {
		return std::sqrt(vec.x*vec.x + vec.y*vec.y);
	}

	Vec2 withMagnitude(const Vec2& vec, const float newMagnitude) {
		return normalized(vec) * newMagnitude;
	}

	float directionDeg(const Vec2& vec) {
		return rad2deg(std::atan2(vec.y, vec.x));
	}

	Vec2 limited(const Vec2& vec, const float maxMagnitude) {
		if (magnitude(vec) > maxMagnitude) {
			return withMagnitude(vec, maxMagnitude);
		}
		return vec;
	}
};
