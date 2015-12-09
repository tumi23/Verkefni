#include "data.h"
#include "objects.h"
#include "ui.h"
#include "worklayers.h"
/*Vid akvodum ad byrja alls kyns breytur herna sem tengjast hverjum
klasa i forritinu og daela theim svo yfir i UI sem notar hvert
fall a mismunandi hatt
*/
int main()
{
    vector<Person> Per;
    vector<computer> Comp;
    Data d;
    UI uid;
    PersonWorkLayer pom;
    computerWorkLayer com;
    uid.startLoop(Comp,Per,d,pom,com);
}
