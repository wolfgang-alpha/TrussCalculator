#ifndef NODEDIALOG_H
#define NODEDIALOG_H

#include "easychangedialog.h"

#include <QComboBox>
#include <QLabel>

class Node;

class NodeDialog : public EasyChangeDialog
{
    Q_OBJECT

public:
    NodeDialog(QWidget *parent, Node *elementNode);
    // see base class
    ~NodeDialog() = default;
    NodeDialog(const NodeDialog &) = delete;
    NodeDialog(NodeDialog &&) = delete;
    NodeDialog &operator =(const NodeDialog &) = delete;
    NodeDialog &operator =(NodeDialog &&) = delete;

    void setXPos();
    void setYPos();
    void setType(int newType);

private:
    Node *node; // weak ptr
    QLabel *idLabel; // parent is this
    LineEdit *xPosInput; // parent is this
    LineEdit *yPosInput; // parent is this
    QComboBox *typeBox; // parent is this
    QLabel *uxLabel; // parent is this
    QLabel *uyLabel; // parent is this

    // EasyChangeDialog interface
public:
    void okPressed(bool) override;
    void updateDialog() override;
};

#endif // NODEDIALOG_H
