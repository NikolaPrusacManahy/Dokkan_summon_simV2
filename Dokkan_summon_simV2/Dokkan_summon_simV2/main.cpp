// Nikola Prusac Manahy
// C00309098
// Session time (Approx)
	// 29.01.25: 1h30
//----------------------------------------------------------------------------------
// This program is a re-creation of the Gacha game Dragon Ball Z Dokkan Battle
// It will simulate a gacha system with probabilities to get certain units
// Gambling System
//----------------------------------------------------------------------------------
// VERSION --> ALPHA
// ----------------------------------------------------------------------------------
// Update log --> 
// ---------------------------------------------------------------------------------
// LIST OF CORRECTION TO BE DONE!!!!!
	// 
	//
	//

#include<iostream>
#include<string>

// list of functions
void performSummon();		// does the summon procedure


int main()
{
	// randomize seed
	srand(time(nullptr));

	// variables
	int bannerType = 0;

	do
	{
		std::cout << "-----------------BANNER SELECTION-----------------" << std::endl
			<< "Please select a banner type by inputing the corresponding number." << std::endl
			<<  "1. DDF TEQ Super Buu (Gohan Absorbed) " << std::endl <<
				"2. Exit" << std::endl <<
				"3. (comming soon)" << std::endl;
		std::cin >> bannerType;

		if (bannerType <= 0 || bannerType > 2)		// Error check if the user's enter a wrong number
		{
			std::cout << "--------------------------------------------------"
				<< std::endl <<
				"ERROR! You have entered a number that is not on the list." << std::endl <<
				"Please enter a correct number." << std::endl <<
				"---------------------------------------------------------" <<
				std::endl;
		}

		if (bannerType == 1)
		{
			// function call to start summoning
			performSummon();		// does the summon procedure
		}
	} while (bannerType !=2);		// Repeat if not correct or stop program

	// exit message
	std::cout << "You have successfully closed the program :)" << std::endl;


	system("pause");
	return 0;
}