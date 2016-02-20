#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_urlbox_editingFinished()
{
}

void MainWindow::on_downloadbutton_clicked()
{
    QProcess *download = new QProcess();
    if (download)
    {
    QString url;
    url = ui->urlbox->text();
//    qDebug()<<home;
    qDebug()<<url;
    download->start("wget", QStringList() << url << "-P" << "/home/arun/Downloads/arun");
    qDebug()<<download;
    download->waitForStarted();
    connect( download, SIGNAL(readyReadStandardOutput()), this, SLOT(on_textBrowser_sourceChanged()) );
    connect( download, SIGNAL(readyReadStandardError()), this, SLOT(ReadErr()) );
    }

}


void MainWindow::on_textBrowser_sourceChanged(const QUrl &arg1)
{
    QProcess *download = dynamic_cast<QProcess *>( sender() );
           if (download)
             ui->textBrowser->append( download->readAllStandardOutput() );
}
