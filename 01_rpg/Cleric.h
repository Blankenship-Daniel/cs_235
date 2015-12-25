#ifndef CLERIC_H
#define CLERIC_H

#include "Fighter.h"

class Cleric : public Fighter
{
private:
	int mana;

public:
	Cleric(string c_name, int c_maxHP, int c_strength, int c_speed, int c_magic);
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();

	~Cleric(void);
};

#endif
