#include "Space.hpp"
#include "planetUnity.hpp"
#include "Player.hpp"
#include "asteroidField.hpp"
#include "planetGazorpazorp.hpp"
#include "TheCitadel.hpp"
#include "ThePurge.hpp"
#include "Microverse.hpp"




int main()
{
	srand(time(NULL));
	int gameChoice = 0;
	std::string input;
	int selection = 0;
	std::vector<std::string> vec;
	bool win = false;

	asteroidField *aField = new asteroidField();
	planetGazorpazorp *pZorp = new planetGazorpazorp();
	planetUnity *pUnity = new planetUnity();
	TheCitadel *tC = new TheCitadel();
	ThePurge *tP = new ThePurge();
	Microverse *micro = new Microverse();
	Player *p1 = new Player();

	//previous next top bottom
	tP->setSpaces(NULL, micro, NULL, NULL, p1, "The Purge Planet");
	micro->setSpaces(tP, aField, NULL, NULL, p1, "The 'Microverse'");
	aField->setSpaces(micro, pZorp, NULL, NULL, p1, "Asteroid Field");
	pZorp->setSpaces(aField, tC, NULL, NULL, p1, "Planet Gazorpazorp");
	tC->setSpaces(pZorp, pUnity, NULL, NULL, p1, "The Council of Ricks");
	pUnity->setSpaces(tC, NULL, NULL, NULL, p1, "Planet Unity");
	p1->setLocation(tP);

	std::cout << "Welcome to the Rick and Morty Game! here is a brief overview.  " << std::endl;
	cout << "This game is based off of the TV show Rick and Morty. If you haven't seen it, this game probably won't make much sense. " << endl
		<< "But don't worry, it should still be fun! here is a little game info. " << endl
		<< "Beth (Rick's daughter), has ingested some strange poison that mad scientist Rick Sanchez has left lying around the garage. " << endl
		<< "You enlist your grandson Morty to go on an adventure to find the ingredients for the antitode for the poison. " << endl
		<< "You end up running into problems along the way, and need to fight your way through! " << endl
		<< "Rick is a mad scientist, and is pretty much amazing in every way. He has a spaceship made of parts from the garage " << endl
		<< "he has friends all over the galazy, and has a lot of inventions. Rick can also turn himself into a pickle. " << endl
		<< "The object of the game is to move through the worlds and collect the ingredients for Beth. You can move either left or right. " << endl
		<< "I hope you enjoy! Let's get started!! " << endl << endl << endl;
	std::cout << "You are starting at " << p1->getLocation()->getName() << endl;
	//cout << p1->getHealth() << endl;
	//cout << p1->getLocation()->getName() << endl;

	cout << "Enter 0 to start the game of 2 to quit right away. " << endl;

	while (selection != 2)
	{
		menu(selection, vec, "Press 1 to start the game", "Press 2 to exit. ");

		if (p1->getHealth() <= 0 || win)
		{
			cout << "Looks like you didn't get the ingredients in time. Jerry has now committed suicide because Beth is dead " << endl
				<< "and Summer has joined the circus. " << endl;
			break;
		}

		if (selection == 1)
		{

			while (p1->getHealth() > 0 && !win)
			{
				std::cout << "what do you want to do? " << std::endl;
				//std::cout << p1->getHealth() << endl;
				std::cout << "Choose your move based on the following selections.\n"
					<< "1. Enter World\n"
					<< "2. Move\n"
					<< "3. Buy new Morty.\n"
					<< "4. Check items acquired.\n";

				if (p1->getHealth() <= 0)
				{
					cout << "Looks like you didn't get the ingredients in time. Jerry has now committed suicide because Beth is dead " << endl
						<< "and Summer has joined the circus. " << endl;
				}

				gameChoice = getInt(input, 0, 4);

				switch (gameChoice)
				{
				case 1:
				{
					if (p1->spaceSearch("Planet Unity") && !p1->enoughItems())
					{
						std::cout << "You have unfinished business. " << std::endl;
					}
					else
					{
						p1->getLocation()->navigateSpace();
						if (p1->spaceSearch("Planet Unity") && p1->enoughItemsToWin())
						{
							cout << "Just in the knick of time, you throw the ingredients together to create the antidote for beth. " << endl;
							cout << "You have won the game! " << endl;
							win = true;
							//p1->clearItems();
						}
					}
					break;
				}
				case 2:
				{

					cout << "Move\n1. left\n2. right.\n";
					int moveSel = getInt(input, 1, 2);

					switch (moveSel)
					{
					case 1:
						p1->moveLeft();
						break;
					case 2:
						p1->moveRight();
						break;
					default:
						break;
					}
					break;
				}
				case 3:
				{
					if (p1->buyNewMortyUsed())
					{
						std::cout << "Either your Morty is still alive, or you already bought a new Morty. " << std::endl;
					}
					else
					{
						p1->specialBuyNewMorty();
					}
					break;
				}
				case 4:
				{
					p1->getItems();
					break;
				}
				default:
					break;
				} //end switch

				/*
				if (*gameWon)
				{
					cout << "Just in the knick of time, you throw the ingredients together to create the antidote for beth. " << endl;
					cout << "You have won the game! " << endl;
					cout << "would you like to play again? Please press 0 to view the menu or 2 to quit. " << endl;
					menu(selection, vec, "Press 1 to start", "press 2 to exit. ");
				}
				*/

			}//end health while

			if (p1->getHealth() <= 0)
			{
				cout << "Looks like you didn't get the ingredients in time. Jerry has now committed suicide because Beth is dead " << endl
					<< "and Summer has joined the circus. " << endl;
				break;
			}

			//cout << "Here" << endl;
			//cout << "would you like to play again? Please press 0 to view the menu or 2 to quit. " << endl;
			//menu(selection, vec, "Press 1 to start", "press 2 to exit. ");
		}//end selection if
		//cout << "Here" << endl;
	}// end selection while

	//cout << "Here" << endl;



		//end if
	//end game while

	//cout << "would you like to play again? Please press 0 to view the menu or 2 to quit. " << endl;
//	menu(selection, vec, "Press 1 to start", "press 2 to exit. ");
	delete aField;
	delete pZorp;
	delete p1;
	delete pUnity;
	delete tP;
	delete micro;
	delete tC;
	
	return 0;
}