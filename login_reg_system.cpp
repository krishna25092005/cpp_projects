/**
 * @file login_reg_system.cpp
 * @author Krishna Chauhan
 * @date 2024-10-29
 *
 * @brief A simple registration and login system using C++.
 *
 * This program allows users to register with a login ID and a password,
 * and then log in using the same credentials. The credentials are stored
 * in a text file. The program provides a simple console-based interface
 * for user interaction.
 *
 * @details
 * Features:
 * - User registration with validation for a strong password.
 * - User login with credential verification.
 * - Simple text file storage for user credentials.
 *
 * @note 
 * This implementation uses basic file I/O and is not secure for real-world applications. Passwords are stored in plain text.
 */

#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class Login
{
private:
    string LoginID, Password;

public:
    Login() : LoginID(""), Password("") {}

    void setID(string id)
    {
        LoginID = id;
    }

    void setPW(string pw)
    {
        Password = pw;
    }

    string getID()
    {
        return LoginID;
    }

    string getPW()
    {
        return Password;
    }
};

void registration(Login log)
{
    system("cls");
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;
    log.setID(id);

start:
    cout << "\tEnter A Strong Password: ";
    cin >> pw;
    if (pw.length() >= 8)
    {
        log.setPW(pw);
    }
    else
    {
        cout << "\tEnter Minimum 8 Characters!" << endl;
        goto start;
    }
    ofstream outfile("D:/Login.txt", ios::app);
    if (!outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        outfile << "\t" << log.getID() << " : " << log.getPW() << endl
                << endl;
        cout << "\tUser Registered Successfuly!" << endl;
    }
    outfile.close();
    Sleep(3000);
}

void login()
{
    system("cls");
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile("D:/Login.txt");
    if (!infile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        string line;
        bool found = false;
        while (getline(infile, line))
        {
            stringstream ss;
            ss << line;
            string userID, userPW;
            char delimiter;
            ss >> userID >> delimiter >> userPW;

            if (id == userID && pw == userPW)
            {
                found = true;

                cout << "\tPlease Wait";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    Sleep(800);
                }
                system("cls");
                cout << "\tWelcome To This Page!" << endl;
                cout << "Thanks for you visit to my account !!" << endl;
            }
        }
        if (!found)
        {
            cout << "\tError: Incorrect Login ID Or Password!" << endl;
        }
    }
    infile.close();
    Sleep(5000);
}

int main()
{
    Login log;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome To Registration & Login Form" << endl;
        cout << "\t====================================" << endl;
        cout << "\t1. Register User" << endl;
        cout << "\t2. Login" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1)
        {
            registration(log);
        }

        else if (val == 2)
        {
            login();
        }

        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\tHave a good day!" << endl;
            Sleep(3000);
        }
        Sleep(3000);
    }
}