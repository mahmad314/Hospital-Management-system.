#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "global.hh"
#include "doctor.hh"
// #include "person.cpp"
using namespace std;
    static int count;
    Doctor :: Doctor(){
        count++;
        add_doctor();
    }
    Doctor :: Doctor(int a):Person(a){
        
    }
    void Doctor :: add_doctor()
    {
        
        cout << "Enter the specialization " << endl;
        cin >> specialization;
        srand(time(0));
        id = (rand() % 100) + 100;
        savedata();
        cout<<"Doctor added Succesfully"<<endl;
        cout<<"ID : "<<id<<endl;
    }

    void Doctor :: savedata()
    {
        fstream file("doctor.txt", ios::app);
        fstream dc("counter.txt", ios::out);
        dc<<Doctor::count;
        if ((!dc.is_open()) || (!file.is_open()))
        {
            cout << "Error in opening the file " << endl;
        }
        file << f_name;
        file << " ";
        file << l_name;
        file << " , ";
        file << age;
        file << " , ";
        file << gender;
        file << " , ";
        file << phone_no;
        file << " , ";
        file << a.getlane();
        file << " , ";
        file << a.getcity();
        file << " , ";
        file << a.getprovince();
        file << " , ";
        file << a.getcountry();
        file << " , ";
        file << specialization;
        file << " , ";
        file << id;
        file << " , ";
        file << category;
        file << endl;
    }
int Doctor::count = tem;
void Doctor ::  printdetails()
    {
        for (int t = 0; t < tem; t++)
        {
            cout << "---------------------------------------" << endl;
            cout << "Doctor # " << t + 1 << endl;
            cout << "Name : " << name[t] << endl;
            cout << "Age : " << agee[t] << endl;
            cout << "Gender: " << gend[t] << endl;
            cout << "Designation: " << cate[t] << endl;
            cout << "specialization " << speciality[t] << endl;
            cout << "Phone # : " << phone[t] << endl;
            cout << "ID: " << i_d[t] << endl;
            cout << "Adress  : " << lan[t] << endl;
            cout << " City : " << cit[t] << endl;
            cout << " Province : " << provi[t] << endl;
            cout << " Country: " << countr[t] << endl;
            cout << "---------------------------------------" << endl;
        }
    }
void Doctor :: getdata()
{

    fstream fil("doctor.txt", ios::in);
    fstream dc("counter.txt", ios::in);
    //
    agee = new int[tem];
    i_d = new int[tem];
    name = new string[tem];
    speciality = new string[tem];
    phone = new string[tem];
    provi = new string[tem];
    cit = new string[tem];
    lan = new string[tem];
    countr = new string[tem];
    gend = new string[tem];
    p_type = new string[tem];
    cate = new string[tem];

    // Separate name, phone, gender, and age from data array
    for (int i = 0; i < tem; i++)
    {
        string temp;
        getline(fil, temp);
        int pos1 = temp.find(" , ");           // 4
        int pos2 = temp.find(" , ", pos1 + 3); // 8
        int pos3 = temp.find(" , ", pos2 + 3);
        int pos4 = temp.find(" , ", pos3 + 3);
        int pos5 = temp.find(" , ", pos4 + 3);
        int pos6 = temp.find(" , ", pos5 + 3);
        int pos7 = temp.find(" , ", pos6 + 3);
        int pos8 = temp.find(" , ", pos7 + 3);
        int pos9 = temp.find(" , ", pos8 + 3);
        int pos10 = temp.find(" , ", pos9 + 3);
        int g = temp.size();
        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos && pos4 != string::npos && pos5 != string::npos && pos6 != string::npos && pos7 != string::npos && pos8 != string::npos && pos9 != string::npos)
        {
            string c,v;
            name[i] = (temp.substr(0, pos1));
            c = ((temp.substr(pos1 + 2, (pos2 - 1) - pos1)));
            c=removeSpaces(c);
            agee[i]=stoi(c); // Convert string to integer for age
            gend[i] = (temp.substr(pos2 + 2, (pos3 - 1) - (pos2)));
            phone[i] = (temp.substr(pos3 + 2, (pos4 - 1) - (pos3)));
            lan[i] = (temp.substr(pos4 + 2, (pos5 - 1) - (pos4)));
            cit[i] = (temp.substr(pos5 + 2, (pos6 - 1) - (pos5)));
            provi[i] = (temp.substr(pos6 + 2, (pos7 - 1) - (pos6)));
            countr[i] = (temp.substr(pos7 + 2, (pos8 - 1) - (pos7)));
            speciality[i] = (temp.substr(pos8 + 2, (pos9 - 1) - (pos8)));
            v= ((temp.substr(pos9 + 2, (pos10 - 1) - (pos9))));
            v=removeSpaces(v);
            i_d[i]=stoi(v);
            cate[i] = ((temp.substr(pos10 + 2, g - (pos10))));
        }
    }
}

void Doctor :: find_doctor()
{
    int te, lc = 0;

    cout << "Find the Doctor by ID" << endl;
    cin >> te;
    for (int o = 0; o < tem; o++)
    {
        if (i_d[o] == te)
        {
            lc++;
            cout << "Doctor Founded Successfully " << endl;
            cout << "Name : " << name[o] << endl;
            cout << "Speciality : " << speciality[o] << endl;
            cout << "Phone No : " << phone[o] << endl;
        }
    }
    if (lc == 0)
    {
        cout << "Doctor not exist " << endl;
    }
}
void Doctor :: updatecounter()
{
    string t;
    fstream fil("counter.txt", ios::in);
    getline(fil, t);
    t=removeSpaces(t);

    tem = stoi(t);
    Doctor::count = tem;
}
