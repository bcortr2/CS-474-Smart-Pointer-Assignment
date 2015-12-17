#include "Painting.h"
#include <iostream>
#include <cstddef>
#include <fstream>
#include <sstream>

Painting::Painting()
{
    //ctor
}

//constructor
Painting::Painting(int newid, std::string newTitle, std::string newArtist)
{
    ID = newid;
    title = newTitle;
    artist = newArtist;
}

//save before painting is deleted
Painting::~Painting() {savePainting();}

Painting::Painting(const Painting& other)
{
    //copy ctor
}

//edit painting's title
void Painting::editTitle(std::string newTitle) {title = newTitle;}

//edit painting's artist
void Painting::editArtist(std::string newArtist) {artist = newArtist;}

//print given painting
void Painting::printPainting() { std::cout << "Painting ID " << ID << ") Titled: " << title << " By: " << artist << std::endl; }

//determine which file to save to (by ID) and load it's information
void Painting::savePainting()
{
    std::string n, t, str, f;

    switch(ID){
        case 1:
            f = "paint1.txt";
            break;
        case 2:
            f = "paint2.txt";
            break;
        case 3:
            f = "paint3.txt";
            break;
        case 4:
            f = "paint4.txt";
            break;
        case 5:
            f = "paint5.txt";
            break;
        default:
            std::cout << "ERROR with ID" << std::endl;
    }

    std::ostringstream ss;
    ss << ID;
    str = ss.str() + "," + title + "," + artist;
    std::ofstream outFile(f.c_str(), std::iostream::trunc);
    if (outFile.is_open())
        outFile << str;
    else
        std::cout << "Problem opening file" << std::endl;
        outFile.close();
}
