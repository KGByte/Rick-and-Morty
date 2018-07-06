#ifndef THEPURGE_HPP
#define THEPURGE_HPP

#include "Space.hpp"
class ThePurge :
	public Space
{
private:
	bool levelPassed;
	int health;
public:
	ThePurge();
	~ThePurge();

	void spaceInfo();
	void navigateSpace();
	int attack();
	int getHealth();
	void setHealth(int);
};

#endif