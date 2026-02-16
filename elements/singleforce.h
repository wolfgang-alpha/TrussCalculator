#ifndef SINGLEFORCE_H
#define SINGLEFORCE_H

#include "trusselement.h"
#include "pen.h"

class Node;

class SingleForce : public TrussElement
{
    Q_OBJECT

public:
    explicit SingleForce(Node *parentNode = nullptr, double elementValue = 0, double elementAngle = 3 * M_PI_2);
    ~SingleForce() override = default;
    // disable copying/moving (implement later if necessary)
    SingleForce(const SingleForce &) = delete;
    SingleForce(SingleForce &&) = delete;
    SingleForce &operator =(const SingleForce &) = delete;
    SingleForce &operator =(SingleForce &&) = delete;

    void setValue(double newValue);
    double getValue() const { return value; }

    void setAngle(double newAngle);
    double getAngle() const { return angle; }

private:
    Pen pen;
    int arrowWidth; // [px]
    int arrowHeight; // [px]
    int length; // [px]
    double value; // [N]
    double angle; // [rad], 0 = right, positive = counterclockwise
    Id<SingleForce> id;

    // TrussElement interface
public:
    EasyChangeDialog *createEasyChangeDialog() override;
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
    void mouseMoveEvent(QGraphicsSceneMouseEvent *) override {} // mouse should not be moveable
};

#endif // SINGLEFORCE_H
