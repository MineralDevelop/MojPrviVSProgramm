// MojPrviVSProgramm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    fstream datoteka;
    int izbor = -1;
    int tracker = 0;
    string line;
    int counter = 0;

    datoteka.open("imenik.txt", ios::in);
    while (getline(datoteka, line))
        counter++;
    datoteka.close();

    string* imeprezime = new string[1000];

    datoteka.open("imenik.txt", ios::in);
    for (int i = 0; i < counter; i++)
    {
        getline(datoteka, imeprezime[i]);
    }
    datoteka.close();

    while (izbor != 0)
    {
        cin >> izbor;
        cin.ignore();
        while (izbor>0)
        {
            getline(cin, imeprezime[counter]);
            counter++;
            izbor--;
        }
    }

    sort(imeprezime, imeprezime + counter);

    datoteka.open("imenik.txt", ios::out | ios::trunc);
    datoteka.close();

    datoteka.open("imenik.txt", ios::out);
    for (int i = 0; i < counter; i++)
    {
        datoteka << imeprezime[i] << endl;
    }
    datoteka.close();

    datoteka.open("imenik.txt", ios::in);
    for (int i = 0; i < counter; i++)
    {
        getline(datoteka, imeprezime[i]);
    }
    datoteka.close();

    for (int i = 0; i < counter; i++)
    {
        cout << imeprezime[i] << endl;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
