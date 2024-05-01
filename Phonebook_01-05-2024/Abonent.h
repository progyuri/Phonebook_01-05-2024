#pragma once

class Abonent
{
    char* surname;
    char* name;
    char* secondName;
public:
    Abonent(): surname(nullptr), name(nullptr), secondName(nullptr) {}
    Abonent(const char* surnameP, const char* nameP, const char* secondNameP): 
        surname{ initSurname(surnameP) }, 
        name{ initName(nameP) }, 
        secondName { initSecondName(secondNameP) } {}


    Abonent(const Abonent& object) :
        surname{ initSurname(object.surname) }, 
        name{ initName(object.name) }, 
        secondName{ initSecondName(object.secondName) } {}

    Abonent& setSurname(const char* surnameP);
    Abonent& setName(const char* nameP);
    Abonent& setSecondName(const char* secondNameP);

    const char* getSurname()const { return surname; }
    const char* getName()const { return name; }
    const char* getSecondName()const { return secondName; }

    char* initSurname(const char* surnameP);
    char* initName(const char* nameP);
    char* initSecondName(const char* secondNameP);

    Abonent& init(const char* surnameP, const char* nameP, const char* secondNameP);
    Abonent& print();

    ~Abonent() { delete[] surname; delete[] name; delete[] secondName; }
};



