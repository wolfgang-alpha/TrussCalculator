#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class LineEdit final : public QLineEdit
{
    Q_OBJECT

public:
    explicit LineEdit(QWidget *parent = nullptr);
    explicit LineEdit(const QString &contents, QWidget *parent = nullptr);

    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *) override {} // override to show nothing
};

#endif // LINEEDIT_H
