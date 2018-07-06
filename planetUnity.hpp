#ifndef PLANETUNITY_HPP
#define PLANETUNITY_HPP

#include "Space.hpp"
class planetUnity :
	public Space
{
private:
	bool levelPassed;
	int health;
public:
	planetUnity();
	~planetUnity();

	void spaceInfo();
	void navigateSpace();
	int attack();
	int getHealth();
	void setHealth(int);
};

#endif
