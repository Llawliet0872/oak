#include <iostream>

int main()
{
    std::string option;
    std::cout << "Installing Dependencies for oak..." << std::endl;
    system("sudo apt install wget g++ libcurl4-openssl-dev dpkg tar");
    system("g++ src/oak.cpp src/utils.cpp -o oak -lcurl");
    std::cout << "Would you like to place oak in /bin for global access? [y/n]: ";
    std::cin >> option;
    if(option == "y" || option == "Y")
    {
        system("sudo mv oak /bin/oak");
        std::cout << "Use \"oak help\" for seeing the options. \nThank you for using oak!" << std::endl;
    }
    else if(option == "n" || option == "N")
    {
        std::cout << "Use \"./oak help\" for seeing the options. \nThank you for using oak!" << std::endl;
    }
    system("chmod +x clean.sh");
    system("./clean.sh");

    return 0;
}
