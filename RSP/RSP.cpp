#include "RSP.h"

Recipe::Recipe(std::string t,std::string ing,std::string ins): title(t),ingredients(ing),instructions(ins){}

std::string Recipe::gettitle() const{

    return title;

}

std::string Recipe::getingredients() const{

    return ingredients;

}

std::string Recipe::getinstructions() const{

    return instructions;

}

Vegetarian::Vegetarian(std::string t,std::string ing,std::string ins): Recipe(t,ing,ins){}

void Vegetarian::display() const{

    std::cout<<"Vegetarian:\n";

    std::cout<<gettitle()<<std::endl;
    
    std::cout<<getingredients()<<std::endl;

    std::cout<<getinstructions()<<std::endl;

}

void Dessert::display() const{

    std::cout<<"Dessert:\n";

    std::cout<<gettitle()<<std::endl;

    std::cout<<getingredients()<<std::endl;

    std::cout<<getinstructions()<<std::endl;

}

Dessert::Dessert(std::string t,std::string ing,std::string ins): Recipe(t,ing,ins){}

User::User(std::string n,std::string c): name(n),contact(c){}

std::string User::getname() const{

    return name;

}

void User::addRecipe(Recipe* r){

    for(auto it:favrecipes){

        if(it==r){

            std::cout<<"The recipe is also added.\n";

            return;

        }

    }

    favrecipes.push_back(r);

    std::cout<<"The recipe is added.\n";

}

void User::search(Recipe* r,std::vector<Recipe*> recipes) const{

    for(auto it:recipes){

        if(it==r){

            std::cout<<"The recipe is found\n";

            return;

        }

    }

    std::cout<<"The recipe is not found.\n";

}

void User::share() const{

    for(auto it:favrecipes){

        it->display();

    }

}

void User::rate(Recipe* r,std::string s){

    Rating* rating=new Rating(r,this,s);

    ratings.push_back(rating);

    std::cout<<"The "<<getname()<<" user rated for "<<r->gettitle()<<" recipe:"<<s<<std::endl;  

}

User::~User(){

    for(auto it:ratings){

        delete it;

    }

}   

Rating::Rating(Recipe* re,User* u,std::string ra): recipe(re),user(u),rate(ra){}