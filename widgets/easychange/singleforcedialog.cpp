#include "singleforcedialog.h"

#include "elements/singleforce.h"
#include "widgets/lineedit.h"

#include <QFormLayout>

SingleForceDialog::SingleForceDialog(QWidget *parent, SingleForce *singleForce) :
    EasyChangeDialog(parent, singleForce),
    force(singleForce),
    valueInput(new LineEdit(this)),
    angleInput(new LineEdit(this))
{
    auto formLayout = new QFormLayout(); // parent gets set later
    valueInput->setText(QString::number(force->getValue()));
    connectLineEdit(valueInput, this, &SingleForceDialog::setValue);
    formLayout->addRow("Wert [N]:", valueInput);
    angleInput->setText(QString::number(force->getAngle() * 180 / M_PI - 180));
    connectLineEdit(angleInput, this, &SingleForceDialog::setAngle);
    formLayout->addRow("Winkel [°]:", angleInput);

    auto hBoxLayout = new QHBoxLayout(); // gets reparented later
    hBoxLayout->addLayout(formLayout);
    setupEasyChangeDialog(hBoxLayout); // reparents the above created layouts
}

void SingleForceDialog::setValue()
{
    force->setValue(valueInput->text().toDouble());
}

void SingleForceDialog::setAngle()
{
    force->setAngle((angleInput->text().toDouble() + 180) * M_PI / 180);
}

void SingleForceDialog::okPressed(bool)
{
    setValue();
    setAngle();
    force->closeEasyChangeDialog();
}

void SingleForceDialog::updateDialog()
{
    valueInput->setText(QString::number(force->getValue()));
    angleInput->setText(QString::number(force->getAngle() * 180 / M_PI));
}
