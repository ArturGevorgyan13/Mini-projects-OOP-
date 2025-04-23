#ifndef _HCS
#define _HCS

#include <iostream>
#include <vector>

class Patient{

private:
    std::string name;
    std::string contact;

public:
    Patient()=default;

    Patient(std::string n,std::string c);

    Patient(const Patient& other)=default;

    Patient(Patient&& other)=default;

    ~Patient()=default;

public:
    std::string getname() const;

    std::string getcontact() const;

    void setname(std::string n);

    void setcontact(std::string c);

};

class Doctor{

private:
    std::string name;
    std::string contact;
    std::string speciality;

public:

    Doctor()=default;

    Doctor(std::string n,std::string c,std::string s);

    Doctor(const Doctor& other)=default;

    Doctor(Doctor&& other)=default;

    ~Doctor()=default;

public:
    std::string getname() const;

    std::string getcontact() const;

    std::string getspeciality() const;

    void setname(std::string n);

    void setcontact(std::string c);

    void setspeciality(std::string s);

};

class Appointment{

public:
    Patient* patient;
    Doctor* doctor;
    std::string time;

public:
    Appointment()=default;

    Appointment(Patient* p,Doctor* d,std::string t);

    Appointment(const Appointment& other);

    Appointment(Appointment&& other);

    virtual ~Appointment()=0;

public:

    Patient* getPatient() const;

    Doctor* getDoctor() const;

    std::string gettime() const;

    void setPatient(Patient* p);

    void setDoctor(Doctor* d);

    void settime(std::string t);

};

class Inperson: public Appointment{

public:
    Inperson()=default;

    Inperson(Patient* p,Doctor* d,std::string t);

    Inperson(const Inperson& other);

    Inperson(Inperson&& other);

    ~Inperson()=default;

};

class Virtual: public Appointment{

public:
    Virtual()=default;

    Virtual(Patient* p,Doctor* d,std::string t);

    Virtual(const Virtual& other);

    Virtual(Virtual&& other);

    ~Virtual()=default;

};

class Program{

public:
    std::vector<Patient*> patients;
    std::vector<Doctor*> doctors;
    std::vector<Appointment*> appointments;

public:
    void scheduleappInperson(std::string np,std::string nd,std::string t);

    void scheduleappVirtual(std::string np,std::string nd,std::string t);

    void manageschedule(std::string np,std::string nd,std::string t);

    void showPatient(std::string n);

public:
    void addPatient(std::string n,std::string c);

    void addDoctor(std::string n,std::string c,std::string s);

};

#endif