#ifndef RODADDER_H
#define RODADDER_H

#include <QGraphicsSceneMouseEvent>

class Rod;
class Node;
class GraphicsScene;

class RodAdder final
{
public:
    explicit RodAdder(GraphicsScene *graphicsScene);
    ~RodAdder();
    // prevent copying or moving this class (because how would a copy look like and since it is not necessary to move it around there is no need to implement the move-operation)
    RodAdder(const RodAdder &) = delete;
    RodAdder(RodAdder &&) = delete;
    RodAdder &operator =(const RodAdder &) = delete;
    RodAdder &operator =(RodAdder &&) = delete;

    void mouseClicked(QGraphicsSceneMouseEvent *event, Node *element);
    void positionChanged(QPointF newPosition);

    bool node1IsNull() const { return node1 == nullptr; }

    void createRod();

    bool rodExistsAlready(Node *node) const; // returns true if there is already a rod between node1 and the given node

private:
    GraphicsScene *scene; // weak ptr
    Rod *rod; // weak ptr as long as it is added to the scene
    Node *node1; // weak ptr
    Node *virtualNode; // weak ptr as long as it is added to the scene
};

#endif // RODADDER_H
