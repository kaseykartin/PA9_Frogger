#include "mobilegameobject.hpp"

class Car : public MobileGameObject {

public:

	Car(int x, int y); // Constructor that takes a starting position

	// Overridden abstract methods from MobileGameObject
	float generateSpeed(); 
	//sf::IntRect setHitBox() override;

};

