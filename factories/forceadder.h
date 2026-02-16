#ifndef FORCEADDER_H
#define FORCEADDER_H

#include <QGraphicsSceneMouseEvent>

class Node;

class ForceAdder final
{
public:
    ForceAdder();

    void mouseClicked(QGraphicsSceneMouseEvent *event, Node *node);
};

#endif // FORCEADDER_H
