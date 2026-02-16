#include "elementselectiondialog.h"

#include "elements/trusselement.h"
#include "widgets/graphicsview.h"

#include <QVBoxLayout>
#include <QPushButton>

ElementSelectionDialog::ElementSelectionDialog(QList<TrussElement *> elementList, GraphicsView *parent) :
    QDialog(parent, Qt::CustomizeWindowHint)
{
    QVBoxLayout *layout = new QVBoxLayout(); // gets reparented later
    for (TrussElement *element : elementList) { // add for each element a button with a descriptive text
        QPushButton *button = new QPushButton(element->getElementSelectionDialogButtonText(), this); // parent is this
        connect(button, &QPushButton::clicked, element, &TrussElement::showEasyChangeDialog); // if the user clicks on a button, select the corresponding element and show its dialog
        connect(button, &QPushButton::clicked, this, &QDialog::close);
        layout->addWidget(button);
    }
    setLayout(layout); // dialog takes ownership of layout
    setFixedSize(sizeHint()); // make dialog not resizeable
}

void ElementSelectionDialog::keyPressEvent(QKeyEvent *event) // forward key-events to graphicsview to close the dialog when the user releases shift
{
    static_cast<GraphicsView *>(parent())->forwardKeyPressEvent(event);
}

void ElementSelectionDialog::keyReleaseEvent(QKeyEvent *event)
{
    static_cast<GraphicsView *>(parent())->forwardKeyReleaseEvent(event);
}
