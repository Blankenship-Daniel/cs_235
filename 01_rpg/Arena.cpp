#include "Arena.h"
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"
#include <sstream>
#include <stdlib.h>

// constructor
Arena::Arena(void)
{
	size = 0;
}

// destructor
Arena::~Arena(void)
{
}

// add fighter
bool Arena::addFighter(string info)
{
	stringstream ss;             // to be able to read each element into individual strings
	string fighterElement;       // holds each piece of the info string
	vector<string> fighterInfo;  // hold all info concerning a new player

	// check to see if any value
	for (int i = 0; i < info.length(); i++)
		if (info[i] == '.')
			return false;
			
	ss.str(info);

	// continue to add a new element to the fighterInfo vector
	//  until the end of the string
	while (ss >> fighterElement)
		fighterInfo.push_back(fighterElement);

	// checks to see if the info string submitted is in the correct format
	if (fighterInfo.size() != 6)
		return false; // return false if it is not

	string name  = fighterInfo[0];
	int maxHP    = atoi(fighterInfo[2].c_str());
	int strength = atoi(fighterInfo[3].c_str());
	int speed    = atoi(fighterInfo[4].c_str());
	int magic    = atoi(fighterInfo[5].c_str());

	// check for duplicate fighters
	for (int i = 0; i < fighters.size(); i++)
		if (name == fighters[i]->getName())
			return false;

	// check for non positive input
	if (maxHP <= 0 || strength <= 0 || speed <= 0 || magic <= 0)
		return false;

	if (fighterInfo[1] == "R")      // type Robot
	{
		fighters.push_back(new Robot(name, maxHP, strength, speed, magic)); // add a fighter of type Robot to the arena
		//cerr << "Robot added" << endl;
	}
	else if (fighterInfo[1] == "A") // type Archer
	{
		fighters.push_back(new Archer(name, maxHP, strength, speed, magic)); // add a fighter of type archer to the arena
		//cerr << "Archer added" << endl;
	}
	else if (fighterInfo[1] == "C") // type Cleric
	{
		fighters.push_back(new Cleric(name, maxHP, strength, speed, magic)); // add a fighter of type cleric to the arena
		//cerr << "Cleric added" << endl;
	}
	else
		return false;

	size++;
	return true;
}

// remove fighter
bool Arena::removeFighter(string name)
{
	for (int i = 0; i < fighters.size(); i++)
	{
		if (name == fighters.at(i)->getName())
		{
			fighters.erase(fighters.begin() + i);
			size--;
			return true;
		}
	}
	return false;
}

// FighterInterface getFighter
FighterInterface* Arena::getFighter(string name)
{
	for (int i = 0; i < fighters.size(); i++)
	{
		if (name == fighters.at(i)->getName())
		{
			return fighters.at(i);
		}
	}
	return NULL;
}

// get size
int Arena::getSize()
{
	return size;
}
