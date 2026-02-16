#ifndef NODEADDER_H
#define NODEADDER_H

#include <QGraphicsSceneMouseEvent>

class Node;
class GraphicsScene;

class NodeAdder final
{
public:
    explicit NodeAdder(GraphicsScene *graphicsScene);
    ~NodeAdder();
    // prevent copying or moving this class (because how would a copy look like and since it is not necessary to move it around there is no need to implement the move-operation)
    NodeAdder(const NodeAdder &) = delete;
    NodeAdder(Node &&) = delete;
    NodeAdder &operator =(const NodeAdder &) = delete;
    NodeAdder &operator =(NodeAdder &&) = delete;

    void positionChanged(const QPointF &newPosition);
    void mouseClicked(QGraphicsSceneMouseEvent *event);

    void addNodePermanently();

private:
    GraphicsScene *scene; // weak ptr
    Node *node; // owner when not added to the scene
};

#endif // NODEADDER_H
