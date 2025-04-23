#ifndef _SSMP
#define _SSMP
#include <iostream>
#include <vector>

class User{

private:
    std::string name;

    std::string contact;

public:
    User()=default;

    User(std::string n,std::string c);

    User(const User& other)=default;

    User(User&& other)=default;

    User& operator=(const User& other);

    User& operator=(User&& other);

    ~User()=default;

public:
    std::string getname() const;

    std::string getcontact() const;

    void setname(std::string n);

    void setcontact(std::string c);

};

class Post{

private:
    User* user;

    std::string content;

    std::string date;

    std::string time;

public:
    Post()=default;

    Post(User* u,std::string c,std::string d,std::string t);

    Post(const Post& other)=default;

    Post(Post&& other)=default;

    Post& operator=(const Post& other);

    Post& operator=(Post&& other);

    virtual ~Post()=0;

public:
    User* getuser() const;

    void display() const;

};

class Text: public Post{

public:
    Text()=default;

    Text(User* u,std::string c,std::string d,std::string t);

    Text(const Text& other)=default;

    Text(Text&& other)=default;

    Text& operator=(const Text& other);

    Text& operator=(Text&& other);

    ~Text()=default;

};

class Image: public Post{

public:
    Image()=default;

    Image(User* u,std::string c,std::string d,std::string t);

    Image(const Image& other)=default;

    Image(Image&& other)=default;

    Image& operator=(const Image& other);

    Image& operator=(Image&& other);

    ~Image()=default;

};

class Comment{

private:
    User* user;

    Post* post;

    std::string content;

public:
    Comment()=default;

    Comment(User* u,Post* p,std::string c);

    Comment(const Comment& other)=default;

    Comment(Comment&& other)=default;

    Comment& operator=(const Comment& other);

    Comment& operator=(Comment&& other);

    ~Comment()=default;

public:
    User* getuser() const;

};

class ABSMedia{

protected:
    std::vector<User*> users;

    std::vector<Post*> posts;

    std::vector<Comment*> comments;

public:

    virtual void createPost(User* u)=0;

    virtual void viewPost() const=0;

    virtual void leaveComment(User* u,Post* p)=0;

    virtual void manageprofile(User* u)=0;

    virtual void addUser(User* u)=0;

    virtual ~ABSMedia();

};

class Media: public ABSMedia{

public:
    void createPost(User* u) override;

    void viewPost() const override;

    void leaveComment(User* u,Post* p) override;

    void manageprofile(User* u) override;

    void addUser(User* u) override;

};

#endif
