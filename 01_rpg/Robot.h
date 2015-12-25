#ifndef ROBOT_H
#define ROBOT_H

#include "Fighter.h"

class Robot : public Fighter
{
private:
	bool use_ability;
	int maxEnergy;
	int currEnergy;
	int bonusDamage;

public:
	Robot(string r_name, int r_maxHP, int r_strength, int r_speed, int r_magic);
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();

	~Robot(void);
};

#endif
