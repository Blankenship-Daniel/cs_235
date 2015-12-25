#include "Archer.h"

// constructor
Archer::Archer(string a_name, int a_maxHP, int a_strength, int a_speed, int a_magic)
	: Fighter(a_name, a_maxHP, a_strength, a_speed, a_magic)
{
	currSpeed = 0;
}

int Archer::getDamage()
{
	return currSpeed;
}

int Archer::getSpeed()
{
	return currSpeed;
}

void Archer::reset()
{
	currHP = maxHP;
	currSpeed = speed;
}

void Archer::takeDamage(int damage)
{
	damage -= currSpeed/4;

	if (damage > 1)
		currHP -= damage;
	else
		currHP--;
}

void Archer::regenerate()
{
	// Increases the fighter's current hit points by an amount equal to 
	//  one sixth of the fighter's strength.
	if (currHP < maxHP)
	{
		int incHP = strength*(1.0/6.0);
		if ((currHP + incHP) < maxHP && incHP > 1) // checks to make sure currHP does not exceed maxHP
		{
			currHP += incHP;
		}
		else if ((currHP + incHP) < maxHP && incHP < 1) // must increase HP by at least 1
		{
			currHP += 1;
		}
		if (currHP > maxHP)
			currHP = maxHP;
	}
}

bool Archer::useAbility()
{
	currSpeed++;
	return true;
}

// destructor
Archer::~Archer(void)
{
}
