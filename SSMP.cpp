#include "SSMP.h" 

User::User(std::string n,std::string c): name(n),contact(c){}

User& User::operator=(const User& other){

    if(this==&other){

        name=other.name;

        contact=other.contact;

    }

    return *this;

}

User& User::operator=(User&& other){

    if(this!=&other){

        name=std::move(other.name);

        contact=std::move(other.contact);

    }

    return *this;

}

std::string User::getname() const{

    return name;

}

std::string User::getcontact() const{

    return contact;

}

void User::setname(std::string n){

    name=n;

}

void User::setcontact(std::string c){

    contact=c;

}

Post::Post(User* u,std::string c,std::string d,std::string t): user(u),content(c),date(d),time(t){}

Post& Post::operator=(const Post& other){

    if(this!=&other){

        user=other.user;

        content=other.content;

        date=other.date;

        time=other.time;

    }

    return *this;

}

Post& Post::operator=(Post&& other){

    if(this!=&other){

        user=std::move(other.user);

        content=std::move(other.content);

        date=std::move(other.date);

        time=std::move(other.time);

    }

    return *this;

}

Post::~Post(){}

User* Post::getuser() const{

    return user;

}

void Post::display() const{

    std::cout<<"The user is "<<user->getname()<<std::endl;

    std::cout<<"The content is "<<content<<std::endl;

    std::cout<<"The date is "<<date<<std::endl;

    std::cout<<"The time is "<<time<<std::endl;

}

Text::Text(User* u,std::string c,std::string d,std::string t): Post(u,c,d,t){}

Text& Text::operator=(const Text& other){

    if(this!=&other){

        Post::operator=(other);        

    }

    return *this;

}

Text& Text::operator=(Text&& other){

    if(this!=&other){

        Post::operator=(std::move(other));        

    }

    return *this;

}

Image::Image(User* u,std::string c,std::string d,std::string t): Post(u,c,d,t){}

Image& Image::operator=(const Image& other){

    if(this!=&other){

        Post::operator=(other);        

    }

    return *this;

}

Image& Image::operator=(Image&& other){

    if(this!=&other){

        Post::operator=(std::move(other));        

    }

    return *this;

}

Comment::Comment(User* u,Post* p,std::string c): user(u),post(p),content(c){}

Comment& Comment::operator=(const Comment& other){

    if(this!=&other){

        user=other.user;

        content=other.content;

    }

    return *this;

}

Comment& Comment::operator=(Comment&& other){

    if(this!=&other){

        user=std::move(other.user);

        content=std::move(other.content);

    }

    return *this;

}

User* Comment::getuser() const{

    return user;

}

ABSMedia::~ABSMedia(){

    for(auto user:users){

        delete user;

    }

    for(auto post:posts){

        delete post;

    }

    for(auto comment:comments){

        delete comment;

    }

}

void Media::createPost(User* u){

    int type=0;

    std::string c;

    std::cout<<"Please,write a comment.\n";

    std::cin.ignore();

    std::getline(std::cin,c);

    std::cout<<"Please,select post type(1-Text or 2-Image).\n";

    std::cin>>type;

    Post* post;

    if(type==1){

        post=new Text(u,c,"13.12.2002","22:22");

    }

    else if(type==2){

        post=new Image(u,c,"13.12.2002","22:22");

    }

    posts.push_back(post);

    std::cout<<"Post created.\n";

}

void Media::viewPost() const{

    for(const auto& post:posts){

        post->display();

        std::cout<<"\n";

    }

}

void Media::leaveComment(User* u,Post* p){

    std::string c;

    std::cout<<"Please,enter a comment.\n";

    std::getline(std::cin,c);

    Comment* comment=new Comment(u,p,c);

    comments.push_back(comment);

    std::cout<<"Comment added.\n";

}

void Media::manageprofile(User* u){

    std::cout<<"Please,enter the name.\n";

    std::string name;

    std::cin>>name;

    std::cout<<"Please,enter the contact.\n";

    std::string contact;

    std::cin>>contact;

    u->setname(name);

    u->setcontact(contact);

    std::cout<<"Profile managed.\n";

}

void Media::addUser(User* u){

    users.push_back(u);

    std::cout<<"User added.\n";

}

int main()

{

    Media media;

    User* u1=new User("Artur","1000");
    User* u2=new User("Arman","2000");
    User* u3=new User("Artak","3000");

    media.addUser(u1);
    media.addUser(u2);
    media.addUser(u3);

    media.manageprofile(u1);

    return 0;

}
