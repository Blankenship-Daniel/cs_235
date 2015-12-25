#ifndef ARENA_H
#define ARENA_H

#include "ArenaInterface.h"
#include "FighterInterface.h"
#include "Fighter.h"

class Arena : public ArenaInterface
{
private:
	int size;
	vector<Fighter*> fighters;

public:
	Arena(); // Arena constructor
	
	bool addFighter(string info); 
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();

	// destructor
	~Arena();
};

#endif
