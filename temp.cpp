#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include "./include/person.hh"
#include "./classes/person.cpp"
#include "./include/patient.hh"
#include "./classes/patient.cpp"
#include "./include/nurse.hh"
#include "./classes/nurse.cpp"
#include "./include/doctor.hh"
#include "./classes/doctor.cpp"
#include "./include/address.hh"
#include "./classes/address.cpp"
#include "./include/global.hh"
#include "./classes/global.cpp"

using namespace std;

int main() {
    Doctor d(1);
    Patient p(1);
    Nurse n(1);
    d.updatecounter();
    p.updatepcounter();
    n.N_updatecounter();

    for (;;) {
    strt:
        int ko, choice;
        cout << "Press 1 to manipulate a Doctor " << endl;
        cout << "Press 2 to manipulate a Nurse" << endl;
        cout << "Press 3 to manipulate a Patient " << endl;
        cin >> choice;

        if (choice == 1) {
        docmenu:
            cout << "1) Add a Doctor " << endl;
            cout << "2) Find a Doctor" << endl;
            cout << "3) Print a Doctor details " << endl;
            cin >> ko;

            if (ko == 1) {
                d.updatecounter();
                Doctor d1;
            } else if (ko == 2) {
                d.updatecounter();
                d.getdata();
                d.find_doctor();
            } else if (ko == 3) {
                d.getdata();
                d.printdetails();
            } else {
                cout << "Wrong Entry " << endl;
                goto docmenu;
            }
        } else if (choice == 2) {
        n_menu:
            cout << "1) Add a Nurse  " << endl;
            cout << "2) Find a Nurse " << endl;
            cout << "3) Print a Nurse detail" << endl;
            cin >> ko;

            if (ko == 1) {
                n.N_updatecounter();
                Nurse n1;
            } else if (ko == 2) {
                n.N_updatecounter();
                n.getNdata();
                n.find_nurse();
            } else if (ko == 3) {
                n.getNdata();
                n.printNdetails();
            } else {
                cout << "Wrong Entry " << endl;
                goto n_menu;
            }
        } else if (choice == 3) {
        p_menu:
            cout << "1) Add a Patient  " << endl;
            cout << "2) Find a Patient " << endl;
            cout << "3) Print details of a Patient" << endl;
            cin >> ko;

            if (ko == 1) {
                p.updatepcounter();
                Patient p1;
            } else if (ko == 2) {
                p.updatepcounter();
                p.getpdata();
                p.find_patient();
            } else if (ko == 3) {
                p.getpdata();
                p.printpdetails();
            } else {
                cout << "Added wrong " << endl;
                goto p_menu;
            }
        } else {
            cout << "Wrong Entry " << endl;
            goto strt;
        }

        int g = 0;
        cout << "Do you want to Exit(press -1 to exit) " << endl;
        cin >> g;

        if (g == -1) {
            cout << "Allah Hafiz" << endl;
            break;
        } else {
            system("clr");
            continue;
        }
    }

    return 0;
}
