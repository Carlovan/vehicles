#ifndef VEHICLES_WORLD_H
#define VEHICLES_WORLD_H

#include <Object.hpp>
#include <Interaction.hpp>

class World {
public:
	ObjectsCollection objects;
	std::vector<std::unique_ptr<Interaction>> interactions;

	template<class T>
	requires std::is_base_of<Interaction, T>::value
	void add_interaction() {
		interactions.push_back(std::unique_ptr<Interaction>(new T()));
	}

	void perform_interactions() {
		for (auto& i : interactions) {
			i->perform(objects);
		}
	}
};

#endif
