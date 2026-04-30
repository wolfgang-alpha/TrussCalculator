/*
 * TrussCalculator - 2D truss structure analysis with FEM
 * Copyright (C) 2018-2019 bernhard1536
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "color.h"

Color::Color(Qt::GlobalColor color) :
    QColor(color)
{
}

Color::Color(int r, int g, int b, int a) :
    QColor(r, g, b, a)
{
}
