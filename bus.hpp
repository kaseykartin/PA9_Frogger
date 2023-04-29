#include "mobilegameobject.hpp"

class Bus : public MobileGameObject {

public:

	Bus(int x, int y); // Constructor that takes a starting position

	// Overridden abstract methods from MobileGameObject
	float generateSpeed();

};