#ifndef LABEL_H
#define LABEL_H

#include "trusselement.h"
#include "pen.h"

#include <QFont>

class Label : public TrussElement
{
    Q_OBJECT

public:
    Label(QString labelText = "", double xPosition = 0, double yPosition = 0, TrussElement *parent = nullptr);
    ~Label() override = default;
    // disable copy-/move-operations, implement later if needed
    Label(const Label &) = delete;
    Label(Label &&) = delete;
    Label &operator =(const Label &) = delete;
    Label &operator =(Label &&) = delete;

    QString getText() const { return text; }
    void setText(const QString &newText, bool centerX = false); // if center is true, the new text gets centered around the center of the current text

    int getTextWidth() const;
    int getTextHeight() const;

    void setColor(const Color &newColor);

private:
    Id<Label> id;
    QString text;
    Pen pen;
    QFont font;
    QPointF offset;

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
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // LABEL_H
