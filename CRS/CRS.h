#ifndef _CRS
#define _CRS
#include <iostream>
#include <vector>
#include <memory>

class Car{

public:
	virtual std::string getBrand() const=0;

	virtual std::string getModel() const=0;

	virtual double getPrice() const=0;

	virtual void getType() const=0;

	virtual ~Car(){}

};

class LuxuryCar: public Car{

private:
	std::string brand;

	std::string model;

	double price;

public:
	LuxuryCar();

	LuxuryCar(std::string b,std::string m,double p);

	LuxuryCar(const LuxuryCar& other);

	LuxuryCar(LuxuryCar&& other);

public:
	std::string getBrand() const override;

        std::string getModel() const override;

        double getPrice() const override;

        void getType() const override;

};

class EconomyCar: public Car{

private:
	std::string brand;

	std::string model;

	double price;

public:
	EconomyCar();

        EconomyCar(std::string b,std::string m,double p);

        EconomyCar(const EconomyCar& other);

        EconomyCar(EconomyCar&& other);

public:
	std::string getBrand() const override;

        std::string getModel() const override;

        double getPrice() const override;

        void getType() const override;

};

class Customer{

private:
	std::string name;

	std::string information;

public:
	Customer();

	Customer(std::string n,std::string i);

	Customer(const Customer& other);

	Customer(Customer&& other);

};

class Rental{

private:
	std::shared_ptr<Customer> customer;

	std::shared_ptr<Car> car;

	int duration;

public:
	Rental();

	Rental(std::shared_ptr<Customer> cu,std::shared_ptr<Car> ca,int d);

	Rental(const Rental& other);

	Rental(Rental&& other);	

};

class ABSRentalSystem{

private:
	std::vector<std::shared_ptr<Car>> cars;

	std::vector<std::shared_ptr<Rental>> rentalHistory;

public:
	void addCar(std::shared_ptr<Car> c);

	virtual void rentCar(std::shared_ptr<Customer> cu,const std::string& b,const std::string& m,int d)=0;

	virtual void returnCar(std::shared_ptr<Rental> r)=0;

	void showHistory() const;

};

class RentalSystem: public ABSRentalSystem{

public:
	void rentCar(std::shared_ptr<Customer> cu,const std::string& b,const std::string& m,int d) override;

        void returnCar(std::shared_ptr<Rental> r) override;

};
#endif











































































