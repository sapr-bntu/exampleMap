#include "map.h"
#include "ui_map.h"
#include <QFileDialog>
#include <QMessageBox>

#include "svgview.h"

map::map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::map),m_view(new SvgView)
{
    ui->setupUi(this);
//    int rows = ui->gridLayout->rowCount();
//    int cols = ui->gridLayout->columnCount();
    ui->verticalLayout->addWidget(m_view);

//    ui->gridLayout->addWidget(m_view,rows,cols,0);
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openFile()));
}

map::~map()
{
    delete ui;
}

void map::openFile()
 {
     QString fileName;

         fileName = QFileDialog::getOpenFileName(this, tr("Open SVG File"),
                 "", "SVG files (*.svg *.svgz *.svg.gz)");


     if (!fileName.isEmpty()) {
         QFile file(fileName);
         if (!file.exists()) {
             QMessageBox::critical(this, tr("Open SVG File"),
                            QString("Could not open file '%1'.").arg(fileName));

//             m_outlineAction->setEnabled(false);
//             m_backgroundAction->setEnabled(false);
             return;
         }

         m_view->openFile(file);

//         if (!fileName.startsWith(":/")) {
//             m_currentPath = fileName;
//             setWindowTitle(tr("%1 - SVGViewer").arg(m_currentPath));
//         }

//         m_outlineAction->setEnabled(true);
//         m_backgroundAction->setEnabled(true);

//         resize(m_view->sizeHint() + QSize(80, 80 + menuBar()->height()));
     }
 }
