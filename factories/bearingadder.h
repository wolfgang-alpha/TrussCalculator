#ifndef BEARINGADDER_H
#define BEARINGADDER_H

#include <QGraphicsSceneMouseEvent>

class Node;

class BearingAdder final
{
public:
    BearingAdder();

    void mouseClicked(QGraphicsSceneMouseEvent *event, Node *node);
};

#endif // BEARINGADDER_H
