#include "Robot.h"
#include "math.h"

// constructor
Robot::Robot(string r_name, int r_maxHP, int r_strength, int r_speed, int r_magic) 
	: Fighter(r_name, r_maxHP, r_strength, r_speed, r_magic)
{
	use_ability = false;
	maxEnergy = magic * 2;
	currEnergy = 0;
	bonusDamage = 0;
}

int Robot::getDamage()
{
	if (use_ability == false)
	{
		return strength;
	}
	else
	{
		use_ability = false;
		return strength + bonusDamage;
	}
}

void Robot::reset()
{
	currHP = maxHP;
	currEnergy = maxEnergy;
}

void Robot::regenerate()
{
	// Increases the fighter's current hit points by an amount equal to 
	//  one sixth of the fighter's strength.
	if (currHP < maxHP)
	{
		int incHP = strength*(1.0/6.0);
		if (incHP > 1)        // checks to make sure currHP does not exceed maxHP
			currHP += incHP;
		else                  // must increase HP by at least 1
			currHP++;

		if (currHP > maxHP)
			currHP = maxHP;
	}
}

bool Robot::useAbility()
{
	if (currEnergy >= ROBOT_ABILITY_COST)
	{
		double num = (double)currEnergy/(double)maxEnergy;
		num = pow(num, 4.0);
		num *= strength;
		bonusDamage = num;
		currEnergy -= ROBOT_ABILITY_COST;
		use_ability = true;
		return true;
	}
	return false;
}

// destructor
Robot::~Robot(void)
{
}
