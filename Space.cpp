#include "Space.hpp"
#include "Player.hpp"

Space::Space()
{
	//std::cout << "calling space constructor... " << std::endl;
	this->left = NULL;
	this->right = NULL;
	this->top = NULL;
	this->bottom = NULL;
	this->name = "";
}

Space::~Space()
{

}

Space::Space(Space *left, Space *right, Space *top, Space *bottom)
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}


void Space::setSpaces(Space *left, Space *right, Space *top, Space *bottom, Player *player, std::string name)
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
	this->player = player;
	this->name = name;
}

std::string Space::getName()
{
	return this->name;
}
Space* Space::getLeft()
{
	if (this->left != NULL)
	{
		return this->left;
	}
	else
	{
		return NULL;
	}
}
Space* Space::getRight()
{
	if (this->right != NULL)
	{
		return this->right;
	}
	else
	{
		return NULL;
	}
}
//used for getting attacks of the space monsters
int Space::rollFuncSpace(int numRolls, int sides)
{
	int points = 0;
	for (int i = 0; i < numRolls; i++)
	{
		points += rand() % sides + 1;
	}
	return points;
}


