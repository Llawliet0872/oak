#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#pragma once

/*
    This function installs packages
*/
void install(std::string package);

/*
	This function uninstalls packages installed through oak
*/
void uninstall(std::string package);

/*
    This function shows the lines which match a specified keyword 
    so that the user can get the correct name of the package
*/
void search(std::string keyword);

/* 
    This function display every available package
*/
void list();
