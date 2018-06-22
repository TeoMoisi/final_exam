#ifndef GUI_H
#define GUI_H
#include "ctrl.h"
#include <QWidget>

namespace Ui {
class gui;
}

class gui : public QWidget
{
    Q_OBJECT

public:
    explicit gui(ctrl* c, idea id, QWidget *parent = 0);
    ~gui();
    void populate();
    void save();

private:
    Ui::gui *ui;
    idea id;
    ctrl* c;
};

#endif // GUI_H
