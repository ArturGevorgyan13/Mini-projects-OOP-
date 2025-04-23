#ifndef _GA
#define _GA

#include <iostream>
#include <vector>

class Game{

private:
    std::string title;
    std::string genre;
    std::string releasedata;

public:
    Game()=default;

    Game(std::string t,std::string g,std::string rd);

public:
    std::string gettitle() const;

    std::string getreleasedata() const;

    void settitle(std::string t);

    void setreleasedata(std::string rd);

};

class Action: public Game{

public:
    Action()=default;

    Action(std::string t,std::string g,std::string rd);

};

class Strategy: public Game{

public:
    Strategy()=default;

    Strategy(std::string t,std::string g,std::string rd);

};

class Developer{

    friend class Publisher;

private:
    std::string name;
    std::string contactinfo;
    std::vector<Game*> devgames;

public:
    Developer()=default;

    Developer(std::string n,std::string ci);

public:
    void createGame(std::string t,std::string g,std::string rd);

    void manageGame(std::string t,std::string nt);

    void show() const;

public:

    std::string getname() const;

};

class Publisher{

private:
    std::string name;
    std::string contactinfo;
    std::vector<Game*> pubgames;

public:
    Publisher()=default;

    Publisher(std::string n,std::string ci);

public:

    void manageGame(Developer* d,std::string t,std::string nrd);

    void sale(Developer* d,std::string t);

public:
    std::string getname() const;

};

class Program{

private:
    std::vector<Developer*> developers;
    std::vector<Publisher*> publishers;

public:
    void addDeveloper(Developer* d);

    void addPublisher(Publisher* p);

    void showGames() const;

    void showDevelopers() const;

    void showPublishers() const;

};

#endif