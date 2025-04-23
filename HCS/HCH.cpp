#include "HCS.h"

Patient::Patient(std::string n,std::string c): name(n),contact(c){}

std::string Patient::getname() const{

    return name;

}

std::string Patient::getcontact() const{

    return contact;

}

void Patient::setname(std::string n){

    name=n;

}

void Patient::setcontact(std::string c){

    contact=c;

}

Doctor::Doctor(std::string n,std::string c,std::string s): name(n),contact(c),speciality(s){}

std::string Doctor::getname() const{

    return name;

}

std::string Doctor::getcontact() const{

    return contact;

}

std::string Doctor::getspeciality() const{

    return speciality;

}

void Doctor::setname(std::string n){

    name=n;

}

void Doctor::setcontact(std::string c){

    contact=c;

}

void Doctor::setspeciality(std::string s){

    speciality=s;

}

Appointment::Appointment(Patient* p,Doctor* d,std::string t): patient(p),doctor(d),time(t){}

Appointment::Appointment(const Appointment& other): patient(new Patient(*(other.patient))),doctor(new Doctor(*(other.doctor))){}

Appointment::Appointment(Appointment&& other): patient(other.patient),doctor(other.doctor),time(other.time){

    other.patient=nullptr;

    other.doctor=nullptr;

}

Appointment::~Appointment(){

    delete patient;

    delete doctor;

}

Inperson::Inperson(Patient* p,Doctor* d,std::string t): Appointment(p,d,t){}

Inperson::Inperson(const Inperson& other): Appointment(other){}

Inperson::Inperson(Inperson&& other): Appointment(other){}

Virtual::Virtual(Patient* p,Doctor* d,std::string t): Appointment(p,d,t){}

Virtual::Virtual(const Virtual& other): Appointment(other){}

Virtual::Virtual(Virtual&& other): Appointment(other){}

void Program::addPatient(std::string n,std::string c){

    Patient* patient=new Patient(n,c);

    patients.push_back(patient);

}

void Program::addDoctor(std::string n,std::string c,std::string s){

    Doctor* doctor=new Doctor(n,c,s);

    doctors.push_back(doctor);

}

void Program::scheduleappInperson(std::string np,std::string nd,std::string t){

    Appointment* appointment;

    Patient* p;

    for(const auto& it:patients){

        if(it->getname()==np){

            p=it;

        }

    }

    Doctor* d;

    for(const auto& it:doctors){

        if(it->getname()==nd){

            d=it;

        }

    }

    appointment=new Inperson(p,d,t);

    appointments.push_back(appointment);

}


void Program::scheduleappVirtual(std::string np,std::string nd,std::string t){

    Appointment* appointment;

    Patient* p;

    for(const auto& it:patients){

        if(it->getname()==np){

            p=it;

        }

    }

    Doctor* d;

    for(const auto& it:doctors){

        if(it->getname()==nd){

            d=it;

        }

    }

    appointment=new Virtual(p,d,t);

    appointments.push_back(appointment);

}

int main()

{

    Program program;

    program.addPatient("Artur","111");
    program.addPatient("Arman","222");

    program.addDoctor("Simonyan","001","Dentist");
    program.addDoctor("Petrosyan","002","Trauma");

    program.scheduleappInperson("Artur","Simonyan","14:00");
    program.scheduleappVirtual("Arman","Petrosyan","15:00");

    //program.manageschedule("Artur","Simonyan","13:00");

    //program.showPatient("Artur");

    std::cout<<program.appointments[1]->doctor->getname();

    return 0;

}