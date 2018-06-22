#ifndef CTRL_H
#define CTRL_H
#include "repo.h"
#include "exception.h"
class ctrl
{
public:
    ctrl();
    ~ctrl() {}

    ctrl(repo* rep): r(rep) {}
    std::vector<screenwriter> getWriters();
    std::vector<idea> getIdeas();

    //method to add an idea
    void addIdea(idea i);
    void updateIdea(idea i);
    void save();
    void saveIdea(std::string i);


private:
    repo* r;
};

#endif // CTRL_H
