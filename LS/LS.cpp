#include "LS.h"

Book::Book(std::string t,std::string a,std::string d): title(t),author(a),date(d){}

std::string Book::gettitle() const{

    return title;

}

FictionBook::FictionBook(std::string t,std::string a,std::string d): Book(t,a,d){}

nonFictionBook::nonFictionBook(std::string t,std::string a,std::string d): Book(t,a,d){}

Borrower::Borrower(std::string n,std::string c): name(n),contact(c){}

void Borrower::searchBook(Librarian* l,Book* b){

    for(auto it:l->books){

        if(b==it){

            std::cout<<"The book is valid: "<<b->gettitle()<<std::endl;

            return;

        }

    }

    std::cout<<"The book is not valid: "<<b->gettitle()<<std::endl;

}

void Borrower::borrowBook(Librarian* l,Book* b){

    auto fit=std::find(l->books.begin(),l->books.end(),b);

    for(auto it:l->books){

        if(b==it){

            books.push_back(b);

            l->books.erase(fit);

            std::cout<<"The book is borrowed: "<<b->gettitle()<<std::endl;

            return;

        }

    }

    std::cout<<"The book is not borrowed: "<<b->gettitle()<<std::endl;

}

void Borrower::viewBook(){

    std::cout<<name<<std::endl;

    for(auto it:books){

        std::cout<<it->gettitle()<<std::endl;

    }

}

void Borrower::returnBook(Librarian* l,Book* b){

    auto it=std::find(books.begin(),books.end(),b);

    books.erase(it);

    l->books.push_back(b);

    std::cout<<"The book is returned: "<<b->gettitle()<<std::endl;

}

Librarian::Librarian(std::string n,std::string c): name(n),contact(c){}

void Librarian::addBook(Book* b){

    for(auto it:books){

        if(b==it){

            std::cout<<"The book is also added: "<<b->gettitle()<<std::endl;

            return;

        }

    }

    books.push_back(b);

    std::cout<<"The book is added: "<<b->gettitle()<<std::endl;

}