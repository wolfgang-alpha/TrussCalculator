#include "labeldialog.h"

#include "widgets/lineedit.h"
#include "elements/dimension.h"

#include <QFormLayout>

LabelDialog::LabelDialog(QWidget *parent, Label *elementLabel) :
    EasyChangeDialog(parent, elementLabel),
    label(elementLabel),
    textInput(new LineEdit(elementLabel->getText(), this)), // parent is this
    xPosInput(new LineEdit(QString::number(elementLabel->x()), this)), // parent is this
    yPosInput(new LineEdit(QString::number(- elementLabel->y()), this)) // parent is this, flip y-axis
{
    auto formLayout = new QFormLayout(); // parent gets set later
    if (label->parentItem() == nullptr || dynamic_cast<Dimension *>(label->parentItem()) != nullptr) { // if there is no parent or if it is a dimension, make the text editable
        connectLineEdit(textInput, this, &LabelDialog::setText);
        formLayout->addRow("Text:", textInput);
    } else {
        textInput->hide();
    }
    connectLineEdit(xPosInput, this, &LabelDialog::setXPos);
    formLayout->addRow("x-Position:", xPosInput);
    connectLineEdit(yPosInput, this, &LabelDialog::setYPos);
    formLayout->addRow("y-Position:", yPosInput);

    auto layout = new QHBoxLayout(); // parent gets set later
    layout->addLayout(formLayout);
    setupEasyChangeDialog(layout); // reparents the layouts
}

void LabelDialog::setText()
{
    auto dim = label->parentItem() != nullptr ? dynamic_cast<Dimension *>(label->parentItem()) : nullptr;
    label->setText(textInput->text(), dim != nullptr ? dim->getOrientation() == Orientation::Horizontal : false); // center the text if the parent is a horizontal dimension
}

void LabelDialog::setXPos()
{
    label->setXPos(xPosInput->text().toDouble());
}

void LabelDialog::setYPos()
{
    label->setYPos(- yPosInput->text().toDouble()); // flip y-axis
}

void LabelDialog::okPressed(bool)
{
    setXPos();
    setYPos();
    setText(); // this fct updates the values in the x- and y-input-lineEdits, therefore save those values (via calling set_Pos) before saving the text (= calling this fct)
    addLabelPermanentlyToScene();
    label->closeEasyChangeDialog();
}

void LabelDialog::updateDialog()
{
    textInput->setText(label->getText());
    xPosInput->setText(QString::number(label->x()));
    yPosInput->setText(QString::number(- label->y())); // flip y-axis
}
