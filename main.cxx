#include "VtkImageShow.h"
#include "QApplication"

int main(int argc, char *argv[]) {

    QApplication *app = new QApplication(argc, argv);
    VtkImageShow *vtkImageShow = new VtkImageShow();

    vtkImageShow->show();

    return app->exec();
}