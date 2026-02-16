#ifndef SYSTEMDEFINITIONDIALOG_H
#define SYSTEMDEFINITIONDIALOG_H

#include <QDialog>

class GraphicsScene;
class QTableView;
class QStandardItemModel;
class Node;
class Rod;
class Bearing;
class SingleForce;
class QGraphicsItem;

namespace Ui {
class SystemDefinitionDialog;
} // end namespace Ui

class SystemDefinitionDialog : public QDialog
{
    Q_OBJECT

public:
    SystemDefinitionDialog(GraphicsScene *graphicsScene, QWidget *parent);
    virtual ~SystemDefinitionDialog() override;

private:
    Ui::SystemDefinitionDialog *ui; // deleted in dtor

    void populateModel(QStandardItemModel *model, QList<Node *> list);
    void populateModel(QStandardItemModel *model, QList<Rod *> list);
    void populateModel(QStandardItemModel *model, QList<Bearing *> list);
    void populateModel(QStandardItemModel *model, QList<SingleForce *> list);

    template<typename T>
    void setupTable(QTableView *view, const QList<QGraphicsItem *> &items, const QStringList &horizontalHeaderLabels);

    // QWidget interface
private slots:
    void on_tabWidget_currentChanged(int index);
    void on_okButton_clicked();
};

#endif // SYSTEMDEFINITIONDIALOG_H
