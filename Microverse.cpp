#include "Microverse.hpp"
#include "Player.hpp"

Microverse::Microverse()
{
	this->health = 100;
	this->levelPassed = false;
}


Microverse::~Microverse()
{
}

void Microverse::spaceInfo()
{
	cout << "You are preparing to leave the purge planet when the spaceship decides not to start. " << endl
		<< "What now Rick?? What's going on? " << endl
		<< "Quiet Morty! The battery is dead, we gotta go inside. " << endl
		<< "We gotta what? " << endl << endl;

	cout << "You are teleported into the spaceship battery! " << endl
		<< "Upon arrival, Rick explains that he was tired of buying new batteries, so he created a tiny " << endl
		<< "universe that acts as his spaceship battery. He calls it the Microverse. " << endl << endl;

	cout << "Isn't it great Morty? I gave them the technology to make electrcity, but in reality " << endl
		<< "they are making it to power the ship's battery! " << endl
		<< "Idk Rick, sounds like slavery with benefits to me. " << endl
		<< "What do you know anyways Morty! " << endl;

}
void Microverse::navigateSpace()
{
	std::string input;
	int roundCount = 0;
	//setHealth(100);
	//health = getHealth();

	if (!levelPassed)
	{
		spaceInfo();

		cout << "You are greeted by the Prime Minister of the Microverse, who doesn't know he actually lives in " << endl
			<< "a battery, but thinks Rick is a god that brought them the power of electricity. " << endl
			<< "PM: Welcome back Rick! Good to see you again! " << endl
			<< "Rick: Yeah yeah greetings whatever, why aren't you making electricity? " << endl
			<< "PM: We have made a great discovery! Our most talented scientist has been working on another way to harness electricty! " << endl
			<< "Rick: Another way? But why, I gave you everything you needed! " << endl
			<< "PM: Just come with me, I'll show you the great discovery. " << endl;

		cout << "You follow the Prime Minister and he introduces you to the best scientist on the planet. " << endl
			<< "Turns out, the scientist has created what he calls a Miniverse, which is very similar " << endl
			<< "to the Microverse that you are currently in (that they still don't know about). " << endl
			<< "Rick, unhappy with this finding, decides to drop the bomb that he created their universe to power his spaceship. " << endl
			<< "This doesn't go well, and the scientist and prime minister become very angry and want to fight. " << endl
			<< "Looks like you will need to prepare to take on the scientist. Genius vs Genius round 1: GO! " << endl;

		std::cout << "Choose your move based on the following selections. \n"
			<< "1. Fight\n"
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
				int scientistAtk = attack();
				player->defend(scientistAtk);
				std::cout << "Scientist attack with " << scientistAtk << " damage. " << std::endl;
				std::cout << "Rick and Morty's health after round " << roundCount << ": " << player->getHealth() << std::endl;
				std::cout << "Scientist health after round " << roundCount << ": " << health << std::endl;

				roundCount++;
			}
			break;
		}
		case 2:
			std::cout << "You need to defeat the scientist so you can tell the people to keep making electricity! " << std::endl;
			break;

		default:
			break;
		}

		if (getHealth() <= 0)
		{
			std::cout << "Congrats! You have defeated the Scientist, convinced the people to " << std::endl
				<< "keep making electricity, and can now continue on with your quest! " << std::endl;
			levelPassed = true;
		}
		if (player->getHealth() <= 0)
		{
			std::cout << "You died! " << std::endl;
			levelPassed = true;
		}
	}
}
int Microverse::attack()
{
	int sciAtk = rollFuncSpace(2, 6);
	return sciAtk;
}

int Microverse::getHealth()
{
	return health;
}
void Microverse::setHealth(int health)
{
	this->health = health;
}