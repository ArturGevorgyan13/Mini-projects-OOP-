#ifndef _RSS
#define _RSS

#include <iostream>
#include <vector>

class Ride;

class Passenger;

class Driver{

private:
    std::string name;
    std::string contact;
    std::string vehicle;

public:
    Driver()=default;

    Driver(std::string n,std::string c,std::string v);

public:
    std::string getname() const;

public:
    virtual void accept(Ride* r) const=0;

    virtual void complete(Ride* r) const=0;

    virtual void rate(Passenger* p,int r) const=0;

};

class DriverCar: public Driver{

public:
    DriverCar()=default;

    DriverCar(std::string n,std::string c,std::string v);

public:
    void accept(Ride* r) const override;

    void complete(Ride* r) const override;

    void rate(Passenger* p,int r) const override;

};

class DriverMotorcycle: public Driver{

public:
    DriverMotorcycle()=default;

    DriverMotorcycle(std::string n,std::string c,std::string v);

public:
    void accept(Ride* r) const override;

    void complete(Ride* r) const override;

    void rate(Passenger* p,int r) const override;

};

class Passenger{

private:
    std::string name;
    std::string contact;

public:
    Passenger()=default;

    Passenger(std::string n,std::string c);

public:
    std::string getname() const;

public:
    void request(Ride* r);

    void rate(Driver* d,int r) const;

};

class Ride{

friend class Passenger;

private:
    Driver* driver;
    std::vector<Passenger*> passengers;
    double distantion;

public:
    Ride()=default;

    Ride(Driver* dr,double di);

};

#endif