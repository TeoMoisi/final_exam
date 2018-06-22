#ifndef SCREENWRITER_H
#define SCREENWRITER_H
#include <string>

class screenwriter
{
public:
    screenwriter() {}
    ~screenwriter() {}
    screenwriter(std::string n, std::string ex): name(n), expertise(ex) {}
    std::string getName() { return this->name; }
    std::string getExp() { return this->expertise; }
    std::string toString()
    {
        std::string sir = "";
        sir += this->name + "," + this->expertise;
        return sir;
    }

private:
    std::string name;
    std::string expertise;
};

#endif // SCREENWRITER_H
