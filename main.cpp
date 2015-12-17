/*Homework 3
 CS474
 Brad Cortright (bcortr2)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LList.h"
#include "PaintingWrapper.h"
#include <cstdlib>

//Prints main menu
void printMenu(){
  std::cout << std::endl;
  std::cout << "*************************************" << std::endl;
  std::cout << "Please choose from the following options" << std::endl;
  std::cout << " 'l' --> List all paintings" << std::endl;
  std::cout << " '1...5' --> Edit the painting with the given ID" << std::endl;
  std::cout << " 't' --> Change the title of the currently selected painting" << std::endl;
  std::cout << " 'a' --> Change the artist name of the currently selected painting" << std::endl;
  std::cout << " 's' --> Save all paintings" << std::endl;
  std::cout << " 'q' --> Quit application" << std::endl;
  std::cout << "Please Enter Choice: ";
}

int main(int argc, char* argv[])
{
    char c;
    std::string newName;
    int p;
    LList l;

    std::cout << "Starting Painting Manager..." << std::endl;
    while (1){
        //loop until user chooses to quit. Print menu options every loop. Get user choice
        std::cout << std::endl;
        std::cout << std::endl;
        printMenu();
        std::cin >> c;
        //check if user choice is 1...5 for setting current painting. If true, lock switch variable to '1' arbitrarily to denote that menu choice
        p = atoi(&c);
        if (p > 0 && p < 6)
            c = '1';

        switch (c){
        //list all paintings
        case 'l':
            std::cout << std::endl;
            std::cout << "Listing all paintings... " << std::endl;
            std::cout << "#####################################" << std::endl;
            l.walkAndPrint();
            std::cout << "#####################################" << std::endl;
            break;
        //allow user to set current painting
        case '1':
            std::cout << std::endl;
            std::cout << "Changing current painting... " << std::endl;
            l.setCurr(p);
            break;
        //allow user to set new title for current painting
        case 't':
            std::cout << "Please enter title name: ";
            std::cin >> newName;
            l.setTitle(newName);
            std::cout << std::endl;
            std::cout << "#####################################" << std::endl;
            std::cout << "New painting description: " << std::endl;
            l.printSingle();
            std::cout << "#####################################" << std::endl;
            break;
        //allow user to set new artist name for current painting
        case 'a':
            std::cout << "Please enter artist name: ";
            std::cin >> newName;
            l.setArtist(newName);
            std::cout << std::endl;
            std::cout << "#####################################" << std::endl;
            std::cout << "New painting description: " << std::endl;
            l.printSingle();
            std::cout << "#####################################" << std::endl;
            break;
        //allow user to save paintings in memory
        case 's':
            std::cout << std::endl;
            std::cout << "Saving paintings..." << std::endl;
            l.save();
            std::cout << "Saved!" << std::endl;
            break;
        //allow user to quit program
        case 'q':
            std::cout << std::endl;
            std::cout << "Exiting..." << std::endl;
            exit(0);
            break;
        //invalid menu choice
        default:
            std::cout << "Incorrect user input" << std::endl;
            break;
        }
    }
    return 0;
}
