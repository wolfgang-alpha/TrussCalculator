#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

class LineEdit;
class MainWindow;

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(MainWindow *parent); // parent is a weak-ptr but the mainwindow outlives this class therefore no nullptr-checks against the parent are needed
    ~Settings() = default;
    Settings(const Settings &) = delete; // prevent copies/moving of the singleton
    Settings(Settings &&) = delete;
    Settings &operator =(const Settings &) = delete;
    Settings &operator =(Settings &&) = delete;

    void setSceneWidth();
    void setSceneHeight();
    void setScaleValue();
    void setMaxDisplacementDistance();
    void setDisplacementCalculationStep();

private:
    void connectLineEdit(LineEdit *lineEdit, void (Settings::*slot)()); // provided to reduce writing in this class
    void okButtonClicked();

    LineEdit *sceneWidthInput; // parent is this
    LineEdit *sceneHeightInput; // parent is this
    LineEdit *scaleValueInput; // parent is this
    LineEdit *maxDisplacementDistanceInput; // parent is this
    LineEdit *displacementCalculationStepInput; // parent is this
};

#endif // SETTINGS_H
