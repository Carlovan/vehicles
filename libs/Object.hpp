#ifndef VEHICLES_OBJECT_H
#define VEHICLES_OBJECT_H

#include <unordered_map>
#include <vector>
#include <memory>
#include <typeinfo>
#include <typeindex>
#include <ranges>
#include <optional>

#include <SFML/Graphics.hpp>

class Object {
public:
	sf::Vector2f position;

	Object(const float x, const float y) : position{x, y} {}

	virtual std::unique_ptr<sf::Shape> getShape() = 0;
};


class ObjectsCollection {
	using value_type = std::shared_ptr<Object>;
	std::unordered_map<std::type_index, std::vector<value_type>> objects;

	auto flatView() {
		return objects | std::views::elements<1> | std::views::join;
	}
	
public:
	auto begin() {
		return flatView().begin();
	}
	auto end() {
		return flatView().end();
	}

	template<class T>
	requires std::is_base_of<value_type::element_type, T>::value
	void add(std::shared_ptr<T> obj) {
		objects[std::type_index(typeid(T))].push_back(obj);
	}

	// Returns true if the object was found and removed
	template<class T>
	requires std::is_base_of<value_type::element_type, T>::value
	bool remove(std::shared_ptr<T> obj) {
		auto index = std::type_index(typeid(T));
		if (!objects.contains(index))
			return false;
		if(auto found = std::ranges::find(objects[index], obj); found != objects[index].end()) {
			std::swap(*found, *objects[index].rbegin());
			objects[index].pop_back();
			return true;
		}
		return false;
	}

	template<class T>
	requires std::is_base_of<value_type::element_type, T>::value
	auto byType() const {
		return byType(std::type_index(typeid(T)));
	}
	auto byType(std::type_index index) const {
		return objects.contains(index) ? std::make_optional(std::ref(objects.at(index))) : std::nullopt;
	}
};

#endif
