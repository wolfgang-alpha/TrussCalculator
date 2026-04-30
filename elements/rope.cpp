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

#include "rope.h"

Rope::Rope() :
    Rod()
{
    pen.setWidth(3);
}

Rope::Rope(Node *elementNode1, Node *elementNode2) :
    Rod(elementNode1, elementNode2)
{
    pen.setWidth(3);
}
