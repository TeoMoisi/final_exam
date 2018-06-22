#ifndef REPO_H
#define REPO_H
#include <vector>
#include <sstream>
#include <istream>
#include <ostream>
#include <fstream>
#include "idea.h"
#include "screenwriter.h"
class repo
{
public:
    repo() {}
    ~repo() {}
    repo(std::string filename);
    void readFromFile(std::string filename);
    void writeToFile();
    std::vector<screenwriter> getWriters() { return this->writers; }
    std::vector<idea> getIdeas() {
         return this->ideas;
    }
    //Method to add an object of type idea
    //pre: idea is not in the file
    //post: the idea is in the file
    void addIdea(idea i);


    std::vector<idea> sortByAct();
    bool same(idea i);

    void updateIdea(idea i);

    void saveIdea(std::string i);

private:
    std::vector<screenwriter> writers;
    std::vector<idea> ideas;

};

#endif // REPO_H
