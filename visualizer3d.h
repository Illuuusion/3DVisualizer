#ifndef VISUALIZER3D_H
#define VISUALIZER3D_H

#include <QMainWindow>
#include "qtscenedrawer.h"
#include "scene.h"
#include "facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Visualizer3D; }
QT_END_NAMESPACE

class Visualizer3D : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer3D(QWidget *parent = nullptr);
    ~Visualizer3D();

private slots:
    void on_loadButton_clicked();

private:
    Ui::Visualizer3D *ui;
    AppContext context;
    Facade facade;
};
#endif // VISUALIZER3D_H
