#include "nodeadder.h"

#include "elements/node.h"
#include "graphicsscene.h"

NodeAdder::NodeAdder(GraphicsScene *graphicsScene) :
    scene(graphicsScene),
    node(new Node(0, 0)) // node gets either passed to scene permanently or deleted in dtor
{
    scene->addItem(node);
    node->setIsMoving(true);
    node->showEasyChangeDialog(); // setIsInSelection(true) is called by this fct
    node->hide(); // hide node and show it when the mouse is in the graphics-view
}

NodeAdder::~NodeAdder()
{
    if (node != nullptr) {
        scene->removeItem(node); // do not call removeElement
        delete node; // delete node if not added to scene permanently
    }
}

void NodeAdder::positionChanged(const QPointF &newPosition) // newPosition is in scene-coords, therefore no conversion needed
{
    node->setPositionAndUpdateDialog(newPosition);
    if (!node->isVisible()) { // show node when the mouse moves for the first time on the scene (because then the node can be drawn under the mouse)
        node->show();
    }
}

void NodeAdder::mouseClicked(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton) {
        addNodePermanently();
    }
}

void NodeAdder::addNodePermanently()
{
    node->setIsMoving(false);
    node->closeEasyChangeDialog();
    node = new Node(node->x(), node->y()); // node is managed by the scene therefore it is safe to create a new node and add it to the scene (at the same position as the old one)
    scene->addItem(node); // add the node immediately after creation to the scene  (for memory management, if node gets overwritten the scene has still a ptr to it)
    node->setIsMoving(true);
    node->showEasyChangeDialog();
}
