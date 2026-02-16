#include "rope.h"

Rope::Rope() :
    Rod()
{
    pen.setWidth(3);
}

Rope::Rope(Node *elementNode1, Node *elementNode2) :
    Rod(elementNode1, elementNode2)
{
    pen.setWidth(3);
}
