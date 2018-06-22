#include "repo.h"
using namespace std;

repo::repo(string filename)
{
    this->readFromFile(filename);
}


void repo::readFromFile(std::string filename)
{
    ifstream f(filename);
    string line;
    while (getline(f, line))
    {
        stringstream get(line);
        vector<string> all;
        string idee;
        while(getline(get, idee, ','))
        {
            all.push_back(idee);
        }
        this->ideas.push_back(idea(all[0], all[1], all[2], stoi(all[3])));
    }
    f.close();

    f.open("/Users/teofanamoisi/Desktop/examen-final/writers.txt");
    string line2;
    while (getline(f, line2))
    {
        stringstream get(line2);
        vector<string> elems;
        string writer;
        while (getline(get, writer, ','))
        {
            elems.push_back(writer);
        }
        this->writers.push_back(screenwriter(elems[0], elems[1]));
    }
    f.close();
}

void repo::writeToFile()
{
    ofstream f("/Users/teofanamoisi/Desktop/examen-final/saved.txt");
    for (auto it: this->ideas)
    {
        if (it.getAct() == 1)
        {
            f << "Act 1 - \n";
            if (it.getStatus() == "accepted")
                f  << it.getDesc() << " "<<it.getCreator() << "\n";
        }
    }
    for (auto it: this->ideas)
    {
        if (it.getAct() == 2)
        {
            f << "Act 2 - \n";
            if (it.getStatus() == "accepted")
                f  << it.getDesc() << " "<<it.getCreator() << "\n";
        }
    }
    for (auto it: this->ideas)
    {
        if (it.getAct() == 3)
        {
            f << "Act 3 - \n";
            if (it.getStatus() == "accepted")
                f  << it.getDesc() << " "<<it.getCreator() << "\n";
        }
    }
    f.close();
}

void repo::saveIdea(std::string i)
{
    ofstream fout("/Users/teofanamoisi/Desktop/examen-final/sdeas.txt");
    //std::string line = i;
    fout << i << "\n" ;
    //file.close();
}

std::vector<idea> repo::sortByAct()
{
    std::vector<idea> all = this->ideas;
    for (int i = 0; i < all.size(); i++)
        for (int j = 0; j < all.size(); j++)
            if (all[i].getAct() < all[j].getAct())
            {
                idea aux = all[i];
                all[i] = all[j];
                all[j] = aux;
            }

    return all;
}

bool repo::same(idea i)
{
    for (auto it: this->ideas)
        if (it.getDesc() == i.getDesc() && it.getAct() == i.getAct())
            return true;
    return false;
}

void repo::addIdea(idea i)
{
    this->ideas.push_back(i);
}

void repo::updateIdea(idea i)
{
    for (int j = 0; j < this->ideas.size(); j++)
        if (this->ideas[j].getDesc() == i.getDesc() && this->ideas[j].getAct() == i.getAct())
            this->ideas[j] = i;
}
