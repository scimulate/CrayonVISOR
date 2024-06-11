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
    aboutAct->setStatusTip(tr("CrayonVISOR is a visual assistant forb colors..."));

    QAction *aboutQtAct = ui->menuHelp->addAction(tr("About &Qt.."), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("CrayonVISOR was developed using Qt technologies..."));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::About()
{
    QMessageBox::about(this, tr("About Application"),
                       tr("<b>CrayonVISOR</b> is a visual assistant for colors.<br><br>"
                          "Instructions: first, select the desired crayon box size (16, 48, etc.) from the dropdown list. Afterwards, click the button and drag your mouse anywhere on the screen. In real time, CrayonVISOR will interpret the color beneath the mouse and identify the best-matching crayon color from the selected box size.<br><br>"
                          "Please visit our <a href=\"https://www.scimulate.com\">website</a> and follow us on <a href=\"https://www.linkedin.com/company/scimulate-llc\">LinkedIn</a>!<br><br>"
                          "CrayonVISOR is made available to you under the terms of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.html\">GPLv3</a>. You are not granted any trademark rights or licenses to the trademarks of Scimulate LLC.<br><br>"));
}
