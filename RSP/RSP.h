#ifndef _RSP
#define _RSP

#include <iostream>
#include <vector>

class Recipe{

private:   
    std::string title;
    std::string ingredients;
    std::string instructions;

public:
    Recipe()=default;

    Recipe(std::string t,std::string ing,std::string ins);

public:
    std::string gettitle() const;

    std::string getingredients() const;

    std::string getinstructions() const;

public:
    virtual void display() const=0;

};

class Vegetarian: public Recipe{

public:
    Vegetarian()=default;

    Vegetarian(std::string t,std::string ing,std::string ins);

public:
    void display() const override;

};

class Dessert: public Recipe{

public:
    Dessert()=default;

    Dessert(std::string t,std::string ing,std::string ins);

public:
    void display() const override;

};

class Rating;

class User{

private:
    std::string name;
    std::string contact;
    std::vector<Recipe*> favrecipes;
    std::vector<Rating*> ratings;

public:
    User()=default;

    User(std::string n,std::string c);

    ~User();

public:
    std::string getname() const;

public:
    void addRecipe(Recipe* r);

public:
    void search(Recipe* r,std::vector<Recipe*> recipes) const;

    void share() const;

    void rate(Recipe* r,std::string s);

};

class Rating{

private:
    Recipe* recipe;
    User* user;
    std::string rate;

public:
    Rating()=default;

    Rating(Recipe* re,User* u,std::string ra);

};

#endif