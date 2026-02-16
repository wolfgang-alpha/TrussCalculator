#include "pen.h"

Pen::Pen(const Color &color, qreal width, Qt::PenCapStyle cap) :
    QPen(QBrush(color), width, Qt::SolidLine, cap, Qt::BevelJoin),
    c(color)
{
}

Pen Pen::differentColor(const Color &otherColor)
{
    Pen pen = Pen(*this); // copy pen
    pen.setColor(otherColor);
    return pen;
}

Pen Pen::differentWidth(int otherWidth)
{
    Pen pen = Pen(*this); // copy pen
    pen.setWidth(otherWidth);
    return pen;
}
