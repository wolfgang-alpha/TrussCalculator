#ifndef SETEAIGLOBALDIALOG_H
#define SETEAIGLOBALDIALOG_H

#include "graphicsscene.h"

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class SetEAIGlobalDialog;
}

class SetEAIGlobalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetEAIGlobalDialog(GraphicsScene *graphicsScene, QMainWindow *parent); // *scene is a weak-ptr
    virtual ~SetEAIGlobalDialog();

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::SetEAIGlobalDialog *ui;
    GraphicsScene *scene; // weak ptr
};

#endif // SETEAIGLOBALDIALOG_H
