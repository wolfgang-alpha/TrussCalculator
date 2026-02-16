#include "lineedit.h"

LineEdit::LineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

LineEdit::LineEdit(const QString &contents, QWidget *parent) :
    QLineEdit(contents, parent)
{
}
