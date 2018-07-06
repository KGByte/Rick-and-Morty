/*
This is (hopefully) my re-usable menu function. To create this menu, I used
bits and pieces from the multiple sources listed below:
https://www.youtube.com/watch?v=fxRE5fHTYJg (vector idea, somewhat modified)
9th edition textbook setion 6.9: Functions in a menu driven program (general menu idea)
8th edition textbook same correspoding section (used for the char y/n to continue or not)
*/

#include "Util.hpp"

int getInt(std::string str, int min, int max)
{
	int userInt;
	bool isGood = false;

	do
	{
		getline(cin, str);
		std::stringstream ss(str);

		if (ss >> userInt)
		{
			if (userInt > max || userInt < min && str.find("."))
			{
				cout << "You must choose an integer between the given bounds "
					<< "from the menu. " << endl;
			}
			else
			{
				isGood = true;
			}
		}
		else
		{
			cout << "You must enter an integer. " << endl;
		}

	} while (!isGood);

	//cout << endl;

	return userInt;
}

int modifiedGetInt(std::string str, int choice1, int choice2)
{

		int userInt;
		bool isGood = false;

		do
		{
			getline(cin, str);
			std::stringstream ss(str);

			if (ss >> userInt)
			{
				if (userInt != choice1 && userInt != choice2)
				{
					cout << "You must choose an integer between the given bounds "
						<< "from the menu. " << endl;
				}
				else
				{
					isGood = true;
				}
			}
			else
			{
				cout << "You must enter an integer. " << endl;
			}

		} while (!isGood);

		//cout << endl;

		return userInt;
}

void menu(int &choice, std::vector<std::string> &menuHold, std::string option1, std::string option2)
{
	/*cout << "Welcome to the game! Here are your options! " << endl;
	cout << "Option 1: Select 1 to start. " << endl;
	cout << "Option 2: Select 2 to quit. " << endl;
	cout << "That's it so far! " << endl;*/
	std::string input;
	choice = getInt(input, 0, 2);

	//std::string temp;

	switch (choice)
	{
	case 0:
		//grab option 1 or 2. can add more options as the menu gets more complicated
		menuHold.push_back(option1);
		menuHold.push_back(option2);
		//cout statement for debugging, will probably comment out
		//cout << "Added menu options! " << endl;
		//grab print menu function
		printMenu(menuHold);
		//menu kept adding choices over and over so I added this to clear each time
		menuHold.clear();
		break;
	case 2:
		exit(1);
		break;
	default:
		break;
	}
}

//This function prints the menu by looping through all the
//options that we have added
void printMenu(const std::vector<std::string> &menuHold)
{
	cout << "Here are the menu options! " << endl;

	for (int i = 0; i < menuHold.size(); i++)
	{
		cout << i + 1 << ": " << menuHold[i] << endl;
	}
}

