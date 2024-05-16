#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "./include/global.hh"
#include "./include/Nurse.hh"
// #include "person.cpp"

using namespace std;
Nurse ::Nurse()
{
    count++;
    add_nurse();
}
int Nurse::count = ntem;
Nurse ::Nurse(int a):Person (a)
{
}
void Nurse ::add_nurse()
{

    cout << "Please select shift (Morning/Evening) : ";
    cin >> shift;
    srand(time(0));
    id = (rand() % 100) + 1;
    cout << "Nurse  added Succesfully" << endl;
    cout << "ID : " << id << endl;
    savedata();
}

void Nurse ::savedata()
{
    fstream file("./data/nurse.txt", ios::app);
    fstream dc("./data/N_counter.txt", ios::out);
    dc << Nurse::count;
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
    file << shift;
    file << " , ";
    file << id;
    file << " , ";
    file << category;
    file << endl;
}
void Nurse ::printNdetails()
{
    for (int t = 0; t < ntem; t++)
    {
        cout << "---------------------------------------" << endl;
        cout << "Nurse # " << t + 1 << endl;
        cout << "Name : " << name[t] << endl;
        cout << "Age : " << agee[t] << endl;
        cout << "Gender: " << gend[t] << endl;
        cout << "Designation: " << cate[t] << endl;
        cout << "Shift " << Shiftt[t] << endl;
        cout << "Phone # : " << phone[t] << endl;
        cout << "ID: " << i_d[t] << endl;
        cout << "Adress  : " << lan[t] << endl;
        cout << " City : " << cit[t] << endl;
        cout << " Province : " << provi[t] << endl;
        cout << " Country: " << countr[t] << endl;
        cout << "---------------------------------------" << endl;
    }
}
void Nurse ::getNdata()
{

    fstream fil("./data/nurse.txt", ios::in);
    fstream dc("./data/N_counter.txt", ios::in);
    //
    agee = new int[ntem];
    i_d = new int[ntem];
    name = new string[ntem];
    Shiftt = new string[ntem];
    phone = new string[ntem];
    provi = new string[ntem];
    cit = new string[ntem];
    lan = new string[ntem];
    countr = new string[ntem];
    gend = new string[ntem];
    p_type = new string[ntem];
    cate = new string[ntem];

    // Separate name, phone, gender, and age from data array
    for (int i = 0; i < ntem; i++)
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
            Shiftt[i] = (temp.substr(pos8 + 2, (pos9 - 1) - (pos8)));
            v = ((temp.substr(pos9 + 2, (pos10 - 1) - (pos9))));
            v = removeSpaces(v);
            i_d[i] = stoi(v);
            cate[i] = ((temp.substr(pos10 + 2, g - (pos10))));
        }
    }
}

void Nurse ::find_nurse()
{
    int te, lc = 0;

    cout << "Find the Nurse by ID" << endl;
    cin >> te;
    for (int o = 0; o < ntem; o++)
    {
        if (i_d[o] == te)
        {
            lc++;
            cout << "Nurse Founded Successfully " << endl;
            cout << "Name : " << name[o] << endl;
            cout << "Shift : " << Shiftt[o] << endl;
            cout << "Phone No : " << phone[o] << endl;
        }
    }
    if (lc == 0)
    {
        cout << "Nurse not exist " << endl;
    }
}
void Nurse ::N_updatecounter()
{
    string t;
    fstream fil("./data/N_counter.txt", ios::in);
    getline(fil, t);
    t = removeSpaces(t);

    ntem = stoi(t);
    Nurse::count = ntem;
}
