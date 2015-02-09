// Head file of this project
#include "VtkImageShow.h"

// Qt
#include "QFileDialog"

// VTK
#include "vtkImageViewer2.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkPNGReader.h"

#define VTK_CREATE(type, name) \
        vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

// Constructor
VtkImageShow::VtkImageShow() {

    setupUi(this);

    m_pImageViewer = vtkSmartPointer<vtkImageViewer2>::New();
    m_pRenderer    = vtkSmartPointer<vtkRenderer>::New();

    m_QVTKWidget->GetRenderWindow()->AddRenderer(m_pRenderer);

    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(onFileOpenSlot()));
}

// Deconstructor should be given explicitly
VtkImageShow::~VtkImageShow() {

}

void VtkImageShow::onFileOpenSlot() {

    QString filter;
    filter = "PNG image file (*.png)";
    QDir dir;

    QString filename = QFileDialog::getOpenFileName(this, QString(tr("Open PNG File")), dir.absolutePath(), filter);

    if(filename.isEmpty())
        return;

    // Unicode filename support
    QByteArray byteArray = filename.toUtf8();
    const char *fileName_str = byteArray.data();

//    vtkSmartPointer<vtkPNGReader> reader_PNG =
//            vtkSmartPointer<vtkPNGReader>::New();
    VTK_CREATE(vtkPNGReader, reader_PNG);
    reader_PNG->SetFileName(fileName_str);

    // Set the output of m_pImageViewer to the input of reader_PNG
    m_pImageViewer->SetInputConnection(reader_PNG->GetOutputPort());
//    m_pImageViewer->UpdateDisplayExtent(); // It's for sliced images

    // Set up the platform
    m_pImageViewer->SetRenderer(m_pRenderer);
    m_pImageViewer->SetRenderWindow(m_QVTKWidget->GetRenderWindow());

    // Set up how to interact
    m_pImageViewer->SetupInteractor(m_QVTKWidget->GetRenderWindow()->GetInteractor());

    m_pRenderer->ResetCamera();
//    m_pRenderer->DrawOn();

    m_QVTKWidget->GetRenderWindow()->Render();

}
