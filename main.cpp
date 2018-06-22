#include "mainwindow.h"
#include <QApplication>
#include "tester.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    repo r("/Users/teofanamoisi/Desktop/examen-final/ideas.txt");
    ctrl c(&r);
    tester t;
    t.run();
    std::vector<MainWindow*> gui;
    for (auto it : c.getWriters())
        gui.push_back(new MainWindow{ &c, it});
    for (int i = 0; i < gui.size(); i++)
        gui[i]->show();

    return a.exec();
}
