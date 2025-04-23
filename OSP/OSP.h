#ifndef _OSP
#define _OSP
#include <iostream>

class Product{

private:
    std::string name;

    double price;

    std::string description;

public:

    std::string getName();

    virtual ~Product()=0; 

};

class Electronics: public Product{

public:
    Electronics();

    Electronics(std::string n,double p,std::string d);

    Electronics(const Electronics& other);

    Electronics(Electronics&& other);

};

class Clothing: public Product{

public:
    Clothing();

    Clothing(std::string n,double p,std::string d);

    Clothing(const Clothing& other);

    Clothing(Clothing&& other);

}; 

class Customer{

private:
    std::string name;

    std::string contact;

public:
    Customer();

    Customer(std::string n,std::string c);

    Customer(const Customer& other);

    Customer(Customer&& other);

};

class OrderOperations{

public:
    virtual void info() const=0;

};

class Order: public OrderOperations{

private:
    std::unique_ptr<Customer> customer;

    std::vector<shared_ptr<Product>> products;

    double totalprice;

public:
    Order();

    Order(std::unique_ptr<Customer> c,std::vector<shared_ptr<Product>> p,double tp);

    Order(const Order& other);

    Order(Order&& other);

public:
    void info() const override;

    void addProduct(unique_ptr<Product> p);

};

class OrderSystem{

private:
    std::vector<shared_ptr<Customer>> customers;

    std::vector<shared_ptr<Product>> products;

public:
    void addCustomer(std::shared_ptr<Customer> c);

    void addProduct(std::shared_ptr<Product> p);

    void searchProduct(const std::string& n) const;

    void purchaseProduct();    

};

#endif