#include <iostream>
#include <string>
#include "./include/person.hh"
#include "./include/global.hh"



using namespace std;
    Person :: Person(){
        add_person();
    }
    Person :: Person(int a){
    }


    string Person :: getfname() { return f_name; }
    string Person :: getlname() { return l_name; }
    string Person :: getgender() { return gender; }
    int Person ::getage() { return age; }
    void Person :: add_person()
    {
        cout << "Enter First Name :  ";
        cin >> f_name;
        cout << "\nEnter Last Name :  ";
        cin >> l_name;
        cout << "\nEnter Age  :  ";
        cin >> age;
        cin.ignore();
        cout << "Enter  your Gender" << endl;
        cin >> gender;
        cin.ignore();
        a.input_address();
        cout << "\nEnter Phone :";
        getline(cin, phone_no);
        cout << "Enter  Category :  ";
        getline(cin, category);
    }
    void Person :: print_details()
    {
        cout << "First Name : " << f_name << "\t Last Name " << l_name << endl;
        cout << "Age : " << age << endl;
        cout << "Gender:(M male F female) " << gender << endl;
        cout << "Contact  # : " << phone_no << endl;
        cout << "Category : " << category << endl;
        a.print_address();
    }