#include "seteaiglobaldialog.h"
#include "ui_seteaiglobaldialog.h"

#include "utilities.h"
#include "elements/rod.h"

SetEAIGlobalDialog::SetEAIGlobalDialog(GraphicsScene *graphicsScene, QMainWindow *parent) :
    QDialog(parent, Qt::WindowTitleHint),
    ui(new Ui::SetEAIGlobalDialog),
    scene(graphicsScene)
{
    ui->setupUi(this);
    setWindowTitle("Werteeingabe");
}

SetEAIGlobalDialog::~SetEAIGlobalDialog()
{
    delete ui;
}

void SetEAIGlobalDialog::on_okButton_clicked()
{
    for (auto rod : Utilities::getAllElementsOfType<Rod *>(scene->items())) { // save the entered values if the checkbox corresponding the variable is true
        if (ui->EBox->isChecked()) {
            rod->setE(ui->EInput->text().toDouble());
        }
        if (ui->ABox->isChecked()) {
            rod->setA(ui->AInput->text().toDouble());
        }
        if (ui->IBox->isChecked()) {
            rod->setI(ui->IInput->text().toDouble());
        }
    }
    close();
}

void SetEAIGlobalDialog::on_cancelButton_clicked()
{
    close();
}
