#ifndef NODE_H
#define NODE_H

#include "trusselement.h"
#include "pen.h"

#include "libs/Eigen/Eigen/Eigen"

class Rod;
class Bearing;
class Label;
class Dimension;

enum class NodeType : int {
    GerberJoint = 0,
    Weld = 1
};

class Node : public TrussElement
{
    Q_OBJECT

public:
    explicit Node(); // default ctor
    Node(double xPosition, double yPosition, NodeType type = NodeType::GerberJoint);
    ~Node() override;
    // disable copy-/move-operations because of member-ptrs, implement later if needed
    Node(const Node &) = delete;
    Node(Node &&) = delete;
    Node &operator =(const Node &) = delete;
    Node &operator =(Node &&) = delete;

    void addRod(Rod *rod);
    void removeRod(Rod *rod);
    int getNumberOfRods() const;
    QList<Rod *> getRods() const { return rods; }

    Bearing *getBearing() const; // returns (potentially nullptr) weak ptr

    double getRadius() const { return radius; }

    Label *getLabel() const { return label; } // returns weak ptr
    void setLabel(Label *newLabel); // if label exists already, it is deleted and then label is set to newLabel

    void addDimension(Dimension *dimension);
    void removeDimension(Dimension *dimension);

    NodeType getNodeType() const { return nodeType; }
    void setNodeType(NodeType newType);

    void setFx(double newFx) { fx = newFx; }
    double getFx() const { return fx; }
    void setFy(double newFy) { fy = newFy; }
    double getFy() const { return fy; }
    void setMz(double newMz) { mz = newMz; }
    double getMz() const { return mz; }

    void setCalcId(int internCalcId) { calcId = internCalcId; }
    int getCalcId() const { return calcId; }

    bool hasAppliedForce() const;
    Eigen::Vector2d getResultingAppliedForce() const;
    double getResultingAppliedMoment() const;

    double getUx() const;
    double getUy() const;

protected:
    NodeType nodeType;
    Pen pen;
    double radius;
    QList<Rod *> rods; // list of weak ptrs
    Id<Node> id;
    Label *label; // this is parent
    QList<Dimension *> dimensions; // list of weak ptrs

    double fx; // positive: right (global) [N]
    double fy; // positive: up [N]
    double mz; // positive: counterclockwise [Nm]
    int calcId;

    // TrussElement interface
public:
    EasyChangeDialog *createEasyChangeDialog() override;
    void setYPos(double newYPos) override;
    void setXPos(double newXPos) override;
    QString getElementSelectionDialogButtonText() const override;
    QString getId() const override;
    QJsonObject saveAsJson() const override;
    void loadFromJson(const QJsonObject &object) override;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // NODE_H
