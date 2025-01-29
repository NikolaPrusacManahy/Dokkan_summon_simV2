/// <summary>
/// This ccp file execute the summoning procedure and output results of the summon
/// Nikola Prusac Manahy
/// C00309098

#include<iostream>
#include<string>
#include "globals.h"


// list of functions


// main function
void performSummon()
{
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string BLUE = "\033[34m";
	const std::string PURPLE = "\033[35m";			// Colour to assossiate with the units
	const std::string RESET = "\033[0m";

	// Variables
	std::string confirm = "";	// Confirmation from the user (Yes/No)

	int pity = 0;				// build pity if the user spent 150 dragon stones (repeatable)
	int pityCount = 3;			// Show the amount of summon required to get the pity unit
	int mainUnit = 0;			// The user will get the main unit when the amount of summons is 20
	int redCoins = 0;			// Countdown before getting the main unit
	int ds = 0;					// dragon stones variables

	// ask the user how many Dragon stone they want (currencies)
	std::cout << "Please enter the amount of Dragon stones you want: ";
	std::cin >> ds;

	
		do
		{
			std::cout << "----------------------------------------------" << std::endl
				<< "Your box contain " << boxAmount << " units." << std::endl
				<< "If you want to check your own units inventory enter: (box)" << std::endl
				<< "Do you want to perform the summon? (Yes/No)" << std::endl
				<< "Amount of Dragon Stones: " << ds << std::endl
				<< "Guaranted Featured unit in " << pityCount << " summons" << std::endl;

		do
		{
				if (redCoins <= 190)
				{
					std::cout << "Red coins amount: " << redCoins << std::endl;
					std::cin >> confirm;
				}
				else if (redCoins >= 200)	// if near to pity
				{
					std::cout << GREEN << "Red coins amount: " << redCoins << RESET << std::endl;
					std::cout << RED << "If you want to buy the main unit, Please enter 'Main' or " << BLUE << "continue your summons(yes / no)" << RESET << std::endl;
					std::cin >> confirm;

					// Give the user another option to purchase the main unit
					if (confirm == "main" || confirm == "Main")
					{
						redCoins -= 200;
						PerformDfSummon(t_dokkanfest, pity, mainUnit, confirm);
					}
					std::string playerBoxanswer = "";
					if (confirm == "box")
					{
						playerBoxanswer = playerBox();
					}

				}
			} while (confirm != "no");



			// Send the user to the summon screen
			if (confirm == "Yes" || confirm == "yes")
			{
				pity += 50;				// Build the pity for the user
				pityCount -= 1;			// Reduce the number so the DOKKAN FEST is Obtained at 0
				mainUnit += 50;			// Build main unit pity
				redCoins += 10;			// the Main unit is Obtained at 200 if player wants

				PerformDfSummon(t_dokkanfest, pity, mainUnit, confirm);
				// use an amount of currency everytime the user summon
				t_ds -= 50;		// Use dragon stones
			}
			else if (confirm == "No" || confirm == "no")
			{
				std::cout << std::endl <<
					"You have closed the program" << std::endl;
				break;
			}
			else
			{
				// Error check
				std::cout << "ERROR! You have to type (yes or no) " << std::endl;
				continue;
			}

			if (pity == 150)		// Reset pity and pity counting
			{
				pity = 0;
				pityCount = 3;
			}

		} while (t_ds != 0);

		// Clean inventory when maximun reached

		// Add a gap and display on the user's screen that there is no currency left to continue
		if (t_ds == 0)		// If the amount is very low
		{
			std::cout << std::endl << RED <<
				"You have " << t_ds << " Dragon Stone left" << RESET << std::endl;
		}
		else
		{
			std::cout << std::endl <<
				"You have " << t_ds << " Dragon Stone left" << std::endl;
		}
}
