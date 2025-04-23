#ifndef _SMS
#define _SMS
#include <iostream>
#include <memory>

class Student{

private:
    std::string name;

    std::string contact;

public:
    Student();

    Student(std::string n,std::string c);

    Student(const Student& other);

    Student(Student&& other);

public:
    void viewinfo();

};

class Teacher{

private:
    std::string name;

    std::string contact;

    std::string subject;

public:
    Teacher();

    Teacher(std::string n,std::string c,std::string s);

    Teacher(const Teacher& other);

    Teacher(Teacher&& other);

};

class Course{

private:
    std::string name;

    std::unique_ptr<Teacher> teacher;

    std::vector<shared_ptr<Student>> students;

public:
    virtual void information() const=0;

    void viewinfo();

};

class Math: public Course{

public:
    Math();

    Math(std::string n,std::unique_ptr<Teacher> t,std::vector<shared_ptr<Student>> s);

    Math(const Math& other);

    Math(Math&& other);

public:
    void information() const override;

};



#endif