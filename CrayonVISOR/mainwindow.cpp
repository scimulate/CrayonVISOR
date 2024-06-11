#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);

    ui->statusbar->showMessage("CrayonVISOR by Scimulate LLC", 5000);

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = ui->menuFile->addAction(exitIcon, tr("E&xit"), this, &QWidget::close);
    exitAct->setStatusTip(tr("Close Application"));

    QAction *aboutAct = ui->menuHelp->addAction(tr("&About CrayonVISOR..."), this, &MainWindow::About);
    aboutAct->setStatusTip(tr("PlotVISOR is a visual assistant for interpreting contour plots..."));

    QAction *aboutQtAct = ui->menuHelp->addAction(tr("About &Qt.."), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("PlotVISOR was developed using Qt technologies..."));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::About()
{
    QMessageBox::about(this, tr("About Application"),
                       tr("<b>PlotVISOR</b> is a visual assistant for contour plots.<br><br>"
                          "By following the instructions (1) to (4) in the program window, users can map the legend of any contour plot and use it to identify values otherwise difficult to interpret.<br><br>"
                          "If \"???\" is displayed instead of a valid result, disable lighting enhancements (within your host software) and/or remap the calibration curve. PlotVISOR has been configured to accommodate mild lighting variation from rendering, but this may affect results by ±1 legend increment.<br><br>"
                          "Please visit our <a href=\"https://www.scimulate.com\">website</a> and follow us on <a href=\"https://www.linkedin.com/company/scimulate-llc\">LinkedIn</a>!<br><br>"
                          "PlotVISOR is made available to you under the terms of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.html\">GPLv3</a>. You are not granted any trademark rights or licenses to the trademarks of Scimulate LLC.<br><br>"));
}
