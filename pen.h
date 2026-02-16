#ifndef PEN_H
#define PEN_H

#include "color.h"

#include <QPen>

class Pen final : public QPen
{
public:
    explicit Pen(const Color &color = Color(), qreal width = 1, Qt::PenCapStyle cap = Qt::RoundCap);
    // QPen has no virtual destructor, therefore be careful when deleting ptrs to Pen via ptrs to QPen (it is safest to use no ptrs to Pen at all)!!!

    Color getColor() const { return c; }

    Pen differentColor(const Color &otherColor); // return a copy of this pen with a different color
    Pen differentWidth(int otherWidth); // return a copy of this pen with a different width

private:
    Color c;
};

#endif // PEN_H
