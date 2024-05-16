#include<iostream>
#include<string>
#include "./include/global.hh"
using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}