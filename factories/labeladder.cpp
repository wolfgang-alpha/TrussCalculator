#include "labeladder.h"

#include "elements/label.h"
#include "graphicsscene.h"

LabelAdder::LabelAdder(GraphicsScene *graphicsScene) :
    scene(graphicsScene),
    label(new Label("Text", 0, 0, nullptr)) // this is owner
{
    scene->addItem(label);
    label->setIsMoving(true);
    label->showEasyChangeDialog();
    label->hide();
}

LabelAdder::~LabelAdder()
{
    if (label != nullptr) {
        scene->removeItem(label);
        delete label;
    }
}

void LabelAdder::mouseClicked(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton) {
        addLabelPermanently();
    }
}

void LabelAdder::positionChanged(const QPointF &newPosition)
{
    label->setPositionAndUpdateDialog(newPosition);
    if (!label->isVisible()) {
        label->setVisible(true);
    }
}

void LabelAdder::addLabelPermanently()
{
    label->setIsMoving(false);
    label->closeEasyChangeDialog();
    label = new Label("Text", label->x(), label->y(), nullptr); // this is owner (the old label is already managed by the scene, therefore the assignment is safe)
    scene->addItem(label);
    label->setIsMoving(true);
    label->showEasyChangeDialog();
}
