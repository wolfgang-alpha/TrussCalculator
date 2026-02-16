#ifndef DIMENSION_H
#define DIMENSION_H

#include "trusselement.h"
#include "pen.h"

class Node;
class Label;

enum class Orientation {
    Horizontal = 0,
    Vertical = 1
};

class Dimension : public TrussElement
{
    Q_OBJECT

public:
    Dimension(Node *elementNode1 = nullptr, Node *elementNode2 = nullptr);
    ~Dimension() override;
    // disable copy-/move-operations because of member-ptrs, implement later if needed
    Dimension(const Dimension &) = delete;
    Dimension(Dimension &&) = delete;
    Dimension &operator =(const Dimension &) = delete;
    Dimension &operator =(Dimension &&) = delete;

    bool isForLongMeasurement() const;

    double getBaselinePos() const { return baselinePos; }
    void setBaselinePos(double newBaselinePos);

    Orientation getOrientation() const { return orientation; }
    void setOrientation(Orientation newOrientation);

    Node *getNode1() const { return node1; }
    Node *getNode2() const { return node2; }
    Node *takeNode1();
    Node *takeNode2();
    void setNode2(Node *newNode2); // this fct overrides the old ptr to node2
    void linkNode1(Node *newNode1);
    void linkNode2(Node *newNode2);

    void forwardPrepareGeometryChange();

    void moveLabelX(double distance);
    void moveLabelY(double distance);

    void setLabel(Label *newLabel);

private:
    Id<Dimension> id;
    Node *node1; // weak ptr
    Node *node2; // weak ptr
    double baselinePos;
    int arrowWidth;
    int arrowHeight;
    int minimumArrowToArrowDistance;
    int borderLineSupernatant;
    int baseLineSupernatant;
    Orientation orientation;
    Pen pen;
    Label *label; // this is parent
    int initialDimensionLabelDistance;

    // TrussElement interface
public:
    EasyChangeDialog *createEasyChangeDialog() override; // passes ownership to caller
    QString getElementSelectionDialogButtonText() const override;
    QString getId() const override;
    QJsonObject saveAsJson() const override;
    void loadFromJson(const QJsonObject &object) override;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // DIMENSION_H
