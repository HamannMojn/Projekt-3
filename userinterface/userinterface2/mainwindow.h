#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <unistd.h>
#include "socket.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void enableStyring();

private slots:
    void on_btnFrem_pressed();

    void on_btnFrem_released();

    void on_btnVenstre_pressed();

    void on_btnVenstre_released();

    void on_btnHojre_pressed();

    void on_btnHojre_released();

    void on_btnTilbage_pressed();

    void on_btnTilbage_released();

    void on_btnLoeft_clicked();

    void on_btnSaenk_clicked();

private:
    Socket socket;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
