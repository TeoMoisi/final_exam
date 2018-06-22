#include "ctrl.h"

ctrl::ctrl()
{

}

void ctrl::saveIdea(std::string i)
{
    this->r->saveIdea(i);
}

void ctrl::addIdea(idea i)
{
    if (i.getDesc() == "")
        throw Exception("The input is not correct!");

    if (i.getAct() > 3 || i.getAct() < 1)
        throw Exception("Input incorect for action 1!");

    if (this->r->same(i) == true)
        throw Exception("Duplicate idea!");

    this->r->addIdea(i);
}

std::vector<screenwriter> ctrl::getWriters()
{
       return this->r->getWriters();
}

std::vector<idea> ctrl::getIdeas()
{
    return this->r->sortByAct();
}

void ctrl::updateIdea(idea i)
{
    i.setStatus("accepted");
    this->r->updateIdea(i);
}

void ctrl::save()
{
    this->r->writeToFile();
}
