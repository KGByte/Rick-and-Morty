#include "planetUnity.hpp"
#include "Player.hpp"

planetUnity::planetUnity()
{
	//std::cout << "Calling unity constructor... " << std::endl;
	this->health = 200;
	this->levelPassed = false;
}

planetUnity::~planetUnity()
{
}

void planetUnity::spaceInfo()
{
	cout << "Alright Morty.. This is it. This is the last stop on our quest for the antidote for your mom. " << endl
		<< "Geez Rick.. Finally. You know this was all your fault anyway! " << endl
		<< "Not now Morty f f for Christs sake. *BURP* " << endl
		<< "Well where are we anyways Rick? " << endl
		<< "Good question Morty, we are about to be at the home world of my ex-girlfriend; Unity. Remeber her? " << endl
		<< "The all powerful being that takes over planets and controls the population and makes them all work together for good? " << endl
		<< "Exactly Morty. We aren't on good terms after I practically made her relapse and ruin the current planet she was on. " << endl
		<< "Yeah Rick..they almost killed me. Oh wait, thats every adventure we are on! " << endl
		<< "w w whatever MORTY, you're just jealous cus your adventures are boring and lame. " << endl
		<< "I didn't even want this adventure! You conveniently hid the poison meant for Evil Morty in the damn wine bottle " << endl
		<< "when you know damn well mom drinks a whole bottle every afternoon! " << endl
		<< "That's not the point Morty, l l l lets just get the antidote. " << endl;
}
void planetUnity::navigateSpace()
{

	std::string input;

	setHealth(200);
	health = getHealth();
	int roundCount = 0;

	cout << "You land on Planet Unity, or at least the planet controlled by it. " << endl
		<< "Unity is not very happy to see you. " << endl
		<< "Unity: Last time you were here rick.. we all know what happened. " << endl
		<< "Rick: Yeah yeah yeah, don;t act like you didn't like it. " << endl
		<< "Morty: Rick! Just ask for the ingredient! " << endl
		<< "Rick: Quiet Morty. Unity, your planet, the one you controlled without their acknowledgement ... " << endl
		<< "Unity: I'm running out of patience Rick. " << endl
		<< "Rick: Alright alright alright, we just need the Mega Seeds so we can ... " << endl
		<< "Unity: And why should I give you those? Honestly Rick, I was hoping to never see you again, but now that " << endl
		<< "I think about it, the universe would be better without you. " << endl
		<< "I think it's time someone took you down. EVERYONE! KILL RICK AND MORTY! " << endl;
	cout << "\n\n";

	cout << "You got 1 real choice this time. Looks like you better fight. Time to take on the whole planet! " << endl;
	cout << "The swarm does a lot more damage when they are together, start taking them out to decrease their damage. " << endl;

	cout << player->getHealth() << endl;

	while (!levelPassed)
	{

		while (getHealth() > 0 && player->getHealth() > 0)
		{
			int unityAtk = attack();
			health -= player->attack(roundCount);
			player->defend(unityAtk);
			std::cout << "Unity attacks with " << unityAtk << " damage. " << std::endl;
			std::cout << "Rick and Morty's health after round " << roundCount << ": " << player->getHealth() << std::endl;
			std::cout << "Unity's health after round " << roundCount << ": " << health << std::endl;

			if (getHealth() <= 0)
			{
				std::cout << "Congrats! You have defeated Unity once and for all, found the mega seeds " << endl
					<< "and should now have all the ingrediens to save beth! " << endl;
				player->addItem("Mega Seed");
				levelPassed = true;
			}
			if (player->getHealth() <= 0)
			{
				std::cout << "You died! " << std::endl;
				levelPassed = true;
			}
			roundCount++;
		}
	}

}
int planetUnity::attack()
{
	int unite = 0;

	//gazorpazops lose attack damage based on how many there are
	unite = ceil(getHealth() / (float)20);
	int unityAtk = rollFuncSpace(unite, 6);
	return unityAtk;
}

int planetUnity::getHealth()
{
	return health;
}
void planetUnity::setHealth(int)
{
	this->health = health;
}