#include "mobilegameobject.hpp"
#include "frog.hpp"

class Log : public MobileGameObject {

public:

	Log(int x, int y);

	bool check_frog(Frog& playerFrog);

	void update(Frog& playerFrog);

	// Overridden abstract methods from MobileGameObject
	float generateSpeed();
	sf::IntRect generateHitBox(); // Generate hitbox specific to log

	// Add getter and setter for _frogRideLog
	bool isFrogRidingLog() const { return _frogRideLog; }
	void setFrogRidingLog(bool value) { _frogRideLog = value; }
	

private:
	bool _frogRideLog;  // Track frog's log-riding status for this log
};