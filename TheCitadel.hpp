#ifndef THECITADEL_HPP
#define THECITADEL_HPP

#include "Space.hpp"
class TheCitadel :
	public Space
{
private:
	bool levelPassed;
public:
	TheCitadel();
	~TheCitadel();

	void spaceInfo();
	void navigateSpace();
	int attack();
};

#endif
