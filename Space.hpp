#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath> //ceiling function
#include "Util.hpp"

//needed forward declaration for this
class Player;

class Space
{
protected:
	Space *left,
		  *right,
		  *top,
		  *bottom;
	Player *player;
	std::string name;
		
public:
	Space();
	Space(Space *, Space *, Space *, Space *);
	virtual ~Space();
	void setSpaces(Space *, Space *, Space *, Space *, Player *, std::string);

	//getters and setters
	std::string getName();
	Space* getLeft();
	Space* getRight();
	int rollFuncSpace(int, int);
	//virtuals
	virtual void spaceInfo() = 0;
	virtual void navigateSpace() = 0;
	virtual int attack() = 0;
	//virtual int attack() = 0;
};

#endif 