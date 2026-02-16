#include "color.h"

Color::Color(Qt::GlobalColor color) :
    QColor(color)
{
}

Color::Color(int r, int g, int b, int a) :
    QColor(r, g, b, a)
{
}
