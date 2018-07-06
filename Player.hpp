#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

class Space;

class Player
{
protected:
	Space *location;
	std::vector<std::string> gameItems;
	int health;
	std::string name;
	bool pickleUsed;
	bool newMortyUsed;
	bool portalUsed;
public:
	Player();
	~Player();
	//setters and getters
	Space* getLocation();
	void setLocation(Space *);
	int getHealth();
	void setHealth(int);
	void getItems();

	//movers
	void moveLeft();
	void moveRight();
	void addItem(std::string);

	//player characteristics
	int rollFunc(int, int);
	int attack(int);
	void defend(int);

	//thinking about adding these to the attack function. Or at least some of them
	int increaseIntoxication();
	void specialPortalGun();
	int specialShipLasers();
	void specialBuyNewMorty();
	void pickleRick();
	bool portalGunUsed();
	bool buyNewMortyUsed();
	bool pickleRickUsed();
	bool spaceSearch(std::string);
	int pickleRickAttack();
	bool enoughItems();
	bool enoughItemsToWin();
	void clearItems();


};

#endif
