#include "tester.h"
#include "ctrl.h"

tester::tester()
{

}

void tester::run()
{
    repo r;
    ctrl c(&r);
    idea i("fly", "proposed", "teo", 2);
    r.addIdea(i);


    idea upd("fly", "accepted", "teo", 2);
    r.updateIdea(upd);

    std::vector<idea> all = r.getIdeas();
    assert(all.size() == 1);
    assert(all[0].getStatus() == "accepted");


    idea ide("be", "proposed", "teo", 3);
    c.addIdea(ide);

    idea ideea("be", "accepted", "teo", 3);
    c.updateIdea(ideea);
    std::vector<idea> ideas = c.getIdeas();
    assert(ideas.size() == 2);
    assert(ideas[1].getStatus() == "accepted");


}
