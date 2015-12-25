#include "Cleric.h"


Cleric::Cleric(string c_name, int c_maxHP, int c_strength, int c_speed, int c_magic) 
	: Fighter(c_name, c_maxHP, c_strength, c_speed, c_magic)
{
	mana = 0;
}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	currHP = maxHP;
	mana = magic * 5;
}

// regenerate
void Cleric::regenerate()
{
	// Increases the fighter's current hit points by an amount equal to 
	//  one sixth of the fighter's strength.
	if (currHP < maxHP)
	{
		int incHP = strength*(1.0/6.0);
		if (incHP > 1)       // checks to make sure currHP does not exceed maxHP
			currHP += incHP;
		else                 // must increase HP by at least 1
			currHP ++;
		if (currHP > maxHP)
			currHP = maxHP;
	}

	// Also increases a Cleric's current mana by an amount equal to one fifth of the Cleric's magic.
	if (mana < (magic*5))
	{
		int incMana = magic*(1.0/5.0);
		if (incMana > 1)     // checks to make sure mana does not exceed magic
			mana += incMana;
		else                 // must increase mana by at least 1;
			mana++;
		if (mana > (magic*5))
			mana = magic;
	}
}

/*	Cleric: Healing Light
*	Increases the Cleric's current hit points by an amount equal to one third of its magic.
*	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
*	Will be used even if the Cleric's current HP is equal to their maximum HP.
*	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
*	Cleric Note:
*	This ability, when successful, must increase the Cleric's current hit points 
*	by at least one.  Do not allow the current hit points to exceed the maximum 
*	hit points.
*
*	Return true if the ability was used; false otherwise.
*/
bool Cleric::useAbility()
{
	if (mana >= CLERIC_ABILITY_COST)
	{
		int incHP = magic*(1.0/3.0);
		if (incHP > 1)
			currHP += incHP;
		else
			currHP++;

		if (currHP > maxHP)
			currHP = maxHP;

		mana -= CLERIC_ABILITY_COST;

		return true;
	}
	return false;
}

Cleric::~Cleric(void)
{
}
