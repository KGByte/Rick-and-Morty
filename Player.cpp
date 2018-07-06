#include "Player.hpp"
#include "Space.hpp"

Player::Player()
{
	this->health = 100;
	this->pickleUsed = false;
	this->newMortyUsed = false;
	this->portalUsed = false;
}

Player::~Player()
{
}

Space* Player::getLocation()
{
	return this->location;
}
void Player::setLocation(Space *location)
{
	this->location = location;
}
int Player::getHealth()
{
	return health;
}
void Player::setHealth(int)
{
	this->health = health;
}
void Player::moveLeft()
{
	if (location->getLeft() != NULL)
	{
		std::cout << "Moving to the next world.." << std::endl;
		this->location = location->getLeft();

		std::cout << "You are now at: " << location->getName() << std::endl;
	}
	else
	{
		std::cout << "You are at the very beginning! You can't move farther left." << std::endl;
	}
}
void Player::moveRight()
{
	/*
	if (spaceSearch("Planet Unity") && enoughItems())
	{
		std::cout << "Moving to the next world.." << std::endl;
		this->location = location->getRight();

		std::cout << "You are now at: " << location->getName() << std::endl;
	}
	*/
	if (location->getRight() != NULL)
	{
		std::cout << "Moving to the next world.." << std::endl;
		this->location = location->getRight();

		std::cout << "You are now at: " << location->getName() << std::endl;
	}
	else
	{
		std::cout << "You are at the end! You can't move farther right." << std::endl;
	}
}

void Player::addItem(std::string items)
{
	this->gameItems.push_back(items);
}

//basically the same as attack function from project 3 and 4
int Player::rollFunc(int numRolls, int sides)
{
	int points = 0;
	for (int i = 0; i < numRolls; i++)
	{
		points += rand() % sides + 1;
	}
	return points;
}

//rick and morty have a standard attack as 2d6
int Player::attack(int rounds)
{
	int rickMortyAtk = 0;
	int choice = 0;
	std::string input;
	//int laserCount = 0;
	std::cout << "What kind of attack do you want to use? " << std::endl
		<< "1. Regular Attack: 2d6 dmg\n"
		<< "2. Ship lasers: 50dmg, can use every third round.\n"
		<< "3. Increase Intoxication: Chance to do double damage or zero damage. \n";

	choice = getInt(input, 1, 3);
	switch (choice)
	{
	case 1: 
		rickMortyAtk = rollFunc(2, 6);
		break;
	case 2:
		if (spaceSearch("The Council of Ricks"))
		{
			std::cout << "The ship is locked up! gonna be a normal attack. " << std::endl;
			rickMortyAtk = rollFunc(2, 6);
		}
		else if (spaceSearch("The Purge Planet"))
		{
			std::cout << "It's lightsabre battle time! No spaceship for this battle, commencing normal attack. " << std::endl;
			rickMortyAtk = rollFunc(2, 6);
		}
		else if (spaceSearch("The 'Microverse'"))
		{
			std::cout << "Can't use the ship cus you are inside its battery! commencing normal attack. " << std::endl;
			rickMortyAtk = rollFunc(2, 6);
		}
		else
		{
			if (rounds % 3 == 0)
			{
				rickMortyAtk = specialShipLasers();
			}
			else
			{
				std::cout << "Lasers in cooldown, Commencing regular attack. " << std::endl;
				rickMortyAtk = rollFunc(2, 6);
			}
		}
		break;
	case 3:
		rickMortyAtk = increaseIntoxication();
		break;
	default:
		break;
	}

	std::cout << "Rick and Morty attack with " << rickMortyAtk << " damage! " << endl;
	return rickMortyAtk;
}
//rick is sly and cunning, he dodges a lot. Morty on the other hand, not so much.
//still tho, enemies have a 10% chance of actually inflicting damage on rick and morty.
void Player::defend(int damage)
{
	int damageInflicted = 0;

	//random numbers from 1 to 100
	damageInflicted = (rand() % 100) + 1;

	//10% of the time he gets hit
	if (damageInflicted <= 20)
	{
		health -= damage;
	}
	else
	{
		std::cout << "Rick and Morty evaded the attack. " << std::endl;
	}

	if (health < 0)
	{
		setHealth(0);
	}
}

//when Rick drinks liquor, he either focuses better or becomes more beligerant. 
//meaning he can either inflict a lot of damage or miss his attack cus hes drunk
int Player::increaseIntoxication()
{
	int chance = 0;
	int drunkDamage = 0;
	//50% chance to do good damage or miss
	chance = (rand() % 2) + 1;

	switch (chance)
	{
	case 1: 
		std::cout << "The liquor worked in your favor! up to 2x damage! " << std::endl;
		drunkDamage = rollFunc(4, 6);
		break;
	case 2:
		std::cout << "Too drunk! you missed. " << std::endl;
		drunkDamage = 0;
		break;
	}
	return drunkDamage;
}
//rick uses his portal gun to travel everywhere. Activating this special allows you to travel to the next space without 
//doing anything, and you also collect the object. He's just that good. 
void Player::specialPortalGun()
{
	std::cout << "Current location: " << getLocation()->getName() << std::endl;
	setLocation(location->getRight());
	std::cout << "New location: " << getLocation()->getName() << std::endl;
	portalUsed = true;
}
//Rick can call in his ship to come to the rescue. His ship is pretty smart.
//There will be good times to use this skill
int Player::specialShipLasers()
{
	return 50;
}
//we all know most Ricks go through plenty of Morty's
//if rick and morty's health goes below 50, rick can buy a 
//brand new morty and increase their health
void Player::specialBuyNewMorty()
{
	if (getHealth() >= 50)
	{
		std::cout << "Your Morty is still alive. " << std::endl;
		newMortyUsed = false;
	}

	else
	{
		std::cout << "Health before buying new Morty: " << getHealth() << std::endl;
		health += 50;
		setHealth(100);

		std::cout << "Health after buying new Morty: " << getHealth() << std::endl;
		newMortyUsed = true;
	}
}
//Rick is infamous for doing crazy things just because.
//Rick can turn himself into a pickle and this does absolutely nothing,
//except now he is a pickle
void Player::pickleRick()
{
	std::cout << "Rick is now a pickle. " << std::endl;
	pickleUsed = true;
	//call pickle picture function
}
bool Player::pickleRickUsed()
{
	return pickleUsed;
}
bool Player::portalGunUsed()
{
	return portalUsed;
}
bool Player::buyNewMortyUsed()
{
	return newMortyUsed;
}
bool Player::spaceSearch(std::string area)
{
	for (int i = 0; i < location->getName().size(); i++) 
	{
		if (location->getName() == area)
		{
			return true;
		}
	}

	return false;
}
int Player::pickleRickAttack()
{
	int rickMortyAtk = 0;
	int choice = 0;
	std::string input;
	//int laserCount = 0;
	std::cout << "What kind of attack do you want to use? " << std::endl
		<< "1. Regular Attack: 1d6 dmg\n"
		<< "2. Increase Intoxication : Chance to do double damage or zero damage. \n";

	choice = getInt(input, 1, 3);
	switch (choice)
	{
	case 1:
		rickMortyAtk = rollFunc(1, 6);
		break;
	case 2:
		rickMortyAtk = increaseIntoxication();
		break;
	default:
		break;
	}

	std::cout << "Rick and Morty attack with " << rickMortyAtk << " damage! " << endl;
	return rickMortyAtk;
}
void Player::getItems()
{
	if (gameItems.size() == 0)
	{
		std::cout << "You have no items so far. " << std::endl;
	}
	else
	{
		for (int i = 0; i < gameItems.size(); i++)
		{
			std::cout << "Acquired Items: " << std::endl;
			std::cout << i + 1 << ": " << gameItems[i] << std::endl;
		}
	}
	//cout << i + 1 << ": " << menuHold[i] << endl;
}
bool Player::enoughItems()
{
	if (gameItems.size() == 2)
	{
		return true;
	}
	else
	{
		std::cout << "You don't have enough items to enter the last world. " << std::endl;
		std::cout << "You need to go back and find the remaining items first. " << std::endl;
		return false;
	}
}

bool Player::enoughItemsToWin()
{
	if (gameItems.size() == 3)
	{
		return true;
	}
}

void Player::clearItems()
{
	gameItems.clear();
}