#ifndef FIGHTER_H
#define FIGHTER_H

#include "FighterInterface.h"

/*****************************************
 * FIGHTER
 * Defines a fighter either of type:
 *  (R)OBOT,
 *  (A)RCHER, or
 *  (C)LERIC
 ****************************************/
class Fighter : public FighterInterface
{
protected:
	string name;
	int maxHP;
	int currHP;
	int strength;
	int speed;
	int magic;

public:
	Fighter(string name, int maxHP, int strength, int speed, int magic); // constructor

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	virtual void reset() = 0;
	virtual void regenerate() = 0;
	virtual bool useAbility() = 0;
	virtual int getDamage() = 0;
	void takeDamage(int damage);

	// destructor
	~Fighter(void);
};

#endif
