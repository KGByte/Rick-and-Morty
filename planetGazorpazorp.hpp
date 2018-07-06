#ifndef PLANETGAZORPAZORP_HPP
#define PLANETGAZORPAZORP_HPP

#include "Space.hpp"
class planetGazorpazorp :
	public Space
{
private:
	bool levelPassed;
	int health;
public:
	planetGazorpazorp();
	~planetGazorpazorp();

	void spaceInfo();
	void navigateSpace();
	int attack();
	int getHealth();
	void setHealth(int);
};

#endif
