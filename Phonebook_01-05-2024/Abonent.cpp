#include <iostream>
#include "Abonent.h"

using namespace std;

Abonent& Abonent::setSurname(const char* surnameP)
{
    auto len {strlen(surnameP) + 1};    // +1 for '\0'
    if (!surname) { surname = new char[len]; }
    else if (surname and strlen(surname) + 1 < len)
    {
        delete[] surname;
        surname = new char[len];
    }
    strcpy_s(surname, len, surnameP);
    return *this;
}

Abonent& Abonent::setName(const char* nameP)
{
    auto len{ strlen(nameP) + 1 };
    if (!name) { name = new char[len]; }
    else if (name and strlen(name) + 1 < len)
    {
        delete[] name;
        name = new char[len];
    }
    strcpy_s(name, len, nameP);
    return *this;
}

Abonent& Abonent::setSecondName(const char* secondNameP)
{
    auto len{ strlen(secondNameP) + 1 };
    if (!secondName) { secondName = new char[len]; }
    else if (secondName and strlen(secondName) + 1 < len)
    {
        delete[] secondName;
        secondName = new char[len];
    }
    strcpy_s(secondName, len, secondNameP);
    return *this;
}

char* Abonent::initSurname(const char* surnameP)
{
    surname = { new char[strlen(surnameP) + 1] };
    strcpy_s(surname, strlen(surnameP) + 1, surnameP);
    return surname;
}
char* Abonent::initName(const char* NameP)
{
    name = { new char[strlen(NameP) + 1] };
    strcpy_s(name, strlen(NameP) + 1, NameP);
    return name;
}
char* Abonent::initSecondName(const char* secondNameP)
{
    secondName = { new char[strlen(secondNameP) + 1] };
    strcpy_s(secondName, strlen(secondNameP) + 1, secondNameP);
    return secondName;
}

Abonent& Abonent::init(const char* surnameP, const char* nameP, const char* secondNameP)
{
    setSurname(surnameP);
    setName(nameP);
    setSecondName(secondNameP);
    return *this;
}

Abonent& Abonent::print()
{
    cout << "\033[1;32m" << "Surname: " << "\033[0m" << surname
        << "\033[1;32m" << "\nName: " << "\033[0m" << name << "\nSecond name: " << secondName << '\n';
    return *this;
}