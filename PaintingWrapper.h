#ifndef PAINTINGWRAPPER_H
#define PAINTINGWRAPPER_H
#include "Painting.h"
#include "LList.h"

class PaintingWrapper
{
    friend class Node;
    friend class LList;
    public:
        PaintingWrapper(int ident);
        PaintingWrapper();
        ~PaintingWrapper();
        Painting* operator->();
        Painting& operator*();
    protected:
        int IDHandle;
        Painting* pPainting;
        PaintingWrapper(const PaintingWrapper& other);
        bool isNull;
    private:
        Painting* pLoadFromFile(int num);
};

#endif // PAINTINGWRAPPER_H
