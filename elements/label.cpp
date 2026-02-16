#include "label.h"

#include "pen.h"
#include "widgets/easychange/labeldialog.h"
#include "jsonkeys.h"

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QJsonObject>

Label::Label(QString labelText, double xPosition, double yPosition, TrussElement *parent) :
    TrussElement(xPosition, yPosition, parent),
    id(Id<Label>()),
    text(labelText),
    pen(Pen(Color(Qt::black))),
    font(QFont("Helvetica", 16)),
    offset(QPointF(0, 0))
{
    setZValue(ElementZValue::Label_);
}

void Label::setText(const QString &newText, bool centerX)
{
    prepareGeometryChange();
    if (centerX) {
        QFontMetrics fm(font);
        setXPos(x() + fm.width(text) / 2 - fm.width(newText) / 2);
    }
    text = newText;
    updateEasyChangeDialog();
}

int Label::getTextWidth() const
{
    QFontMetrics fm(font);
    return fm.width(text);
}

int Label::getTextHeight() const
{
    QFontMetrics fm(font);
    return fm.capHeight();
}

void Label::setColor(const Color &newColor)
{
    prepareGeometryChange(); // do not call update() because this could (rarely but possibly) lead to buggy behavior
    pen = pen.differentColor(newColor);
}

EasyChangeDialog *Label::createEasyChangeDialog()
{
    return new LabelDialog(scene()->views().first(), this); // gets handled by the truss-element
}

QString Label::getElementSelectionDialogButtonText() const
{
    return QString("Beschriftung (ID: ") + getId() + QString(")");
}

QString Label::getId() const
{
    return id.toString();
}

QJsonObject Label::saveAsJson() const
{
    QJsonObject o(TrussElement::saveAsJson());
    o.insert(JsonKeys::id, getId());
    o.insert(JsonKeys::text, text);
    o.insert(JsonKeys::elementType, static_cast<int>(ElementType::Label));
    return o;
}

void Label::loadFromJson(const QJsonObject &object)
{
    TrussElement::loadFromJson(object);
    id.resetId(object.value(JsonKeys::id).toString());
    text = object.value(JsonKeys::text).toString();
}

QRectF Label::boundingRect() const
{
    QFontMetrics fm(font);
    return {0, (double) - fm.ascent(), (double) fm.width(text), (double) fm.height()}; // yPos is baseline of text
}

void Label::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setPen(pen);
    if (isUnderHoverAction) {
        painter->setPen(pen.differentColor(hoverPenColor));
    }
    if (isInSelection) {
        painter->setPen(pen.differentColor(selectionPenColor));
    }
    painter->setFont(font);
    painter->drawText(0, 0, text);
    painter->restore();
}

void Label::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (isMoving) {
        setPositionAndUpdateDialog(mapToParent(event->pos()) - offset); // map to parent because this->x() and this->y() are in parent-coords while event->pos() is in item-coords
        event->accept();
    } else {
        QGraphicsObject::mouseMoveEvent(event);
    }
}

void Label::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    offset = mapToParent(event->pos()) - pos(); // offset between the mouse-cursor and the origin of the label
    TrussElement::mousePressEvent(event);
}

void Label::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if (parentItem() != nullptr) {
        static_cast<TrussElement *>(parentItem())->setIsUnderHoverAction(true);
    }
    TrussElement::hoverEnterEvent(event);
}

void Label::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (parentItem() != nullptr) {
        static_cast<TrussElement *>(parentItem())->setIsUnderHoverAction(false);
    }
    TrussElement::hoverLeaveEvent(event);
}
