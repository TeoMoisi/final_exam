#include "gui.h"
#include "ui_gui.h"
#include <QPushButton>
gui::gui(ctrl* c, idea id, QWidget *parent) :
    QWidget(parent),
    id(id), c(c),
    ui(new Ui::gui)
{
    ui->setupUi(this);
    this->populate();
    QObject::connect(this->ui->savebutton , &QPushButton::clicked, this,  &gui::save);

}

gui::~gui()
{
    delete ui;
}


void gui::populate()
{
    this->ui->ideea->setText(QString::fromStdString(this->id.toString()));
}

void gui::save()
{
    QString i = this->ui->ideea->toPlainText();
    std::string ideea = i.toStdString();
    this->c->saveIdea(ideea);
}
