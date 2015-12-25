#include "Fighter.h"

// constructor
Fighter::Fighter(string name, int maxHP, int strength, int speed, int magic)
{
	this->name = name;
	this->maxHP = maxHP;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
	this->currHP = 0;
}

// destructor
Fighter::~Fighter(void)
{
}

// get name
string Fighter::getName()
{
	return name;
}

// get max hp
int Fighter::getMaximumHP()
{
	return maxHP;
}

// get current hp
int Fighter::getCurrentHP()
{
	return currHP;
}

// get strength
int Fighter::getStrength()
{
	return strength;
}

// get speed
int Fighter::getSpeed()
{
	return speed;
}

// get magic
int Fighter::getMagic()
{
	return magic;
}

/*
*	takeDamage(int)
*
*	Reduces the fighter's current hit points by an amount equal to the given 
*	damage minus one fourth of the fighter's speed.  This method must reduce 
*	the fighter's current hit points by at least one.  It is acceptable for 
*	this method to give the fighter negative current hit points.
*
*	Examples:
*		damage=10, speed=7		=> damage_taken=9
*		damage=10, speed=9		=> damage_taken=8
*		damage=10, speed=50		=> damage_taken=1
*/
void Fighter::takeDamage(int damage)
{
	damage -= speed/4;

	if (damage > 1)
		currHP -= damage;
	else
		currHP--;
}





