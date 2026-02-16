#ifndef ELEMENTSELECTIONDIALOG_H
#define ELEMENTSELECTIONDIALOG_H

#include <QDialog>

class TrussElement;
class GraphicsView;

class ElementSelectionDialog final : public QDialog
{
    Q_OBJECT

public:
    ElementSelectionDialog(QList<TrussElement *> elementList, GraphicsView *parent = nullptr);

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // ELEMENTSELECTIONDIALOG_H
