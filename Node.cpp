#include "Node.h"
#include <cstddef>

Node::Node() : pWrapper(0), next(NULL){}

Node::Node(int tempID) : pWrapper(tempID), next(NULL){};

Node::~Node()
{
    //dtor
}
