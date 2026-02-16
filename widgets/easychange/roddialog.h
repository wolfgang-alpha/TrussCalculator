#ifndef RODDIALOG_H
#define RODDIALOG_H

#include "easychangedialog.h"

#include <QLabel>
#include <QComboBox>

class Rod;

class RodDialog : public EasyChangeDialog
{
    Q_OBJECT

public:
    RodDialog(QWidget *parent, Rod *elementRod);
    // see base class
    ~RodDialog() = default;
    RodDialog(const RodDialog &) = delete;
    RodDialog(RodDialog &&) = delete;
    RodDialog &operator =(const RodDialog &) = delete;
    RodDialog &operator =(RodDialog &&) = delete;

    void setE();
    void setA();
    void setI();

private:
    Rod *rod; // weak ptr
    QLabel *rodForceLabel; // parent is this
    QLabel *u1xLabel; // parent is this
    QLabel *u1yLabel; // parent is this
    QLabel *u1zLabel; // parent is this
    QLabel *u2xLabel; // parent is this
    QLabel *u2yLabel; // parent is this
    QLabel *u2zLabel; // parent is this
    LineEdit *EInput; // parent is this
    LineEdit *AInput; // parent is this
    LineEdit *IInput; // parent is this

    // EasyChangeDialog interface
public:
    void okPressed(bool) override;
    void updateDialog() override;
};

#endif // RODDIALOG_H
