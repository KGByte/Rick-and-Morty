#include "TheCitadel.hpp"
#include "Player.hpp"


TheCitadel::TheCitadel()
{
	this->levelPassed = false;
}
TheCitadel::~TheCitadel()
{
}

void TheCitadel::spaceInfo()
{
	cout << "Shortly after leaving Gazorpazorp world, a ship from the governing body over all ricks within reality, " << endl
		<< "swooped in behind Rick and Morty's little space ship and sent out their tractor beam to bring in their ship. " << endl << endl;

	cout << "Ah geez what now Rick? Morty exasperately explaimed. " << endl
		<< "It's the damn Council of Ricks! Probably taking us back to The Citadel to beg me to join their dumb government. " << endl
		<< "I hope that's all it is... " << endl
		<< "D d don't be so dramatic, Morty, not like those idiots could do anything outside their rickdiculous government. " << endl;
}
void TheCitadel::navigateSpace()
{

	std::string input;
	int councelHealth = 100;
	int roundCount = 0;


	if (!levelPassed)
	{
		spaceInfo();

		cout << "As soon as Rick and Morty's ship was safely aboard, they were handcuffed and brought to The Council. " << endl
			<< "Rick: yeah nice little show of force you idiots, I'm not gonna join your dumb club. " << endl
			<< "Council: Silence! You are brought before us to stand trial for the murder of 27 ricks. " << endl
			<< "Guards! Take his portal gun, check the history. " << endl
			<< "Rick: Oh come on guys, don't look at another mans portal history! That's sacred information! " << endl
			<< "Council: Silence! Once we match up your portal history to the deaths of the Ricks, we can lock you away for good. " << endl;

		cout << "Looks like you're in a pickle here, no pun intended, cus you could actually be a pickle if you wanted, you know, " << endl
			<< "if you haven't used that special yet. Anyways, The Council of Ricks mean business, you're gonna have to figure out what to do. " << endl;

		cout << "Choose your move based on the following selections.\n"
			<< "1. Try and escape\n"
			<< "2. Fight\n"
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
			cout << "You try and escape but their are too many guards, looks like that isn't going to work. " << endl;
			break;
		case 2:
		{
			cout << "You have chosen to fight! Let the battle begin! " << endl;
			while (councelHealth > 0 && player->getHealth() > 0)
			{
				councelHealth -= player->attack(roundCount);
				int councelAtk = attack();
				player->defend(councelAtk);
				std::cout << "The Councel attack with " << councelAtk << " damage. " << std::endl;
				std::cout << "Rick and Morty's health after round " << roundCount << ": " << player->getHealth() << std::endl;
				std::cout << "The Council's health after round " << roundCount << ": " << councelHealth << std::endl;

				roundCount++;
			}
			break;
		}
		case 3:
		{
			if (player->pickleRickUsed())
			{
				cout << "You have already turned yourself into a pickle! " << endl;
			}
			else
			{
				player->pickleRick();
				cout << "Looks like you didn't luck out on this one, now you are at an extreme disadvantage. " << endl;
				cout << "Because you are so small and a pickle, and Morty is pretty much useless, your attack is now half what it should be. " << endl;
				cout << "This is bad. Hope for the best here. Oh yeah, you can still drink liquor for a better chance of attacking. " << endl;
				cout << "Rick can always drink liquor. " << endl;

				while (councelHealth > 0 && player->getHealth() > 0)
				{
					councelHealth -= player->pickleRickAttack();
					int councelAtk = attack();
					player->defend(councelAtk);
					std::cout << "The Councel attack with " << councelAtk << " damage. " << std::endl;
					std::cout << "Rick and Morty's health after round " << roundCount << ": " << player->getHealth() << std::endl;
					std::cout << "The Council's health after round " << roundCount << ": " << councelHealth << std::endl;

					roundCount++;
				}
				break;
			}
		}

		}//end switch
		if (councelHealth <= 0)
		{
			std::cout << "Congrats! You have defeated The Council and can finaly leave The Citadel once and for all. " << endl;
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

int TheCitadel::attack()
{
	//6 attacks, 1 for each council member
	int citadelAtk = rollFuncSpace(6, 6);
	return citadelAtk;
}