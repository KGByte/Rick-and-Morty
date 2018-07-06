#include "ThePurge.hpp"
#include "Player.hpp"

ThePurge::ThePurge()
{
	this->levelPassed = false;
	this->health = 100;
}

ThePurge::~ThePurge()
{
}
void ThePurge::spaceInfo()
{
	cout << "Alright Morty, it's our first stop. Can't remember the name of this stupid planet but I came here drunk " << endl
		<< "awhile back and stumbled upon the zephyr poppy. This flower Morty, this flower can do a lot of things Morty! " << endl
		<< "For one, it will be needed for the antidote for your mother, and something else like cures all known diseases to " << endl
		<< "man Morty, but whatever lets just go. " << endl
		<< "What was that last part Rick? " << endl
		<< "Don't worry about it m m Morty just, lets just go little buddy. " << endl << endl;

}
void ThePurge::navigateSpace()
{
	std::string input;
	int roundCount = 0;
	//setHealth(100);
	//health = getHealth();

	if (!levelPassed)
	{
		spaceInfo();

		cout << "When cruising the spaceship at about 50 ft above the surface looking for a good landing spot, you spy " << endl
			<< "the inhabitants of the planet running around and killing each other! " << endl
			<< "Morty: What the hell is going on Rick! " << endl
			<< "Idk Morty lets find out, try and talk to one of these crazy people. " << endl << endl;

		cout << "You spy a lone survivor and decide to land next to him. " << endl
			<< "he immediately charges you with an axe! Luckily for you, Rick is skilled in the martial arts " << endl
			<< "and disarms him easily. What the hell is wrong with you! you ask. " << endl
			<< "Inhabitant: What do you mean? it's the purge! " << endl
			<< "Rick: The what?? " << endl
			<< "Inhabitant: Umm.. the purge? the one night where there are no laws and crime is penatly free! " << endl
			<< "it helps reduce crime overall, and makes our beautiful planet more peaceful. " << endl
			<< "Rick: Uhh yeah whatever, we are looking for the zephyr poppy, where can we find some. " << endl
			<< "Inhabitant: I got some over at my place! follow me. " << endl << endl;

		cout << "While walking to the persons house, you spy a band of about 20 purgers in the distance. " << endl
			<< "They see you, hold up their weapons, and charge! " << endl
			<< "Rick: Alright, let's have some fun Morty! Here take this lightsabre. " << endl
			<< "Morty: Rick where the hell did you get this!? " << endl
			<< "Rick: Umm, I'm a scientist, remember Morty? Don't embarass me again. Let's go! " << endl << endl;

		std::cout << "Choose your move based on the following selections. \n"
			<< "1. Fight with lightsabre\n"
			<< "2. Use portal gun.\n";

	}
	else
	{
		std::cout << "You have already beaten this level. " << std::endl;
	}

	while (!levelPassed)
	{

		int selection = getInt(input, 1, 3);
		switch (selection)
		{
		case 1:
		{
			std::cout << "You have chosen to fight! Let the battle begin! " << std::endl;
			while (getHealth() > 0 && player->getHealth() > 0)
			{
				health -= player->attack(roundCount);
				int gAtk = attack();
				player->defend(gAtk);
				std::cout << "Purgers attack with " << gAtk << " damage. " << std::endl;
				std::cout << "Rick and Morty's health after round " << roundCount << ": " << player->getHealth() << std::endl;
				std::cout << "Purgers health after round " << roundCount << ": " << health << std::endl;

				roundCount++;
			}
			break;
		}
		case 2:
			std::cout << "Don't you need to get the zephyr poppy still? " << std::endl;
			break;

		default:
			break;
		}

		if (getHealth() <= 0)
		{
			std::cout << "Congrats! You have defeated the Purgers, found the flower, and are ready to leave the purge planet! " << endl;
			player->addItem("Zephyr Poppy");
			levelPassed = true;
		}

		if (player->getHealth() <= 0)
		{
			std::cout << "You died! " << std::endl;
			levelPassed = true;
		}
	}
}
int ThePurge::attack()
{
	int mob = 0;
	//The mob attacks you, and damage is reduce based on the amount of people left
	mob = ceil(getHealth() / (float)30);
	int pAtk = rollFuncSpace(mob, 6);
	return pAtk;
}
int ThePurge::getHealth()
{
	return health;
}
void ThePurge::setHealth(int health)
{
	this->health = health;
}