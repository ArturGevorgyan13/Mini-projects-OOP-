#include "GA.h"

int main()

{

    Developer d1("Artur","1111");
    Developer d2("Anna","2222");

    d1.createGame("A","Action","01.02.2017");
    d2.createGame("B","Action","01.03.2013");
    d2.createGame("C","Strategy","03.03.2014");

    d1.manageGame("A","D");

    Publisher p1("Alaric","0001");
    Publisher p2("Kethrine","0002");

    p1.sale(&d1,"D");
    p2.sale(&d2,"B");
    p2.sale(&d2,"C");

    p1.manageGame(&d1,"D","01.02.2020");

    Program program;

    program.addDeveloper(&d1);
    program.addDeveloper(&d2);
    program.addPublisher(&p1);
    program.addPublisher(&p2);

    program.showDevelopers();
    program.showPublishers();
    program.showGames();

    return 0;

}