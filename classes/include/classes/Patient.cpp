#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "global.hh"
#include "patient.hh"
// #include "person.cpp"

using namespace std;

Patient ::Patient()
{
    count++;
    add_patient();
}
Patient ::Patient(int a):Person(a)
{
}
int Patient::count = ptem;
void Patient ::add_patient()
{

    cout << "Enter the disease " << endl;
    cin >> disease;
    srand(time(0));
    id = (rand() % 100) + 1;
    cout << "Patient Added Successfully " << endl;
    cout << "Admit No : " << id << endl;
    savedata();
}

void Patient ::savedata()
{
    fstream file("Patient.txt", ios::app);
    fstream dc("pcounter.txt", ios::out);
    dc << Patient::count;
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
    file << disease;
    file << " , ";
    file << id;
    file << " , ";
    file << category;
    file << endl;
}

void Patient ::printpdetails()
{
    for (int t = 0; t < ptem; t++)
    {
        cout << "---------------------------------------" << endl;
        cout << "Patient # " << t + 1 << endl;
        cout << "Name : " << name[t] << endl;
        cout << "Age : " << agee[t] << endl;
        cout << "Gender: " << gend[t] << endl;
        cout << "Designation: " << cate[t] << endl;
        cout << "disease " << diseas[t] << endl;
        cout << "Phone # : " << phone[t] << endl;
        cout << "Admit no: " << i_d[t] << endl;
        cout << "Adress  : " << lan[t] << endl;
        cout << " City : " << cit[t] << endl;
        cout << " Province : " << provi[t] << endl;
        cout << " Country: " << countr[t] << endl;
        cout << "---------------------------------------" << endl;
    }
}
void Patient ::getpdata()
{

    fstream fil("Patient.txt", ios::in);
    fstream dc("pcounter.txt", ios::in);
    //
    agee = new int[ptem];
    i_d = new int[ptem];
    name = new string[ptem];
    diseas = new string[ptem];
    phone = new string[ptem];
    provi = new string[ptem];
    cit = new string[ptem];
    lan = new string[ptem];
    countr = new string[ptem];
    gend = new string[ptem];
    weigh = new string[ptem];
    cate = new string[ptem];

    // Separate name, phone, gender, and age from data array
    for (int i = 0; i < ptem; i++)
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
            string c, v;
            name[i] = (temp.substr(0, pos1));
            c = ((temp.substr(pos1 + 2, (pos2 - 1) - pos1)));
            c = removeSpaces(c);
            agee[i] = stoi(c); // Convert string to integer for age
            gend[i] = (temp.substr(pos2 + 2, (pos3 - 1) - (pos2)));
            phone[i] = (temp.substr(pos3 + 2, (pos4 - 1) - (pos3)));
            lan[i] = (temp.substr(pos4 + 2, (pos5 - 1) - (pos4)));
            cit[i] = (temp.substr(pos5 + 2, (pos6 - 1) - (pos5)));
            provi[i] = (temp.substr(pos6 + 2, (pos7 - 1) - (pos6)));
            countr[i] = (temp.substr(pos7 + 2, (pos8 - 1) - (pos7)));
            diseas[i] = (temp.substr(pos8 + 2, (pos9 - 1) - (pos8)));
            v = ((temp.substr(pos9 + 2, (pos10 - 1) - (pos9))));
            v = removeSpaces(v);
            i_d[i] = stoi(v);
            cate[i] = ((temp.substr(pos10 + 2, g - (pos10))));
        }
    }
}

void Patient ::find_patient()
{
    int te, lc = 0;

    cout << "Find the Patient by Admit No " << endl;
    cin >> te;
    for (int o = 0; o < ptem; o++)
    {
        if (i_d[o] == te)
        {
            lc++;
            cout << "Patient Founded Successfully " << endl;
            cout << "Name : " << name[o] << endl;
            cout << "Disease : " << diseas[o] << endl;
            cout << "Phone No : " << phone[o] << endl;
        }
    }
    if (lc == 0)
    {
        cout << "Patient not exist " << endl;
    }
}
void Patient ::updatepcounter()
{
    string t;
    fstream fil("pcounter.txt", ios::in);
    getline(fil, t);
    t = removeSpaces(t);

    ptem = stoi(t);
    Patient::count = ptem;
}