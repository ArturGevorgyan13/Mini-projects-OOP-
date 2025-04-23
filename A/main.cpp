#include "A.h"

int main()

{

    auto shop=std::make_shared<Shop>();

    auto c1=std::make_shared<Customer>("Artur","111");
    auto c2=std::make_shared<Customer>("Ares","222");

    shop->addProduct("A",10,"bla1",7,Type::ELECTRONIC);
    shop->addProduct("B",11,"bla2",7,Type::ELECTRONIC);
    shop->addProduct("C",12,"bla3",7,Type::CLOTHING);
    shop->addProduct("D",13,"bla4",7,Type::CLOTHING);

    c1->search("A",shop);
    c1->search("F",shop);
    c2->search("B",shop);

    c1->purchase({"A","C"},shop);
    c2->purchase({"B","D"},shop);

    c1->view(shop);
    c2->view(shop);

    c1->leavereview("comment1",shop);
    c2->leavereview("comment2",shop);

    return 0;

}