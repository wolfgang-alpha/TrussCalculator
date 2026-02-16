#include "forceadder.h"

#include "elements/singleforce.h"
#include "elements/node.h"
#include "utilities.h"

ForceAdder::ForceAdder()
{
}

void ForceAdder::mouseClicked(QGraphicsSceneMouseEvent *event, Node *node)
{
    if (event->buttons() == Qt::LeftButton) {
        if (node == nullptr) { // user clicked on empty scene-space, do nothing
            return;
        } else { // create new bearing and add it to the scene
            auto force = new SingleForce(node); // the ownership is passed to the node (=parent) (the item is automatically added to the scene by the node)
            force->showEasyChangeDialog(); // show its dialog
        }
    }
}
