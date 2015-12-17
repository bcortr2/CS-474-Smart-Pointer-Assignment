#ifndef NODE_H
#define NODE_H
#include "PaintingWrapper.h"

class Node
{
    friend class LList;
    public:
        Node();
        Node(int tempID);
        virtual ~Node();
        Node(const Node& other);
        PaintingWrapper getPW() {return pWrapper;}
        Node* getNext() {return next;}
    protected:
        PaintingWrapper pWrapper;
    private:
        Node* next;
};

#endif // NODE_H
