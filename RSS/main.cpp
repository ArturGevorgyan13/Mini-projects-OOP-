#include "RSS.h"

int main()

{

    DriverCar d1("Artur","1","Car");
    DriverMotorcycle d2("Arman","2","Moto");
    DriverMotorcycle d3("Syzui","3","Heco");

    Passenger p1("A","11");
    Passenger p2("B","22");
    Passenger p3("C","33");
    Passenger p4("D","44");
    Passenger p5("E","55");
    Passenger p6("F","66");
    Passenger p7("G","77");

    Ride r1(&d1,10);
    Ride r2(&d2,15);
    Ride r3(&d3,20);

    p1.request(&r1);
    p2.request(&r1);
    p3.request(&r1);
    p4.request(&r2);
    p5.request(&r2);
    p6.request(&r3);
    p7.request(&r3);

    d1.accept(&r1);
    d2.accept(&r2);
    d3.accept(&r3);

    d1.complete(&r1);
    d2.complete(&r2);
    d3.complete(&r3);

    d1.rate(&p1,5);

    p1.rate(&d1,9);
    p4.rate(&d2,10);

    return 0;

}