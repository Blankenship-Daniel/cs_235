#ifndef BSTINTERFACE_H_
#define BSTINTERFACE_H_

#include "NodeInterface.h"

class BSTInterface {
public:
	BSTInterface() {}
	virtual ~BSTInterface() {}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	 * Returns the root node for this tree
	 *
	 * @return the root node for this tree.
	 */
	virtual NodeInterface * getRootNode() = 0;

	/*
	 * Attempts to add the given int to the BST tree
	 *
	 * @return true if added
	 * @return false if unsuccessful (i.e. the int is already in tree)
	 */
	virtual bool add(int data) = 0;

	/*
	 * Attempts to remove the given int from the BST tree
	 *
	 * @return true if successfully removed
	 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
	 */
	virtual bool remove(int data) = 0;
};

#endif