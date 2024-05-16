#ifndef DOCTOR
#define DOCTOR
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "person.hh"

using namespace std;
class Doctor : public Person
{
protected:
    string specialization;
    int appointments;

public:
    static int count;
    Doctor();
    Doctor(int a);
    void add_doctor();
    void savedata();
    void printdetails();
    void getdata();
    void find_doctor();
    void updatecounter();
};
#endif
