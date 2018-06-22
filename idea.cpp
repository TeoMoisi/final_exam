#include "idea.h"
using namespace std;

string idea::getDesc()
{
    return this->desc;
}

string idea::getStatus()
{
    return this->status;
}

string idea::getCreator()
{
    return this->creator;
}

int idea::getAct()
{
    return this->act;
}

std::string idea::toString()
{
    std::string sir = "";
    sir += this->desc + "," + this->status + "," + this->creator + "," + std::to_string(this->act );
    return sir;
}
