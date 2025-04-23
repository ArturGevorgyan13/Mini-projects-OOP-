#ifndef _LS
#define _LS

#include <iostream>
#include <vector>
#include <algorithm>

class Book{

private:
    std::string title;
    std::string author;
    std::string date;

public:
    Book()=default;

    Book(std::string t,std::string a,std::string d);

public:
    std::string gettitle() const;

};

class FictionBook: public Book{

public:
    FictionBook()=default;

    FictionBook(std::string t,std::string a,std::string d);

};

class nonFictionBook: public Book{

public:
    nonFictionBook()=default;

    nonFictionBook(std::string t,std::string a,std::string d);

};

class Librarian;

class Borrower{

private:
    std::string name;
    std::string contact;
    std::vector<Book*> books;

public:
    Borrower()=default;

    Borrower(std::string n,std::string c);

public:
    void searchBook(Librarian* l,Book* b);

    void borrowBook(Librarian* l,Book* b);

    void viewBook();

    void returnBook(Librarian* l,Book* b);

};

class Librarian{

friend class Borrower;

private:
    std::string name;
    std::string contact;
    std::vector<Book*> books;

public:
    Librarian()=default;

    Librarian(std::string n,std::string c);

public:
    void addBook(Book* b);

};

#endif