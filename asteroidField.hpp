#ifndef	ASTEROIDFIELD_HPP
#define ASTEROIDFIELD_HPP

#include "Space.hpp"


class asteroidField :
	public Space
{
private:
	bool levelPassed;
	//std::string 

public:
	asteroidField();
	~asteroidField();

	void spaceInfo();
	void navigateSpace();
	int attack();
	
};

#endif

