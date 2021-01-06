#include "../include/Utils.hpp"

int main(int argc, char **argv)
{
	std::string command;
	// Checking for the number of arguments
	if (argc >= 2)
	{
		// Getting the arguments
		command = argv[1];
		// Checking is the argument is "install"
		if (command == "install")
		{
			// Checking is the package is specified
			if (argc <= 2)
			{
				std::cout << "Package not specified!" << std::endl;
			}
			else
			{
				std::cout << "\nInstalling " << argv[2] << "..."
						  << "\n"
						  << std::endl;
				install(argv[2]);
			}
		}

		if (command == "uninstall")
		{
			// Checking is the package is specified
			if (argc <= 2)
			{
				std::cout << "Package not specified!" << std::endl;
			}
			else
			{
				std::cout << "\nUninstalling " << argv[2] << "..."
						  << "\n"
						  << std::endl;
				uninstall(argv[2]);
			}
		}

		// Checking is the command is "list"
		else if (command == "list")	
		{
			list();
		}
		
		// Checking is the command is "help"
		else if (command == "help")
		{
			std::cout << "Use \"oak search <name>\" to see if a package is available.\nUse \"oak list\" to see a list of the available packages. \nUse \"oak install <package>\" for installing new packages.\n\nIf you like oak and want to help it develop, you can contribute by adding packages to https://github.com/Llawliet0872/scripts." << std::endl;
		}

		// Checking if the command is search
		else if (command == "search")
		{
			// Checking is the name is specified
			if (argc <= 2)
			{
				std::cout << "Name not specified!" << std::endl;
			}
			else
			{
				search(argv[2]);
			}
		}
		// Checking is command exists
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
