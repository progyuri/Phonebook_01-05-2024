#include <iostream>
#include "Phonebook.h"
#include <fstream>>

using namespace std;	

PhoneBook& PhoneBook::setContactDetails(const char* addContactDetailsP)
{
    auto len{ strlen(addContactDetailsP) + 1 };
    if (!addContactDetails) { addContactDetails = new char[len]; }
    else if (addContactDetails and strlen(addContactDetails) + 1 < len)
    {
        delete[] addContactDetails;
        addContactDetails = new char[len];
    }
    strcpy_s(addContactDetails, len, addContactDetailsP);
    return *this;
}

char* PhoneBook::initContactDetailsP(const char* addContactDetailsP)
{
    addContactDetails = { new char[strlen(addContactDetailsP) + 1] };
    strcpy_s(addContactDetails, strlen(addContactDetailsP) + 1, addContactDetailsP);
    return addContactDetails;
}

PhoneBook& PhoneBook::init(const char* surnameP, const char* nameP, const char* secondNameP, int homePhoneP, int workPhoneP, int mobilePhoneP, const char* addContactDetailsP)
{
    setContacts(surnameP, nameP, secondNameP);
    homePhone = homePhoneP;
    workPhone = workPhoneP;
    mobilePhone = mobilePhoneP;
    setContactDetails(addContactDetailsP);
    return *this;
}

PhoneBook& PhoneBook::print()
{
    contact.print();
    cout << "Home phone: " << homePhone << "\nWork phone: " << workPhone << "\nMobile phone: " << mobilePhone
        << "\nAdditional contact details: " << addContactDetails << '\n';
    return *this;
}

void listPhoneBook(PhoneBook* begin, PhoneBook* end)
{
    for (auto contacts{begin}; contacts != end; ++contacts)
    {
        contacts->print(); cout << '\n';
    }
}

void contactSearch(PhoneBook* begin, PhoneBook* end, char* found, bool(*searchCriterion)(const PhoneBook& const contacts, char* found))
{
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        if (searchCriterion(*contacts, found)) { contacts->print(); std::cout << '\n'; }
    }
}

bool searchBySurname(const PhoneBook& const contacts, char* found)
{
    return strstr(contacts.getContactSurname(), found);
}

bool searchByName(const PhoneBook& const contacts, char* found)
{
    return strstr(contacts.getContactName(), found);
}

void savePhoneBook(PhoneBook* begin, PhoneBook* end)
{
    ofstream outf;
    outf.open("PhoneBook.txt");
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        outf << contacts->getContactSurname() << '\n';
        outf << contacts->getContactName() << '\n';
        outf << contacts->getContactSecondName() << '\n';
        outf << contacts->getHomePhone() << '\n';
        outf << contacts->getWorkPhone() << '\n';
        outf << contacts->getMobilePhone() << '\n';
        outf << contacts->getaddContactDetails() << '\n';
    }
    outf.close();
}

void loadPhoneBook(PhoneBook* begin, PhoneBook* end)
{
    ifstream inf;
    char surnameP[15];
    char nameP[15];
    char secondNameP[15];
    int homePhoneP{ 0 };
    int workPhoneP{ 0 };
    int mobilePhoneP{ 0 };
    char contactDetailsP[15];

    inf.open("PhoneBook.txt");
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        inf.getline(surnameP, 15);
        inf.getline(nameP, 15);
        inf.getline(secondNameP, 15);
        inf >> homePhoneP;
        inf >> workPhoneP;
        inf >> mobilePhoneP;
        inf.ignore(100, '\n');
        inf.getline(contactDetailsP, 15);
        contacts->init(surnameP, nameP, secondNameP, homePhoneP, workPhoneP, mobilePhoneP, contactDetailsP);
    }
    inf.close();
}

void pastInArr(PhoneBook*& Arr, size_t& arrSize, size_t idxPastElem)
{
    PhoneBook* newArr{ new PhoneBook[arrSize + 1] };
    for (size_t i{ 0 }; i < arrSize; ++i)
    {
        newArr[i + (i >= idxPastElem)].PhoneBook::PhoneBook(Arr[i]);
    }
    delete[] Arr;
    Arr = newArr;
    arrSize++;
}

void cutFromArr(PhoneBook*& Arr, size_t& arrSize, size_t idxCutElem)
{
    PhoneBook* newArr{ new PhoneBook[arrSize--] };
    for (size_t i{ 0 }; i < arrSize; ++i)
    {
        newArr[i].PhoneBook::PhoneBook(Arr[i + (i >= idxCutElem)]);
    }
    delete[]Arr;
    Arr = newArr;
}

void phoneBookSort(PhoneBook* contacts, size_t PhoneBookSize, bool(*criteria)(const PhoneBook& contactsA, const PhoneBook& contactsB))
{
    PhoneBook tmp;
    for (size_t head{ 0 }; head < PhoneBookSize; ++head)
    {
        for (size_t tail{ PhoneBookSize - 1 }; tail > head; --tail)
        {
            if (criteria(contacts[tail], contacts[head]))
            {
                tmp.PhoneBook::PhoneBook(contacts[tail]);
                contacts[tail].PhoneBook::PhoneBook(contacts[head]);
                contacts[head].PhoneBook::PhoneBook(tmp);
            }
        }
    }
}

bool sortBySurname(const PhoneBook& contactsA, const PhoneBook& contactsB)
{
    return strcmp(contactsA.getContactSurname(), contactsB.getContactSurname()) < 0;
}

bool sortByName(const PhoneBook& contactsA, const PhoneBook& contactsB)
{
    return strcmp(contactsA.getContactName(), contactsB.getContactName()) < 0;
};

