#include "A.h"

Product::Product(std::string n,double p,std::string d): name(n),price(p),description(d){}

double Product::getprice() const{

    return price;

}

std::string Product::getname() const{

    return name;

}

Electronic::Electronic(std::string n,double p,std::string d): Product(n,p,d){}

Type Electronic::gettype() const{

    return Type::ELECTRONIC;

}

Clothing::Clothing(std::string n,double p,std::string d): Product(n,p,d){}

Type Clothing::gettype() const{

    return Type::CLOTHING;

}

Customer::Customer(std::string n,std::string c): name(n),contact(c){}

std::string Customer::getname() const{

    return name;

}

std::string Customer::getcontact() const{

    return contact;

}

void Customer::search(std::string pn,std::shared_ptr<Shop> s){

    if(s->searchProduct(pn)){

        std::cout<<"The product "<<pn<<" is valid.\n";

    }

    else std::cout<<"The product "<<pn<<" is not valid.\n";

}

void Customer::purchase(std::vector<std::string> pns,std::shared_ptr<Shop> s){

    std::vector<std::string> newproducts;

    for(auto it:pns){

        if(!s->searchProduct(it)){

            continue;

        }

        newproducts.push_back(it);

        s->sellProduct(it);

    }

    double price=0;

    price=s->price(newproducts);

    s->addOrder(name,newproducts,price);

    std::cout<<"The customer "<<name<<" purchased.\n";

}

void Customer::view(std::shared_ptr<Shop> s) const{

    std::cout<<"Customer: "<<name<<std::endl;

    s->show(name);

}

void Customer::leavereview(std::string r,std::shared_ptr<Shop> s) const{

    s->comment(name,r);

    std::cout<<"The customer "<<name<<" leave review: "<<r<<std::endl;

}

Order::Order(std::string cn,std::vector<std::string> ps,double p): customername(cn),products(ps),totalprice(p){}

void Order::display() const{

    for(auto it:products){

        std::cout<<it<<std::endl;

    }

}

bool Shop::searchProduct(std::string pn) const{

    for(auto it:products){

        if(it.first->getname()==pn){

            return it.second;

        }

    }

    return false;

}

void Shop::sellProduct(std::string pn){

    for(auto it:products){

        if(pn==it.first->getname()){

            --it.second;

            return;

        }

    }

}

void Shop::addOrder(std::string cn,std::vector<std::string> pns,double p){

    for(auto it:customersorders){

        if(it.first==cn){

            customersorders[it.first].push_back(std::make_shared<Order>(cn,pns,p));

            return;

        }

    }

    std::vector<std::shared_ptr<Order>> orders {std::make_shared<Order>(cn,pns,p)};

    customersorders.insert(std::make_pair(cn,orders));

    std::cout<<"The customer "<<cn<<"'s order is added.\n";

}

double Shop::price(std::vector<std::string> pn) const{

    double sum=0;

    for(auto it:pn){

        for(auto ito:products){

            if(it==ito.first->getname()){

                sum+=ito.first->getprice();

            }

        }

    }

    return sum;

}

void Shop::show(std::string cn) const{

    for(auto it:customersorders){

        if(it.first==cn){

            for(auto ito:it.second){

                ito->display();

            }

        }

    }

}

void Shop::comment(std::string cn,std::string c){

    for(auto& it:customercomment){

        if(it.first==cn){

            it.second+=c;

        }

    }

    customercomment.insert(std::make_pair(cn,c));

}

void Shop::addProduct(std::string n,double p,std::string d,int count,Type typee){

    for(auto& it:products){

        if(it.first->getname()==n){

            it.second+=count;
            
            std::cout<<"The product is added.\n";

            return;

        }

    }

    if(typee==Type::ELECTRONIC){

        products.insert(std::make_pair(std::make_shared<Electronic>(n,p,d),count));

        std::cout<<"The product(Electronic) is added.\n";

    }

    else if(typee==Type::CLOTHING){

        products.insert(std::make_pair(std::make_shared<Clothing>(n,p,d),count));

        std::cout<<"The product(Clothing) is added.\n";

    }

}
