// Nikola Prusac Manahy
// C00309098
// Session time (Approx)
        // 29.01.25: 1h30
//----------------------------------------------------------------------------------
// This program is a re-creation of the Gacha game Dragon Ball Z Dokkan Battle
// It will simulate a gacha system with probabilities to get certain units
// Gambling System
//----------------------------------------------------------------------------------
// VERSION --> BETA
// ----------------------------------------------------------------------------------
// Update log --> Box feature to be added
// ---------------------------------------------------------------------------------
// LIST OF CORRECTION TO BE DONE!!!!!
        //
        //
        //

#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<limits>

// list of functions
void performSummon();           // does the summon procedure

// UI helpers
void displayTitle();
void displayMainMenu();
void displayErrorMessage(const std::string& message);
void displayGoodbye();


int main()
{
        // randomize seed
        srand(static_cast<unsigned int>(time(nullptr)));

        displayTitle();

        // variables
        int bannerType = 0;

        do
        {
                displayMainMenu();

                if (!(std::cin >> bannerType))
                {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        displayErrorMessage("That doesn't look like a number. Please choose an option from the menu.");
                        continue;
                }

                if (bannerType <= 0 || bannerType > 2)          // Error check if the user's enter a wrong number
                {
                        displayErrorMessage("You have entered a number that is not on the list. Try again!");
                }

                if (bannerType == 1)
                {
                        // function call to start summoning
                        performSummon();                // does the summon procedure
                }
        } while (bannerType != 2);               // Repeat if not correct or stop program

        // exit message
        displayGoodbye();


        system("pause");
        return 0;
}

void displayTitle()
{
        const std::string GOLD = "\033[33m";
        const std::string RESET = "\033[0m";
        const std::string BOLD = "\033[1m";

        std::cout << '\n';
        std::cout << GOLD << BOLD;
        std::cout << "      ██████╗  ██████╗ ██╗  ██╗██╗  ██╗ █████╗ ███╗   ██╗" << std::endl;
        std::cout << "      ██╔══██╗██╔═══██╗██║ ██╔╝██║  ██║██╔══██╗████╗  ██║" << std::endl;
        std::cout << "      ██████╔╝██║   ██║█████╔╝ ███████║███████║██╔██╗ ██║" << std::endl;
        std::cout << "      ██╔══██╗██║   ██║██╔═██╗ ██╔══██║██╔══██║██║╚██╗██║" << std::endl;
        std::cout << "      ██║  ██║╚██████╔╝██║  ██╗██║  ██║██║  ██║██║ ╚████║" << std::endl;
        std::cout << "      ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝" << std::endl;
        std::cout << RESET << std::endl;

        std::cout << std::string(70, '=') << std::endl;
        std::cout << std::setw(53) << "Dokkan Battle Summon Simulator" << std::endl;
        std::cout << std::string(70, '=') << std::endl << std::endl;
}

void displayMainMenu()
{
        const std::string CYAN = "\033[36m";
        const std::string RESET = "\033[0m";
        const std::string BOLD = "\033[1m";

        std::cout << CYAN;
        std::cout << "╔══════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║" << BOLD << "                  BANNER SELECTION HUB                  " << RESET << CYAN << "║" << std::endl;
        std::cout << "╠══════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║  Please enter the number of the banner you wish to try.  ║" << std::endl;
        std::cout << "╠══════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║  1. ✦ DDF TEQ Super Buu (Gohan Absorbed)                 ║" << std::endl;
        std::cout << "║  2. ✦ Exit the Summon Chamber                            ║" << std::endl;
        std::cout << "║  3. ✦ (Coming soon)                                      ║" << std::endl;
        std::cout << "╚══════════════════════════════════════════════════════════╝" << RESET << std::endl;
        std::cout << "Your choice: ";
}

void displayErrorMessage(const std::string& message)
{
        const std::string RED = "\033[31m";
        const std::string RESET = "\033[0m";

        std::cout << std::endl;
        std::cout << RED;
        std::cout << "╔════════════════════════════════════════╗" << std::endl;
        std::cout << "║   Oops!                                 ║" << std::endl;
        std::cout << "╠════════════════════════════════════════╣" << std::endl;
        if (message.size() <= 38)
        {
                std::cout << "║  " << std::left << std::setw(38) << message << "║" << std::endl;
        }
        else
        {
                std::cout << "║  " << std::left << std::setw(38) << message.substr(0, 38) << "║" << std::endl;
                std::cout << "║  " << std::left << std::setw(38) << message.substr(38) << "║" << std::endl;
        }
        std::cout << "╚════════════════════════════════════════╝" << RESET << std::endl << std::endl;
}

void displayGoodbye()
{
        const std::string GREEN = "\033[32m";
        const std::string RESET = "\033[0m";

        std::cout << GREEN;
        std::cout << "╔═══════════════════════════════════════════════╗" << std::endl;
        std::cout << "║  Thank you for visiting the Summon Chamber!   ║" << std::endl;
        std::cout << "║  May your next pulls be legendary!            ║" << std::endl;
        std::cout << "╚═══════════════════════════════════════════════╝" << RESET << std::endl;
}
