#include "RSP.h"

int main()

{

    std::vector<Recipe*> recipes;

    Dessert r1("Cake","A","i1");
    Vegetarian r2("Laxana","B","i2");
    Vegetarian r3("Marol","C","i3");

    recipes.push_back(&r1);
    recipes.push_back(&r2);
    recipes.push_back(&r3);

    User u1("Artur","1111");
    User u2("Arman","2222");

    u1.search(&r1,recipes);

    u1.addRecipe(&r1);
    u2.addRecipe(&r2);
    u2.addRecipe(&r3);

    u1.share();
    u2.share();

    u1.rate(&r1,"9");
    u2.rate(&r2,"7");
    u1.rate(&r3,"5");

    return 0;

}