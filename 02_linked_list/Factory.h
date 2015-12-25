#ifndef FACTORY_H
#define FACTORY_H

#include "LinkedListInterface.h"

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================

class Factory
{
	public:
		static LinkedListInterface<int>*    getLinkedListInt();
		static LinkedListInterface<string>* getLinkedListString();
		
};
//=======================================================================================

#endif
