#include "LS.h"

int main()

{

    FictionBook b1("A","Karen","01.02.2019");
    FictionBook b2("B","Armine","02.03.2019");
    nonFictionBook b3("C","Mariam","03.03.2019");
    FictionBook b4("D","Suren","04.03.2019");

    Borrower bo1("Arturo","0000");
    Borrower bo2("Arseno","1111");
    Borrower bo3("Klarao","2222");

    Librarian l1("Klaus","777");
    Librarian l2("Kole","666");

    l1.addBook(&b1);
    l1.addBook(&b2);
    l1.addBook(&b3);
    l2.addBook(&b4);

    bo1.searchBook(&l1,&b1);
    bo2.searchBook(&l1,&b2);
    bo3.searchBook(&l2,&b3);
    bo3.searchBook(&l1,&b3);
    bo3.searchBook(&l2,&b4);

    bo1.borrowBook(&l1,&b1);
    bo2.borrowBook(&l1,&b2);
    bo3.borrowBook(&l1,&b3);
    bo3.borrowBook(&l2,&b4);

    bo1.viewBook();
    bo2.viewBook();
    bo3.viewBook();

    bo1.returnBook(&l1,&b1);
    bo2.returnBook(&l1,&b2);
    bo3.returnBook(&l1,&b3);
    bo3.returnBook(&l1,&b4);

    bo1.viewBook();
    bo2.viewBook();
    bo3.viewBook();

    return 0;

}