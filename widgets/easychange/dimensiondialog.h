#ifndef DIMENSIONDIALOG_H
#define DIMENSIONDIALOG_H

#include "easychangedialog.h"

class Dimension;
class LineEdit;
class QComboBox;

class DimensionDialog : public EasyChangeDialog
{
    Q_OBJECT

public:
    DimensionDialog(QWidget *parent, Dimension *underlyingElement);
    // see base class
    ~DimensionDialog() = default;
    DimensionDialog(const DimensionDialog &) = delete;
    DimensionDialog(DimensionDialog &&) = delete;
    DimensionDialog &operator =(const DimensionDialog &) = delete;
    DimensionDialog &operator =(DimensionDialog &&) = delete;


    void setBaselinePos();
    void setDimensionOrientation();

private:
    Dimension *dimension;
    LineEdit *baselinePosInput;
    QComboBox *orientationInput;

    // EasyChangeDialog interface
public:
    void okPressed(bool) override;
    void updateDialog() override;
};

#endif // DIMENSIONDIALOG_H
