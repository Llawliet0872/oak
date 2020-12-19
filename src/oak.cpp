#include "../include/Utils.hpp"

int main(int argc, char **argv)
{
	std::string command = "";
	if (argc >= 2)
	{
		command = argv[1];

		if (command == "install")
		{
			if (argc <= 2)
			{
				std::cout << "Package not specified!" << std::endl;
			}
			else
			{
				char option; 
				std::cout << "\nInstalling " << argv[2] << "..."
						  << "\n"
						  << std::endl;
				install(argv[2]);
			}
		}

		else if (command == "list")	
		{
			list();
		}

		else if (command == "help")
		{
			std::cout << "\nUse \"oak search <name>\" to see if a package is available.\nUse \"oak list\" to see a list of the available packages. \nUse \"oak install <package>\" for installing new packages.\n\nIf you like oak and want to help it develop, you can contribute by adding packages to https://github.com/Llawliet0872/scripts." << std::endl;
		}

		else if (command == "search")
		{
			if (argc <= 2)
			{
				std::cout << "Name not specified!" << std::endl;
			}
			else
			{
				search(argv[2]);
			}
		}

		else
		{
			std::cout << argv[1] << ": Command Not Found!" << std::endl;
		}
	}

	else
	{
		std::cout << "Too few arguments!" << std::endl;
	}

	return 0;
}