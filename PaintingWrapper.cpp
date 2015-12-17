#include "PaintingWrapper.h"
#include "LList.h"
#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>

PaintingWrapper::PaintingWrapper() : IDHandle(0), pPainting(NULL), isNull(true) {}

PaintingWrapper::PaintingWrapper(int ident) : IDHandle(ident), pPainting(NULL), isNull(true) {}

//delete painting and set to NULL
PaintingWrapper::~PaintingWrapper()
{
    delete pPainting;
    pPainting = NULL;
}

//load painting not already in memory from file based on num (painting ID)
Painting* PaintingWrapper::pLoadFromFile(int num)
{
    std::string n, t, str, f;
    int i;
    switch(num){
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

    std::ifstream myFile(f.c_str(), std::fstream::in);
    if(myFile.is_open()){
    getline(myFile, str, ',');
    std::istringstream(str) >> i;
    getline(myFile, t, ',');
    getline(myFile, n, ',');
    }
    else
        std::cout << "Problem opening file" << std::endl;

    myFile.close();
    return new Painting(i, t, n);
}

Painting* PaintingWrapper::operator->()
{
    if (pPainting == NULL){
        pPainting = pLoadFromFile(IDHandle);
        isNull = false;
        if (!LList::spaceLeft)
           LList::eject = true;
        else
        LList::spaceLeft--;
    }

    return pPainting;
}

Painting& PaintingWrapper::operator*()
{
    if(pPainting == NULL){
        pPainting = pLoadFromFile(IDHandle);
    }
    return *pPainting;
}

