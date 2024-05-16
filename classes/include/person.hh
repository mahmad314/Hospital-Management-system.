
#ifndef PERSON
#define PERSON
#include <string>
#include "address.hh"

using namespace std;

class Person
{
protected:
    int id;
    string f_name, l_name;
    int age;
    string gender;
    Address a;
    string phone_no;
    string category;

public:
    Person();
    Person(int a);
    inline string getfname();
    inline string getlname();
    inline string getgender();
    inline int getage();
    void add_person();
    void print_details();
    
};
#endif