/// <summary>
/// This ccp file execute the summoning procedure and output results of the summon
/// Nikola Prusac Manahy
/// C00309098

#include<iostream>
#include<string>
#include "globals.h"


// list of functions
void PerformDfSummon(std::string t_confirm, int t_pity);		// rate system and get units
std::string gettingSR();										// Get a SR
std::string gettingR();											// Get a R
std::string gettingSSR();										// Get a SSR
std::string gettingPITY();										// Getting a featured unit
std::string gettingMAIN();										// Getting the main unit

void playerBox();										// opens the player's inventory


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


				if (redCoins <= 190)
				{
					std::cout << "Red coins amount: " << redCoins << std::endl;
					std::cin >> confirm;

					if (confirm == "box")
					{
						playerBox();
					}
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
						PerformDfSummon(confirm,pity);
					}
					
					if (confirm == "box")
					{
						playerBox();
					}

				}


			if (confirm == "no" || confirm == "No")
			{
				break;
			}
			// Send the user to the summon screen
			if (confirm == "Yes" || confirm == "yes")
			{
				pity += 50;				// Build the pity for the user
				pityCount -= 1;			// Reduce the number so the DOKKAN FEST is Obtained at 0
				mainUnit += 50;			// Build main unit pity
				redCoins += 10;			// the Main unit is Obtained at 200 if player wants

				PerformDfSummon(confirm, pity);
				// use an amount of currency everytime the user summon
				ds -= 50;		// Use dragon stones
			}
			else if (confirm == "No" || confirm == "no" && confirm != "box")
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

		} while (ds != 0);

		// Clean inventory when maximun reached

		// Add a gap and display on the user's screen that there is no currency left to continue
		if (ds == 0)		// If the amount is very low
		{
			std::cout << std::endl << RED <<
				"You have " << ds << " Dragon Stone left" << RESET << std::endl;
		}
		else
		{
			std::cout << std::endl <<
				"You have " << ds << " Dragon Stone left" << std::endl;
		}
}




// rate system to get units
void PerformDfSummon(std::string t_confirm, int t_pity)
{
	// Variables
	std::string character = "";			// These are the characters that the user will get in order
	int step;							// Number that need to reach 10 

	int randomNum = 0;					// Number generated randomly

	// If the user has bought the main unit by red coins
	if (t_confirm == "Main" || t_confirm == "main")
	{
		character = gettingMAIN();		// Call the main unit
		std::cout << "You have bought the main unit: " << character << std::endl;
		amount_main++;
	}

	for (step = 0; step <= 9; step++)
	{
		if (t_confirm == "Main" || t_confirm == "main")
		{
			break;
		}
		// Generate a random number to set the user's chance to get a unit (1-100)
		randomNum = (rand() % 101) + 1;

		if (randomNum >= 1 && randomNum <= 59 && step <= 8)		// Getting a SR unit
		{
			character = gettingSR();// Call SR unit
			amount_sr++;
		}
		else if (randomNum >= 60 && randomNum <= 89 && step <= 8)		// getting a R unit
		{
			character = gettingR();// Call R unit
			amount_r++;
		}
		else if (step <= 8)
		{
			character = gettingSSR();// Call a SRR unit
			amount_ssr++;
			std::to_string(unitsArray[step]) = character;
			boxAmount++;		// increase the player's box each time a unit has been summoned
		}


		// Character number 10 is always a SSR
		if (t_confirm != "Main")
		{
			if (step == 9)
			{
				if (t_pity == 150)
				{
					character = gettingPITY();  // Call a featured unit
					amount_Featured++;
					std::to_string(unitsArray[step]) = character;
					boxAmount++;		// increase the player's box each time a unit has been summoned
				}
				else
				{
					character = gettingSSR();
					std::to_string(unitsArray[step]) = character;
					boxAmount++;		// increase the player's box each time a unit has been summoned
					amount_ssr++;
				}
			}
		}
		else if (step == 9 && t_confirm != "Main")
		{
			character = gettingMAIN();		// Call the main unit
			amount_main++;
			std::to_string(unitsArray[step]) = character;
			boxAmount++;		// increase the player's box each time a unit has been summoned
		}

		
		// Display the result of the summon
		std::cout << "Summon result--> " << character << std::endl;
	}

	// Add a gap and display the amount of units the user got in a summury version
	std::cout << std::endl <<
		"Amount of Main unit: " << amount_main << std::endl <<
		"Amount of Fetured Unit: " << amount_Featured << std::endl <<
		"Amount of SSR: " << amount_ssr << std::endl <<
		"Amount of SR: " << amount_sr << std::endl <<
		"Amount of R: " << amount_r << std::endl;

}

// functions for units
std::string gettingR()
{
	// Set the units ready to randomly picked
	std::string r_units[] = { "R - Goku", "R - vegeta", "R - Piccolo", "R - Bulma", "R - Trunks", "R - Goten", "R - Gohan", "R - Master roshi", "R - Yamcha",
							"R - Tien", "R - Nappa", "R - Radits", "R - Frieza", "R - Android 16", "R - Android 17", "R - Android 18", "R - Android 19", "R - Dr. Gero", "R - Chichi" };

	// Pick the random unit
	int r_unit_generated = rand() % 19;

	// Return the unit 
	return r_units[r_unit_generated];
}

std::string gettingSR()
{
	// Set the units ready to randomly picked
	std::string sr_units[] = { "SR - vegeta", "SR - Super Saiyan Goku", "SR - King Piccolo", "SR - Yamcha", "SR - Cooler", "SR - Super Saiyan Trunks (kid)", "SR - Pan (Gt)",
								"SR - Super Saiyan Vegeta", "SR - Piccolo (Fused)", "SR - Android 13", "SR - Mai", "SR - Gohan", "SR - trunks (teen)(Future)", "SR - Gotenks", "SR - Goku", "SR - Super Saiyan 2 Goku", "SR - Krillin",
								"SR - Kami", "SR - Mr. Popo", "SR - Android 19", "SR - Android 16", "SR - Cell (1st From)", "SR - Dodoria", "SR - Zarbon", "SR - Frieza (2nd form)" };

	// Pick the random unit
	int sr_unit_generated = rand() % 25;

	// Return the unit 
	return sr_units[sr_unit_generated];
}

std::string gettingSSR()
{
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string BLUE = "\033[34m";
	const std::string PURPLE = "\033[35m";			// Colour to assossiate with the units
	const std::string RESET = "\033[0m";

	// Set the units ready to randomly picked
	std::string ssr_units[] = { "*SSR* - vegeta", "*SSR* - Goku", "*SSR* - Gohan", "*SSR* - Goten (Gt)", "*SSR* - Vegeta (Gt)", "*SSR* - Goku (Gt)", "*SSR* - Gotenks", "*SSR* - Super Saiyan 3 Gotenks",
								"*SSR* - Yamcha", "*SSR* - Nappa", "*SSR* - Super Saiyan God Goku", "*SSR* - Super Saiyan God Vegeta", "*SSR* - Gogeta", "*SSR* - Super Saiyan Vegito", "*SSR* - Super Saiyan 2 Gohan (teen)", "*SSR* - Android 17",
								"*SSR* - Android 16", "*SSR* - Android 18", "*SSR* - Dispo", "*SSR* - Toppo", "*SSR* - Jiren", "*SSR* - Super Saiyan God Super Saiyan Goku", "*SSR* - Ribrian", "*SSR* - Bergamo",
								"*SSR* - hit", "*SSR* - Frost", "*SSR* - Cabba", "*SSR* - Mageta", "*SSR* - Buu (Kid)", "*SSR* - Super Buu", "*SSR* - Buu (good)", "*SSR* - Buu (Evil)",
								"*SSR* - Ultimate Gohan", "*SSR* - Piccolo", "*SSR* - Cell (perfect form)", "*SSR* - Cell Jr.", "*SSR* - Super Saiyan God Super Saiyan Vegeta", "*SSR* - Frieza (Final form)", "*SSR* - Radits", "*SSR* - Krillin", };


	// List of featured units on the TEQ Buhan banner
	std::string ssr_feature[] = { GREEN + "*DOOKAN FEST* TEQ Super Buu (Gohan Absorbed)" + RESET , RED + "*DOOKAN FEST* STR Master Roshi" + RESET , BLUE + "*DOOKAN FEST* AGL Frieza (1st Form)" + RESET ,
									RED + "*DOOKAN FEST* STR Android #17 & Hell Fighter #17" + RESET , PURPLE + "*DOOKAN FEST* INT Majin Vegeta" + RESET , GREEN + "*DOOKAN FEST* TEQ Super Saiyan 2 Vegeta" + RESET ,
									PURPLE + "*DOOKAN FEST* INT Super Saiyan 2 Goku" + RESET , RED + "*DOOKAN FEST* STR Super Buu" + RESET, PURPLE + "*DOOKAN FEST* INT Ultimate Gohan" + RESET };

	// Pick the random unit
	int ssr_unit_generated = rand() % 40;
	int ssr_unit_featured_generated = rand() % 9;

	// If the user got a featured or not
	int probability = (rand() % 100) + 1;

	if (probability >= 1 && probability <= 94)
	{
		// Return the unit
		return ssr_units[ssr_unit_generated];
	}
	else
	{
		if (ssr_feature[ssr_unit_featured_generated] == ssr_feature[0])
		{
			amount_main++;
		}
		// Return the unit 
		return ssr_feature[ssr_unit_featured_generated];
	}
}






// pity system for main unit or featured units
std::string gettingPITY()
{

	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string BLUE = "\033[34m";
	const std::string PURPLE = "\033[35m";			// Colour to assossiate with the units
	const std::string RESET = "\033[0m";


	std::string ssr_feature[] = { GREEN + "*DOOKAN FEST* TEQ Super Buu (Gohan Absorbed)" + RESET , RED + "*DOOKAN FEST* STR Master Roshi" + RESET , BLUE + "*DOOKAN FEST* AGL Frieza (1st Form)" + RESET ,
									RED + "*DOOKAN FEST* STR Android #17 & Hell Fighter #17" + RESET , PURPLE + "*DOOKAN FEST* INT Majin Vegeta" + RESET , GREEN + "*DOOKAN FEST* TEQ Super Saiyan 2 Vegeta" + RESET ,
									PURPLE + "*DOOKAN FEST* INT Super Saiyan 2 Goku" + RESET , RED + "*DOOKAN FEST* STR Super Buu" + RESET, PURPLE + "*DOOKAN FEST* INT Ultimate Gohan" + RESET };

	// Pick the random unit
	int ssr_unit_featured_generated = rand() % 9;

	if (ssr_feature[ssr_unit_featured_generated] == ssr_feature[0])
	{
		amount_main++;
	}
	// return the featured unit to the function
	return ssr_feature[ssr_unit_featured_generated];
}





// buying the main unit after using 200 red coins
std::string gettingMAIN()
{

	const std::string GREEN = "\033[32m";			// Colour to assossiate with the units
	const std::string RESET = "\033[0m";


	std::string ssr_feature[] = { GREEN + "*DOOKAN FEST* TEQ Super Buu (Gohan Absorbed)" + RESET };

	// Pick the random unit
	int ssr_unit_featured_generated = rand() % 1;

	// return the featured unit to the function
	return ssr_feature[ssr_unit_featured_generated];
}

void playerBox()
{
	// variables
	std::string erase = "";

	std::cout << "-----------This is your box-----------" << std::endl;

	for (int index = 0; index < boxAmount; index++)
	{
		std::cout << std::to_string(unitsArray[index]) << std::endl;
	}
}