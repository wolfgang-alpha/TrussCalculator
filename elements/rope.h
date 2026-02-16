#ifndef ROPE_H
#define ROPE_H

#include "rod.h"

class Node;

class Rope : public Rod
{
    Q_OBJECT

public:
    explicit Rope(); // default ctor
    Rope(Node *elementNode1, Node *elementNode2);
    ~Rope() override = default;
    // disable copying/moving because of member-ptrs (implement later if necessary)
    Rope(const Rope &) = delete;
    Rope(Rope &&) = delete;
    Rope &operator =(const Rope &) = delete;
    Rope &operator =(Rope &&) = delete;
};

#endif // ROPE_H
