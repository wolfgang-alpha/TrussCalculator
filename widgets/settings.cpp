/*
 * TrussCalculator - 2D truss structure analysis with FEM
 * Copyright (C) 2018-2019 bernhard1536
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "settings.h"

#include "widgets/lineedit.h"
#include "widgets/mainwindow.h"
#include "utilities.h"
#include "widgets/graphicsview.h"
#include "graphicsscene.h"

#include <QFormLayout>
#include <QPushButton>

void Settings::setSceneWidth()
{
    static_cast<MainWindow *>(parent())->getGraphicsView()->setMinSceneWidth(sceneWidthInput->text().toDouble());
}

void Settings::setSceneHeight()
{
    static_cast<MainWindow *>(parent())->getGraphicsView()->setMinSceneHeight(sceneHeightInput->text().toDouble());
}

void Settings::setScaleValue()
{
    static_cast<GraphicsScene *>(static_cast<MainWindow *>(parent())->getGraphicsView()->scene())->setScaleValue(scaleValueInput->text().toDouble());
}

void Settings::setMaxDisplacementDistance()
{
    static_cast<GraphicsScene *>(static_cast<MainWindow *>(parent())->getGraphicsView()->scene())->setMaxDisplacementDistance(maxDisplacementDistanceInput->text().toDouble());
}

void Settings::setDisplacementCalculationStep()
{
    static_cast<GraphicsScene *>(static_cast<MainWindow *>(parent())->getGraphicsView()->scene())->setDisplacementCalculationStep(displacementCalculationStepInput->text().toDouble());
}

Settings::Settings(MainWindow *parent) :
    QDialog(parent, Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint),
    sceneWidthInput(new LineEdit(QString::number(parent->getGraphicsView()->getMinSceneWidth()), this)),
    sceneHeightInput(new LineEdit(QString::number(parent->getGraphicsView()->getMinSceneHeight()), this)),
    scaleValueInput(new LineEdit(QString::number(static_cast<GraphicsScene *>(parent->getGraphicsView()->scene())->getScaleValue()), this)),
    maxDisplacementDistanceInput(new LineEdit(QString::number(static_cast<GraphicsScene *>(parent->getGraphicsView()->scene())->getMaxDisplacementDistance()), this)),
    displacementCalculationStepInput(new LineEdit(QString::number(static_cast<GraphicsScene *>(parent->getGraphicsView()->scene())->getDisplacementCalculationStep()), this))
{
    setWindowTitle("Einstellungen");

    // create form-layout
    QFormLayout *formLayout = new QFormLayout(); // gets reparented later
    connectLineEdit(sceneWidthInput, &Settings::setSceneWidth);
    formLayout->addRow("Minimale Breite des Zeichenbereiches [px]:", sceneWidthInput);
    connectLineEdit(sceneHeightInput, &Settings::setSceneHeight);
    formLayout->addRow("Minimale Höhe des Zeichenbereiches [px]:", sceneHeightInput);
    connectLineEdit(scaleValueInput, &Settings::setScaleValue);
    formLayout->addRow("Skalierungsfaktor [px/m]:", scaleValueInput);
    connectLineEdit(maxDisplacementDistanceInput, &Settings::setMaxDisplacementDistance);
    formLayout->addRow("Maximal gezeichnete Auslenkung [px]:", maxDisplacementDistanceInput);
    connectLineEdit(displacementCalculationStepInput, &Settings::setDisplacementCalculationStep);
    formLayout->addRow("Schrittwert bei der Deformationszeichnung [%]:", displacementCalculationStepInput);

    // create button-area
    QHBoxLayout *hBoxLayout = new QHBoxLayout(); // gets reparented later
    QPushButton *okButton = new QPushButton("Ok", this);
    connect(okButton, &QPushButton::clicked, this, &Settings::okButtonClicked);
    okButton->setAutoDefault(false); // to not activate the button when the user presses enter
    hBoxLayout->addWidget(okButton);
    QPushButton *cancelButton = new QPushButton("Abbrechen", this);
    connect(cancelButton, &QPushButton::clicked, this, &Settings::hide); // hide the dialog without saving changes when cancel-button is clicked
    cancelButton->setAutoDefault(false); // see okButton
    hBoxLayout->addWidget(cancelButton);

    // combine form-layout with button-area
    QVBoxLayout *vBoxLayout = new QVBoxLayout(); // gets reparented later
    vBoxLayout->addLayout(formLayout);
    vBoxLayout->addLayout(hBoxLayout);
    setLayout(vBoxLayout); // reparents everything contained within the layouts to this

    setFixedSize(sizeHint()); // make dialog not resizeable
}

void Settings::connectLineEdit(LineEdit *lineEdit, void (Settings::*slot)())
{
    Utilities::connectLineEditToDoneSignal(lineEdit, this, slot);
}

void Settings::okButtonClicked() // save contents of line-edits
{
    sceneWidthInput->returnPressed();
    sceneHeightInput->returnPressed();
    scaleValueInput->returnPressed();
    maxDisplacementDistanceInput->returnPressed();
    displacementCalculationStepInput->returnPressed();
    close();
}
