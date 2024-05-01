#include <iostream>
#include "Abonent.h"
#include "PhoneBook.h"



using namespace std;        

int main()
{
    size_t PhoneBookSize{ 10 };
    PhoneBook* contacts{ new PhoneBook[PhoneBookSize] };
    auto contactsEnd { contacts + PhoneBookSize };


  
    contacts[0].init("Kulyk", "Volodymir", "Oleksandrovich", 0, 0, 79116724589, " ");
    contacts[1].init("Ivanov", "Oleg", "Vasylyovich", 0, 0, 78911457890, " ");
    contacts[2].init("Kozlov", "Ivan", "Stepanovich", 0, 0, 7911111111, " ");
    contacts[3].init("Kozodubov", "Andriy", "Mykolayovich", 0, 0, 7945555555, "Friend");
    contacts[4].init("Philipchuk", "Yriy", "Leonidvich", 312221321, 312231705, 7919910000, "Director");
    contacts[5].init("Karasev", "Dmytro", "Stepanovich", 0, 312225565, 7679638521, " ");
    contacts[6].init("Shevchuk", "Oleksander", "Ivanovich", 0, 312225533, 7670996523, " ");
    contacts[7].init("Solovey", "Andriy", "Oleksandrovich", 312228511, 312231799, 7507412525, "Mechanic");
    contacts[8].init("Havryluk", "Valeriy", "Stepanovich", 312221300, 0, 795045754300, " ");
    contacts[9].init("Marchuk", "Sergey", "Vasilevich", 312221515, 312231755, 79501518895, "Doctor");
 

    listPhoneBook(contacts, contactsEnd);

    char foundS[]{ "Marchuk" };
    cout << "\033[1;31m" << "\nSearch by Surname:\n" << "\033[0m";
    contactSearch(contacts, contactsEnd, foundS, searchBySurname);

    char foundN[]{ "Andriy" };
    std::cout << "\033[1;31m" << "\nSearch by name:\n" << "\033[0m";
    contactSearch(contacts, contactsEnd, foundN, searchByName);

    savePhoneBook(contacts, contactsEnd);

    std::cout << "\033[1;31m" << "\nLoad contacts from file :\n" << "\033[0m";
    PhoneBook* fileContacts{ new PhoneBook[PhoneBookSize] };
    auto fileContactsEnd{ fileContacts + PhoneBookSize };
    loadPhoneBook(fileContacts, fileContactsEnd);
    listPhoneBook(fileContacts, fileContactsEnd);

    cout << "\033[1;31m" << "\nAdd contact in contacts :\n" << "\033[0m";
    pastInArr(contacts, PhoneBookSize, 3);
    contacts[3].init("Savchuk", "Oleh", "Olehovich", 0, 0, 502582525, "worker");
    listPhoneBook(contacts, contacts + PhoneBookSize);

    cout << "\033[1;31m" << "\nDelete contact from contacts :\n" << "\033[0m";
    cutFromArr(contacts, PhoneBookSize, 3);
    listPhoneBook(contacts, contacts + PhoneBookSize);

    phoneBookSort(contacts, PhoneBookSize, sortBySurname);
    std::cout << "\033[1;31m" << "\nSorted by Surname:\n" << "\033[0m";
    listPhoneBook(contacts, contacts + PhoneBookSize);

    delete[] contacts;
  
}



