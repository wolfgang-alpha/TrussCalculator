#ifndef LABELADDER_H
#define LABELADDER_H

#include <QGraphicsSceneMouseEvent>

class Label;
class GraphicsScene;

class LabelAdder final
{
public:
    LabelAdder(GraphicsScene *graphicsScene); // see NodeAdder for comments
    ~LabelAdder();
    // prevent copying or moving this class (because how would a copy look like and since it is not necessary to move it around there is no need to implement the move-operation)
    LabelAdder(const LabelAdder &) = delete;
    LabelAdder(LabelAdder &&) = delete;
    LabelAdder &operator =(const LabelAdder &) = delete;
    LabelAdder &operator =(LabelAdder &&) = delete;

    void mouseClicked(QGraphicsSceneMouseEvent *event);

    void positionChanged(const QPointF &newPosition);

    void addLabelPermanently();

private:
    GraphicsScene *scene;
    Label *label;
};

#endif // LABELADDER_H
