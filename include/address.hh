#ifndef ADDRESS
#define ADDRESS
#include <string>
using namespace std;
class Address
{
public:
    string city;
    string lane;
    string province;
    string country;
    void print_address();
    inline string getlane();
    inline string getcity();
    inline string getprovince();
    inline string getcountry();
    void input_address();
};
#endif