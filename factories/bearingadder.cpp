#include "bearingadder.h"

#include "elements/bearing.h"
#include "elements/node.h"
#include "utilities.h"

BearingAdder::BearingAdder()
{
}

void BearingAdder::mouseClicked(QGraphicsSceneMouseEvent *event, Node *node)
{
    if (event->buttons() == Qt::LeftButton) {
        if (node == nullptr) { // user clicked on empty scene-space, do nothing
            return;
        } else if (!Utilities::getAllElementsOfType<Bearing *>(node->childItems()).isEmpty()) { // if the node has already a bearing attached to it, don't add another one
            return;
        } else { // create new bearing and add it to the scene
            auto bearing = new Bearing(node); // the ownership is passed to the node (=parent) (the item is automatically added to the scene by the node)
            bearing->showEasyChangeDialog(); // show its dialog
        }
    }
}
