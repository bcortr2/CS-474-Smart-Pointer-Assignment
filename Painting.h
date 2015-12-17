#ifndef PAINTING_H
#define PAINTING_H
#include <string>

class Painting
{
    friend class PaintingWrapper;
    public:
        Painting();
        Painting(int newid, std::string newTitle, std::string newArtist);
        ~Painting();
        Painting(const Painting& other);
        void printPainting();
        void savePainting();
        void editArtist(std::string newArtist);
        void editTitle(std::string newTitle);
    protected:
        int ID;
        std::string title;
        std::string artist;
        char* image;
    private:
};

#endif // PAINTING_H
