#ifndef LOCATINGBEARINGDIALOG_H
#define LOCATINGBEARINGDIALOG_H

#include "easychangedialog.h"

#include <QComboBox>
#include <QLabel>

class LineEdit;
class Bearing;

class BearingDialog : public EasyChangeDialog
{
    Q_OBJECT

public:
    BearingDialog(QWidget *parent, Bearing *elementBearing);
    // see base class
    ~BearingDialog() = default;
    BearingDialog(const BearingDialog &) = delete;
    BearingDialog(BearingDialog &&) = delete;
    BearingDialog &operator =(const BearingDialog &) = delete;
    BearingDialog &operator =(BearingDialog &&) = delete;

    void setAngle();
    void setType(int index);

private:
    Bearing *bearing; // weak ptr
    LineEdit *angleInputLineEdit; // parent is this
    QComboBox *typeInput; // parent is this
    QLabel *xForceLabel; // parent is this
    QLabel *yForceLabel; // parent is this
    QLabel *zMomentLabel; // parent is this

    // EasyChangeDialog interface
public:
    void okPressed(bool) override;
    void updateDialog() override;
};

#endif // LOCATINGBEARINGDIALOG_H
