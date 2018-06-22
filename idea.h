#ifndef IDEA_H
#define IDEA_H
#include <string>

class idea
{
public:
    idea() {}
    ~idea() {}
    idea(std::string d, std::string s, std::string c, int a): desc(d), status(s), creator(c), act(a) {}
    std::string getDesc();
    std::string getStatus();
    std::string getCreator();
    int getAct();
    std::string toString();
    void setDesc(std::string desc) { this->desc = desc; }
    void setStatus(std::string st)
    {
        this->status = st;
    }
    void setCreator(std::string cr) { this->creator = cr; }
    void setAct(int act) {this->act = act; }

private:
    std::string desc, status, creator;
    int act;
};

#endif // IDEA_H
