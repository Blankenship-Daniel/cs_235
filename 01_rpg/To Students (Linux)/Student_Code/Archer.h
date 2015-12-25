#ifndef ARCHER_H
#define ARCHER_H

#include "Fighter.h"

class Archer : public Fighter
{
private:
	int currSpeed;

public:
	Archer(string a_name, int a_maxHP, int a_strength, int a_speed, int a_magic);
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
	void takeDamage(int damage);
	int getSpeed();

	~Archer(void);
};

#endif
