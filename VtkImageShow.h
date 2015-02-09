#ifndef VTKIMAGESHOW_H
#define VTKIMAGESHOW_H

#include "QMainWindow"
#include "vtkSmartPointer.h"
#include "ui_VtkImageShow.h"

class vtkImageViewer2;
class vtkRenderer;


class VtkImageShow : public QMainWindow, private Ui::VtkImageWindow {

Q_OBJECT

public:
    VtkImageShow();
    ~VtkImageShow();

private slots:
    void onFileOpenSlot();

private:
    vtkSmartPointer<vtkImageViewer2> m_pImageViewer;
    vtkSmartPointer<vtkRenderer> m_pRenderer;
};

#endif // VTKIMAGESHOW_H

