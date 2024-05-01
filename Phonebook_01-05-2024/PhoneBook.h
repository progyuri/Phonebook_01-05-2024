#pragma once
#include <iostream>
#include "Abonent.h"

using namespace std;

class PhoneBook
{
    Abonent contact;
    int homePhone;
    int workPhone;
    int mobilePhone;
    char* addContactDetails;

public:
    PhoneBook() : PhoneBook{ " ", " "," ", 0,0,0," " } {}
    PhoneBook(const char* surnameP, const char* nameP, const char* secondNameP, int homePhoneP, int workPhoneP, int mobilePhoneP, const char* addContactDetailsP) :
        contact{ surnameP,nameP,secondNameP },
        homePhone{ homePhoneP },
        workPhone{ workPhoneP },
        mobilePhone{ mobilePhoneP },
        addContactDetails{ initContactDetailsP(addContactDetailsP) } {}
    PhoneBook(const PhoneBook& contacts) :
        contact{ contacts.contact },
        homePhone{ contacts.homePhone },
        workPhone{ contacts.workPhone },
        mobilePhone{ contacts.mobilePhone },
        addContactDetails{ initContactDetailsP(contacts.addContactDetails) } {}

    PhoneBook& setContacts(const char* surnameP, const char* nameP, const char* secondNameP)
    {
        contact.setSurname(surnameP);
        contact.setName(nameP);
        contact.setSecondName(secondNameP);
        return *this;
    }

    PhoneBook& setHomePhone(int homePhoneP) { homePhone = homePhoneP; return *this; }
    PhoneBook& setWorkPhone(int workPhoneP) { workPhone = workPhoneP; return *this; }
    PhoneBook& setMobilePhone(int mobilePhoneP) { mobilePhone = mobilePhoneP; return *this; }

    PhoneBook& setContactDetails(const char* addContactDetailsP);

    const char* getContactSurname()const { return contact.getSurname(); }
    const char* getContactName()const { return contact.getName(); }
    const char* getContactSecondName()const { return contact.getSecondName(); }

    int getHomePhone()const { return homePhone; }
    int getWorkPhone()const { return workPhone; }
    int getMobilePhone()const { return mobilePhone; }

    const char* getaddContactDetails()const { return addContactDetails; }

    char* initContactDetailsP(const char* addContactDetailsP);

    PhoneBook& init(const char* surnameP, const char* nameP, const char* secondNameP, int homePhoneP, int workPhoneP, int mobilePhoneP, const char* addContactDetailsP);

    PhoneBook& print();

    ~PhoneBook() { delete[] addContactDetails; }
    
};

void listPhoneBook(PhoneBook*, PhoneBook*);
void contactSearch(PhoneBook*, PhoneBook*, char*, bool(*searchCriterion)(const PhoneBook& const contacts, char* found));
bool searchBySurname(const PhoneBook& const , char*);
bool searchByName(const PhoneBook& const , char*);
void savePhoneBook(PhoneBook*, PhoneBook*);
void loadPhoneBook(PhoneBook*, PhoneBook*);
void pastInArr(PhoneBook*&, size_t&, size_t);
void cutFromArr(PhoneBook*&, size_t&, size_t);
void phoneBookSort(PhoneBook*, size_t, bool(*)(const PhoneBook&, const PhoneBook&));
bool sortBySurname(const PhoneBook& contactsA, const PhoneBook&);
bool sortByName(const PhoneBook&, const PhoneBook&);
