#include "GA.h"

Game::Game(std::string t,std::string g,std::string rd): title(t),genre(g),releasedata(rd){}

std::string Game::gettitle() const{

    return title;

}

void Game::settitle(std::string t){

    title=t;

}

void Game::setreleasedata(std::string rd){

    releasedata=rd;

}

Action::Action(std::string t,std::string g,std::string rd): Game(t,g,rd){}

Strategy::Strategy(std::string t,std::string g,std::string rd): Game(t,g,rd){}

Developer::Developer(std::string n,std::string ci): name(n),contactinfo(ci){}

void Developer::createGame(std::string t,std::string g,std::string rd){

    for(auto it:devgames){

        if(t==it->gettitle()){

            std::cout<<"The game is also developed.\n";

            return;

        }

    } 

    Game* game;

    if(g=="Action"){

        game=new Action(t,g,rd);

    }

    else if(g=="Strategy"){

        game=new Strategy(t,g,rd);

    }

    devgames.push_back(game);

    std::cout<<"The game is developed by "<<this->name<<".\n";

}

void Developer::manageGame(std::string t,std::string nt){

    for(auto it:devgames){

        if(nt==it->gettitle()){

            std::cout<<"The name is not valid.\n";

        }

    }

    for(auto it:devgames){

        if(t==it->gettitle()){

            it->settitle(nt);

            std::cout<<"The game is managed by developer "<<this->name<<".\n";

            return;

        }

    }

    std::cout<<"The game is not found.\n";

}

void Developer::show() const{

    std::cout<<getname()<<std::endl;

    for(auto it:devgames){

        std::cout<<it->gettitle()<<std::endl;

    }

}

std::string Developer::getname() const{

    return name;

}

Publisher::Publisher(std::string n,std::string ci): name(n),contactinfo(ci){}

void Publisher::manageGame(Developer* d,std::string t,std::string nrd){

    for(auto it:d->devgames){

        if(t==it->gettitle()){

            it->setreleasedata(nrd);

            std::cout<<"The game is managed by publisher "<<this->name<<".\n";

            return;

        }

    }

    std::cout<<"The game is not found.\n";

}

void Publisher::sale(Developer* d,std::string t){

    for(auto it:d->devgames){

        if(t==it->gettitle()){

            pubgames.push_back(it);

            std::cout<<"The game is published "<<this->name<<".\n";

            return;

        }

    }

    std::cout<<"The game is not found.\n";

}

std::string Publisher::getname() const{

    return name;

}

void Program::addDeveloper(Developer* d){

    developers.push_back(d);

}

void Program::addPublisher(Publisher* p){

    publishers.push_back(p);

}

void Program::showGames() const{

    for(auto it:developers){

        it->show();

    }

}

void Program::showDevelopers() const{

    for(auto it:developers){

        std::cout<<it->getname()<<std::endl;

    }

}

void Program::showPublishers() const{

    for(auto it:publishers){

        std::cout<<it->getname()<<std::endl;

    }

}