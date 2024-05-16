#ifndef NURSE
#define NURSE
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "person.hh"


using namespace std;


class Nurse : public Person
{
protected:
    string shift;

public:
    static int count;
    Nurse();
    Nurse(int a);
    void add_nurse();
    void savedata();
    void getNdata();
    void find_nurse();
    void N_updatecounter();
    void printNdetails();
};
#endif