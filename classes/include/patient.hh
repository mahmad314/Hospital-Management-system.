#ifndef PATIENT
#define PATIENT
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "person.hh"



using namespace std;


class Patient : public Person
{
protected:
    string disease;

public:
    static int count;
    Patient();
    Patient(int a);
    
    void add_patient();

void printpdetails();
    
    void savedata();
void getpdata();
void updatepcounter();
void find_patient();
    
};
#endif
    


