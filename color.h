#ifndef COLOR_H
#define COLOR_H

#include <QColor>

class Color final : public QColor
{
public:
    explicit Color(Qt::GlobalColor color = Qt::black); // default color is black
    Color(int r, int g, int b, int a = 255);
};

#endif // COLOR_H
