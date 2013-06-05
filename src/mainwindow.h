#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controls.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Controls *controls, QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
    
private:
    Ui::MainWindow *ui;

    Controls *_controls;

    void LoadSettings();
    void SaveSettings();
};

#endif // MAINWINDOW_H
