#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tableview.h"
#include <QMainWindow>
#include "ctrl.h"
#include "gui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ctrl* contr, screenwriter scr, QWidget *parent = 0);
    ~MainWindow();
    void setUpTableView();
    void add();
    void revise();
    void develop();
    void savePlot();

private:
    Ui::MainWindow *ui;
    ctrl* c;
    screenwriter s;
    table_veiw* table;

};

#endif // MAINWINDOW_H
