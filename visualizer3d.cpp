#include "visualizer3d.h"
#include "ui_visualizer3d.h"
#include "QDebug"

Visualizer3D::Visualizer3D(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Visualizer3D)
{
    ui->setupUi(this);
}

Visualizer3D::~Visualizer3D()
{
    delete ui;
}


void Visualizer3D::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), "*.txt");
    context.file = fileName.toStdString();
    QtSceneDrawer* drawer = new QtSceneDrawer(this);
    if (facade.show(&context))
        drawer->figures = context.scene;
        drawer->move(0, 50);
        drawer->resize(1000, 820);
        drawer->hide();
        drawer->show();
}
