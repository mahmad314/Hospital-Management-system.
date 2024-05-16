
#include <iostream>
#include <string>
#include "./include/address.hh"
#include "./include/global.hh"
using namespace std;
void Address::print_address()
{
    cout << "Address : " << lane << endl
    << "city : " << city << endl
    << "Province :" << province << endl
    << "Country : " << country << endl;
}
string Address ::getlane() { return lane; }
string Address ::getcity() { return city; }
string Address ::getprovince() { return province; }
string Address ::getcountry() { return country; }
void Address::input_address()
{

    cout << "Enter  address : ";
    getline(cin, lane);

    cout << "\nEnter  City : " << endl;
    getline(cin, city);

    cout << "\nEnter  Province : " << endl;
    getline(cin, province);

    cout << "\nEnter  Country : " << endl;
    getline(cin, country);
}