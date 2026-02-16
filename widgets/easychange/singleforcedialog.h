#ifndef SINGLEFORCEDIALOG_H
#define SINGLEFORCEDIALOG_H

#include "widgets/easychange/easychangedialog.h"

class SingleForce;

class SingleForceDialog : public EasyChangeDialog
{
    Q_OBJECT

public:
    SingleForceDialog(QWidget *parent, SingleForce *singleForce);
    // see base class
    ~SingleForceDialog() = default;
    SingleForceDialog(const SingleForceDialog &) = delete;
    SingleForceDialog(SingleForceDialog &&) = default;
    SingleForceDialog &operator =(const SingleForceDialog &) = delete;
    SingleForceDialog &operator =(SingleForceDialog &&) = delete;

    void setValue();
    void setAngle();

private:
    SingleForce *force; // weak ptr
    LineEdit *valueInput; // parent is this
    LineEdit *angleInput; // parent is this

    // EasyChangeDialog interface
public:
    void okPressed(bool) override;
    void updateDialog() override;
};

#endif // SINGLEFORCEDIALOG_H
