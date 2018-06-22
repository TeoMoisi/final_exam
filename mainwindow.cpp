#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSortFilterProxyModel>
//#include "exception.h"
#include <QMessageBox>

MainWindow::MainWindow(ctrl* ctr, screenwriter scr ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
     c(ctr), s(scr)
{
    ui->setupUi(this);
    this->table = new table_veiw{ this->c };
    this->setUpTableView();
    QWidget::setWindowTitle(QString::fromStdString(this->s.getName()));
    QObject::connect(this->ui->add_button, &QPushButton::clicked, this,  &MainWindow::add);
    QObject::connect(this->ui->revise_button, &QPushButton::clicked, this,  &MainWindow::revise);
    QObject::connect(this->ui->dev, &QPushButton::clicked, this,  &MainWindow::develop);
    for (auto it: this->c->getIdeas())
        if (it.getCreator() == this->s.getName() && it.getStatus() != "accepted")
            this->ui->dev->setVisible(false);
    QObject::connect(this->ui->savebutton , &QPushButton::clicked, this,  &MainWindow::savePlot);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::savePlot()
{
    this->c->save();

}

void MainWindow::develop()
{
    std::vector<gui*> g;
    for (auto it : c->getIdeas())
        if (it.getStatus() == "accepted")
            g.push_back(new gui{ this->c, it});
    for (int i = 0; i < g.size(); i++)
        g[i]->show();

}

void MainWindow::setUpTableView()
{
    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
    proxyModel->setSourceModel(this->table);
    ui->ideas->setSortingEnabled(true);
    ui->ideas->setModel(proxyModel);
    //ui->ideas->resizeColumnsToContents();
    ui->ideas->resizeColumnToContents(1);
    ui->ideas->resizeColumnToContents(2);
    ui->ideas->resizeColumnToContents(3);
    ui->ideas->resizeColumnToContents(4);
}

void MainWindow::add()
{
    QString desc = this->ui->desc->text();
    QString act = this->ui->act->text();
    std::string status = "proposed";
    idea i(desc.toStdString(), status, this->s.getName(), act.toInt());
    try
    {
        this->c->addIdea(i);
    }
    catch (Exception& e)
    {
        QMessageBox box;
        box.setText(QString::fromStdString(e.what()));
        box.exec();
    }
    this->setUpTableView();

}

void MainWindow::revise()
{
    idea idee;
    QString desc = this->ui->desc->text();
    QString act = this->ui->act->text();
    for (auto it: this->c->getIdeas())
        if (it.getAct() == act.toInt() && it.getDesc() == desc.toStdString())
            idee = it;
    if (this->s.getExp() != "senior")
        QMessageBox::critical(this, "Start Task", QString::fromStdString("You are  not a senior!"), QMessageBox::Ok, QMessageBox::Ok);

    if (idee.getStatus() == "proposed")
        this->c->updateIdea(idee);
    this->setUpTableView();

}

