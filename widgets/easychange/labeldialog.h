#ifndef LABELDIALOG_H
#define LABELDIALOG_H

#include "easychangedialog.h"
#include "elements/label.h"

class LabelDialog : public EasyChangeDialog
{
    Q_OBJECT

public:
    LabelDialog(QWidget *parent, Label *elementLabel);
    // see base class
    ~LabelDialog() = default;
    LabelDialog(const LabelDialog &) = delete;
    LabelDialog(LabelDialog &&) = delete;
    LabelDialog &operator =(const LabelDialog &) = delete;
    LabelDialog &operator =(LabelDialog &&) = delete;

    void setText();
    void setXPos();
    void setYPos();

private:
    Label *label; // weak ptr
    LineEdit *textInput; // parent is this
    LineEdit *xPosInput; // parent is this
    LineEdit *yPosInput; // parent is this

    // EasyChangeDialog interface
public:
    void okPressed(bool) override;
    void updateDialog() override;
};

#endif // LABELDIALOG_H
