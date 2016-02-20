#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_urlbox_editingFinished();

    void on_downloadbutton_clicked();


//    void on_console_text_linkActivated(const QString &link);

    void on_textBrowser_textChanged();

    void on_textBrowser_sourceChanged(const QUrl &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
