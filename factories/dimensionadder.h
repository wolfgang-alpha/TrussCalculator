#ifndef DIMENSIONADDER_H
#define DIMENSIONADDER_H

class Node;
class Dimension;
class GraphicsScene;
class QGraphicsSceneMouseEvent;
class QPointF;

class DimensionAdder final
{
public:
    DimensionAdder(GraphicsScene *graphicsScene);
    ~DimensionAdder();
    // prevent copying/moving this class
    DimensionAdder(const DimensionAdder &) = delete;
    DimensionAdder(DimensionAdder &&) = delete;
    DimensionAdder &operator =(const DimensionAdder &) = delete;
    DimensionAdder &operator =(DimensionAdder &&) = delete;

    void mouseClicked(QGraphicsSceneMouseEvent *event, Node *node);

    void positionChanged(const QPointF &newPosition);

private:
    void createDimension();

    GraphicsScene *scene; // weak ptr
    Dimension *dimension; // owner is this as long as it is not added to the scene
    Node *node1; // weak ptr
    Node *virtualNode; // owner as long as it is not added to the scene
};

#endif // DIMENSIONADDER_H
