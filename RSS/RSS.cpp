#include "RSS.h"

Driver::Driver(std::string n,std::string c,std::string v): name(n),contact(c),vehicle(v){}

std::string Driver::getname() const{

    return name;

}

DriverCar::DriverCar(std::string n,std::string c,std::string v): Driver(n,c,v){}

void DriverCar::accept(Ride* r) const{

    std::cout<<"The "<<getname()<<" car-driver accepts this ride.\n";

}

void DriverCar::complete(Ride* r) const{

    std::cout<<"The "<<getname()<<" car-driver complete this ride\n";

}

void DriverCar::rate(Passenger* p,int r) const{

    std::cout<<"The "<<getname()<<" car-driver rate "<<p->getname()<<" passenger: "<<r<<std::endl; 

}

DriverMotorcycle::DriverMotorcycle(std::string n,std::string c,std::string v): Driver(n,c,v){}

void DriverMotorcycle::accept(Ride* r) const{

    std::cout<<"The "<<getname()<<" motorcycle-driver accepts this ride.\n";

}

void DriverMotorcycle::complete(Ride* r) const{

    std::cout<<"The "<<getname()<<" motorcycle-driver complete this ride\n";

}

void DriverMotorcycle::rate(Passenger* p,int r) const{

    std::cout<<"The "<<getname()<<" motorcycle-driver rate "<<p->getname()<<" passenger: "<<r<<std::endl; 

}

Passenger::Passenger(std::string n,std::string c): name(n),contact(c){}

std::string Passenger::getname() const{

    return name;

}

void Passenger::request(Ride* r){

    for(auto it:r->passengers){

        if(this==it){

            std::cout<<"The passenger is also requested.\n";

            return; 

        }

    }

    (r->passengers).push_back(this);

    std::cout<<"The "<<getname()<<" passenger is requested.\n";

}

void Passenger::rate(Driver* d,int r) const{

    std::cout<<"The "<<getname()<<" passenger rates "<<d->getname()<<" driver: "<<r<<std::endl;

}

Ride::Ride(Driver* dr,double di): driver(dr),distantion(di){}