#ifndef VEHICLES_INTERACTION_H
#define VEHICLES_INTERACTION_H

#include <Object.hpp>

class Interaction {
public:
	virtual void perform(const ObjectsCollection& objects) = 0;
};

template<class A, class B>
class BaseInteraction : public Interaction {
protected:
	virtual void interact(A& a, B& b) = 0;
public:
	void perform(const ObjectsCollection& objects) final {
		auto aObjects = objects.byType<A>();
		auto bObjects = objects.byType<B>();
		if (aObjects && bObjects) {
			for (auto aObj : (*aObjects).get()) {
				for (auto bObj : (*bObjects).get()) {
					interact(dynamic_cast<A&>(*aObj), dynamic_cast<B&>(*bObj));
				}
			}
		}
	}
};

#endif
