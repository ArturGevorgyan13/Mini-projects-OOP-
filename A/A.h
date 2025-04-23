#ifndef _A
#define _A

#include <iostream>
#include <vector>
#include <map>
#include <memory>

class Shop;

class Customer;

class Order;

enum class Type{

    ELECTRONIC,
    CLOTHING

};

class Product{

private:
    std::string name;
    double price;
    std::string description;

public:
    std::string getname() const;

    double getprice() const;

public:

    virtual Type gettype() const=0;

public:
    Product()=default;

    Product(std::string n,double p,std::string d);

    virtual ~Product()=default;

};

class Electronic: public Product{

public: 
    Electronic()=default;

    Electronic(std::string n,double p,std::string d);

public:
    Type gettype() const override;

};

class Clothing: public Product{

public:
    Clothing()=default;

    Clothing(std::string n,double p,std::string d);

public:
    Type gettype() const override;

};

class Customer{

private:
    std::string name;
    std::string contact;

public:
    std::string getname() const;
    
    std::string getcontact() const;

public:
    Customer()=default;

    Customer(std::string n,std::string c);

public:
    void search(std::string pn,std::shared_ptr<Shop> s);

    void purchase(std::vector<std::string> pns,std::shared_ptr<Shop> s);

    void view(std::shared_ptr<Shop> s) const;

    void leavereview(std::string r,std::shared_ptr<Shop> s) const;

};

class Order{

private:
    std::string customername;
    std::vector<std::string> products;
    double totalprice;

public:
    Order()=default;

    Order(std::string cn,std::vector<std::string> ps,double p);

public:
    void display() const;

};

class Shop{

private:
    std::map<std::shared_ptr<Product>,int> products;
    std::map<std::string,std::vector<std::shared_ptr<Order>>> customersorders;
    std::map<std::string,std::string> customercomment;

public:
    bool searchProduct(std::string pn) const;

    void sellProduct(std::string pn);

    void addOrder(std::string cn,std::vector<std::string> pns,double p);

    double price(std::vector<std::string> pn) const;

    void show(std::string cn) const;

    void comment(std::string cn,std::string c);

    void addProduct(std::string n,double p,std::string d,int count,Type typee);

};

#endif