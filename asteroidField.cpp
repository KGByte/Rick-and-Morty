#include "asteroidField.hpp"
#include "Player.hpp"

asteroidField::asteroidField()
{
//	std::cout << "Calling asteroid field constructor... " << std::endl;
	this->levelPassed = false;
}


asteroidField::~asteroidField()
{
}

void asteroidField::spaceInfo()
{
	std::cout << "Hold on M M Morty, looks like an asteroid field ahead " << std::endl
		<< "Ahh geez Rick, can't we just teleport through? " << std::endl
		<< "Relax Morty, don't be such a b b *BURPS* baby. " << std::endl
		<< "I'll take the wheel, we can navigate these rocks. " << std::endl;
	std::cout << "\n\n";
}
void asteroidField::navigateSpace()
{
	
	std::string input;
	int zigerionShipHealth = 300;
	int roundCount = 0;

		
	if (!levelPassed)
	{
		spaceInfo();

		std::cout << "Shortly after entering the asteroid field, you are set on by the well known " << std::endl
			<< "intergalactic scammers, the Zigerions! They are obviously after Rick's recipe for concentrated dark matter. " << std::endl
			<< "You can either try and outrun them, fight them, or teleport your way out of this mess. The portal gun may " << std::endl
			<< "have enough energy. " << std::endl;

		std::cout << "Choose your move based on the following selections.\n"
			<< "1. Try and outrun them\n"
			<< "2. Fight\n"
			<< "3. Use portal gun.\n";
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
			std::cout << "You try and outrun them, but their ship is way too fast and big. The asteroids " << std::endl
				<< "hit their ship and do nothing. You are gonna either need to stand and fight or teleport. " << endl;
			break;
		case 2:
		{
			std::cout << "You have chosen to fight! Let the battle begin! hint: Now might be a good time for ship lasers. " << std::endl;
			while (zigerionShipHealth > 0 && player->getHealth() > 0)
			{
				zigerionShipHealth -= player->attack(roundCount);
				int zigerionAtk = attack();
				player->defend(zigerionAtk);
				std::cout << "Zigerions attack with " << zigerionAtk << " damage. " << std::endl;
				std::cout << "Rick and Morty's health after round " << roundCount << ": " << player->getHealth() << std::endl;
				std::cout << "Zigerion ship health after round " << roundCount << ": " << zigerionShipHealth << std::endl;

				roundCount++;
			}
			break;
		}
		case 3:
		{
			if (player->portalGunUsed())
			{
				std::cout << "Portal Gun has only 1 charge! Can't use it. " << endl;
			}
			else
			{
				std::cout << "Let's get out of here Morty! " << std::endl;
				player->specialPortalGun();
				levelPassed = true;
			}
		}

		}//end switch
		if (zigerionShipHealth <= 0)
		{
			std::cout << "Congrats! You have defeated the Zigerions and you have navigated out of the asteroid field. " << endl;
			//std::cout <<
			levelPassed = true;
		}
		if (player->getHealth() <= 0)
		{
			std::cout << "You died! " << std::endl;
			levelPassed = true;
		}
		
	}

}

int asteroidField::attack()
{
	int zigerionAtk = rollFuncSpace(3, 6);
	return zigerionAtk;
}