#include "planetGazorpazorp.hpp"
#include "Player.hpp"

planetGazorpazorp::planetGazorpazorp()
{
	//std::cout << "Calling gazorpazorp constructor... " << std::endl;
	this->health = 100;
	levelPassed = false;
}

planetGazorpazorp::~planetGazorpazorp()
{
}

void planetGazorpazorp::spaceInfo()
{
	std::cout << "Alright Morty, narrow escape from the asteroid field, but we are finally at planet Gazorpazorp. " << std::endl
		<< "WHAT?!? What are we doing here Rick? Don't you remember what happened last time? You and Summer were almost executed. " << std::endl
		<< "Yeah yeah yeah Morty, real sidekick you are, j j j just complaining about everything. " << std::endl
		<< "But Rick! " << std::endl
		<< "Enough Morty! We need to sotp here, their planet is the only place that grows the Excaliber Flower, I need it for the antidote. " << std::endl;
	std::cout << "\n\n";
}
void planetGazorpazorp::navigateSpace()
{
	std::string input;
	//int gazorpazorpHealth = 100;
	int roundCount = 0;
	setHealth(100);
	health = getHealth();

	if (!levelPassed)
	{
		spaceInfo();

		std::cout << "Rick and Morty land safely on Gazorpazorp world and are immediately encountered by their leader. " << std::endl
			<< "Leader: What are YOU doing here again? " << std::endl
			<< "Rick: Relax lady I need something from your planet then I'm out. " << std::endl
			<< "Leader: I don't think so! Sick em gazorpazorps! " << std::endl
			<< "The leader of the planet has sent the wild gazorpazorps (Giant strong beasts) on you and it looks like you are doing to have to fight. " << std::endl
			<< "Be careful, the more Gazorpazorps there are, the stronger they are. " << std::endl;

		std::cout << "Choose your move based on the following selections. \n"
			<< "1. Fight\n"
			<< "2. Use portal gun.\n"
			<< "3. Turn into a pickle. You don't know if this is good or bad, only one way to find out.\n";
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
			std::cout << "You have chosen to fight! " << std::endl;
			while (getHealth() > 0 && player->getHealth() > 0)
			{
				health -= player->attack(roundCount);
				int gAtk = attack();
				player->defend(gAtk);
				std::cout << "Gazorpazoprs attack with " << gAtk << " damage. " << std::endl;
				std::cout << "Rick and Morty's health after round " << roundCount << ": " << player->getHealth() << std::endl;
				std::cout << "Gazorpazorps health after round " << roundCount << ": " << health << std::endl;

				roundCount++;
			}
			break;
		}
		case 2:
			if (player->portalGunUsed())
			{
				std::cout << "Portal Gun has only 1 charge! Can't use it. " << endl;
			}
			else
			{
				std::cout << "Let's get out of here Morty! " << std::endl;
				std::cout << "You grab the flower and teleport away. " << std::endl;
				player->addItem("Excaliber Flower");
				player->specialPortalGun();
				levelPassed = true;
			}
			break;
		case 3:
			player->pickleRick();
			std::cout << "Apparently Gazorpazorps hate pickles! you lucked out on this one. " << std::endl;
			std::cout << "They run away and leave you alone. Now you have time to grab the flower and leave." << std::endl;
			player->addItem("Excaliber Flower");
			levelPassed = true;
		default:
			break;
		}

		if (getHealth() <= 0)
		{
			std::cout << "Congrats! You have defeated the Gazorpazorps, found the flower, and esacped planet Gazorpazorp. " << endl;
			player->addItem("Excaliber Flower");
			levelPassed = true;
		}
		if (player->getHealth() <= 0)
		{
			std::cout << "You died! " << std::endl;
			levelPassed = true;
		}
	}
}

int planetGazorpazorp::attack()
{
	int swarm = 0;
	
	//gazorpazops lose attack damage based on how many there are
	swarm = ceil(getHealth() / (float)20);
	int gAtk = rollFuncSpace(swarm, 6);
	return gAtk;
}
int planetGazorpazorp::getHealth()
{
	return health;
}
void planetGazorpazorp::setHealth(int health)
{
	this->health = health;
}