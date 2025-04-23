#ifndef _MA
#define _MA

#include <iostream>
#include <vector>

class User{

private:
    std::string name;
    std::string contact;

public:
    User(std::string n,std::string c);

public:
    std::string getname() const;

    std::string getcontact() const;

    void setname(std::string n);

    void setcontact(std::string c);

};

class Conversation{

private:
    std::vector<User*> users;

    std::vector<Message*> messages;

public:
    Conversation()=default;

    Conversation(std::vector<User*> u,std::vector<Message> m);

public:
    void addUser(User* u);

    void removeUser(User* u);

    void addMessage(Message* u);

    void removeMessage(Message* u);

    void viewHistory();

};

class Message{

private:
    User* user;
    Conversation* conversation;
    std::string content;

public:
    virtual ~Message()=0;

public:
    std::string getcontent() const;

    virtual std::string gettype() const=0;

    virtual void display() const=0;

};

class Text: public Message{

public:
    Text()=default;

    Text(User* u,Conversation* conv,const std::string& cont);

    Text(const Text& other);

    Text(Text&& other);

    ~Text();

public:
    std::string gettype() const override;

    void display() const override;

};

class Multimedia: public Message{

public:
    Multimedia()=default;

    Multimedia(User* u,Conversation* conv,const std::string& cont);

    Multimedia(const Multimedia& other);

    Multimedia(Multimedia&& other);

    ~Multimedia();

public:
    std::string gettype() const override;

    void display() const override;

};

class MessageProgram{

private:
    std::vector<User*> users;
    std::vector<Conversation*> conversations;

public:
    void createUser(std::string n,std::string c);

    void deleteUser(std::string n,std::string c);

    void createConversation(std::vector<std::string> names);

    void deleteConversation(Conversation* c);

    void sendMessage(std::string message,Conversation* c,std::string name);

};

#endif