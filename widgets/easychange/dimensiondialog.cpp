#include "dimensiondialog.h"

#include "elements/dimension.h"

#include <QComboBox>
#include <QFormLayout>

DimensionDialog::DimensionDialog(QWidget *parent, Dimension *underlyingElement) :
    EasyChangeDialog(parent, underlyingElement),
    dimension(underlyingElement),
    baselinePosInput(new LineEdit(QString::number(underlyingElement->getOrientation() == Orientation::Vertical ? underlyingElement->getBaselinePos() : - underlyingElement->getBaselinePos()), this)), // parent is this, flip y-axis if horizontal
    orientationInput(new QComboBox(this)) // parent is this
{
    auto layout = new QFormLayout(); // parent gets set later
    connectLineEdit(baselinePosInput, this, &DimensionDialog::setBaselinePos);
    layout->addRow("Position der Grundlinie [px]:", baselinePosInput);
    orientationInput->insertItem(0, "Horizontal"); // the indexes of the combobox-items have to be the same as in the Orientation-enum
    orientationInput->insertItem(1, "Vertikal");
    orientationInput->setCurrentIndex(static_cast<int>(dimension->getOrientation()));
    connect(orientationInput, qOverload<int>(&QComboBox::currentIndexChanged), this, &DimensionDialog::setDimensionOrientation);
    layout->addRow("Ausrichtung:", orientationInput);

    auto l = new QHBoxLayout(); // parent gets set later
    l->addLayout(layout);
    setupEasyChangeDialog(l); // reparents layout and l to this
}

void DimensionDialog::setBaselinePos()
{

    dimension->setBaselinePos(dimension->getOrientation() == Orientation::Vertical ? baselinePosInput->text().toDouble() : - baselinePosInput->text().toDouble()); // flip y-axis if horizontal
}

void DimensionDialog::setDimensionOrientation()
{
    dimension->setOrientation(static_cast<Orientation>(orientationInput->currentIndex()));
}

void DimensionDialog::okPressed(bool)
{
    setBaselinePos();
    setDimensionOrientation();
    close();
}

void DimensionDialog::updateDialog()
{
    baselinePosInput->setText(QString::number(dimension->getOrientation() == Orientation::Vertical ? dimension->getBaselinePos() : - dimension->getBaselinePos())); // flip y-axis if horizontal
    orientationInput->setCurrentIndex(static_cast<int>(dimension->getOrientation()));
}
