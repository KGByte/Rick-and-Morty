#ifndef MICROVERSE_HPP
#define MICROVERSE_HPP

#include "Space.hpp"
class Microverse :
	public Space
{
private:
	bool levelPassed;
	int health;
public:
	Microverse();
	~Microverse();

	void spaceInfo();
	void navigateSpace();
	int attack();
	int getHealth();
	void setHealth(int);
};

#endif