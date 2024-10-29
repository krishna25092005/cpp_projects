/**
 * @file banking_system.cpp
 * @brief A simple banking system application that allows users to create accounts, deposit, and withdraw money.
 *
 * This application provides a command-line interface for managing bank accounts. Users can create new accounts, deposit money, and withdraw money from their accounts. The account information is stored in a text file.
 *
 * @author Krishna Chauhan
 * @date 2024-10-29
 *
 * @details
 * The application uses file I/O to store and retrieve account information. It also uses threading to introduce delays for a better user experience. The main functionalities include:
 * - Creating a new account
 * - Depositing money into an account
 * - Withdrawing money from an account
 *
 * The account information is stored in the format: AccountNo : Password : Balance
 *
 * @note
 * This is a simple implementation and does not include advanced features like encryption for passwords or database storage.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
using namespace std;

class Account
{
private:
    string AccountNo, Password;
    int Balance;

public:
    Account() : AccountNo(""), Password(""), Balance(0) {}

    void setAccountNo(string id)
    {
        AccountNo = id;
    }

    void setPassword(string pw)
    {
        Password = pw;
    }

    void setBalance(int balance)
    {
        Balance = balance;
    }

    string getAccountNo() const
    {
        return AccountNo;
    }

    string getPassword() const
    {
        return Password;
    }

    int getBalance() const
    {
        return Balance;
    }
};

void openAccount(Account &user)
{
    system("cls");
    string id, pw;

    cout << "\tEnter Account No: ";
    cin >> id;
    user.setAccountNo(id);

    cout << "\tEnter A Strong Password: ";
    cin >> pw;
    user.setPassword(pw);

    user.setBalance(0);

    ofstream outfile("D:/Account.txt", ios::app);
    if (!outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        outfile << user.getAccountNo() << " : " << user.getPassword() << " : " << user.getBalance() << endl;
        cout << "\tAccount Created Successfully!" << endl;
    }
    outfile.close();
    this_thread::sleep_for(chrono::milliseconds(5000));
}

void addCash()
{
    system("cls");
    string id;
    cout << "\tEnter Account No: ";
    cin >> id;

    ifstream infile("D:/Account.txt");
    ofstream outfile("D:/Account_Temp.txt");
    if (!infile || !outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line))
    {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;
        if (id == userID)
        {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;

            int newBalance = userBalance + cash;
            outfile << userID << " : " << userPW << " : " << newBalance << endl;
            cout << "\tNew Balance Is: " << newBalance << endl;
        }
        else
        {
            outfile << line << endl;
        }
    }

    if (!found)
    {
        cout << "\tEnter Valid Account No!" << endl;
    }

    infile.close();
    outfile.close();
    remove("D:/Account.txt");
    rename("D:/Account_Temp.txt", "D:/Account.txt");
    this_thread::sleep_for(chrono::milliseconds(5000));
}

void withdraw()
{
    string id, pw;
    cout << "\tEnter Account No: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;
    ifstream infile("D:/Account.txt");
    ofstream outfile("D:/Account_Temp.txt");
    if (!infile || !outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line))
    {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;

        if (id == userID && pw == userPW)
        {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;

            if (cash <= userBalance)
            {
                int newBalance = userBalance - cash;
                outfile << userID << " : " << userPW << " : " << newBalance << endl;
                cout << "\tTransaction Was Successful!" << endl;
                cout << "\tRemaining Balance: " << newBalance << endl;
            }
            else
            {
                cout << "\tLow Balance!" << endl;
                outfile << line << endl;
            }
        }
        else
        {
            outfile << line << endl;
        }
    }

    if (!found)
    {
        cout << "\tInvalid Account No or Password!" << endl;
    }

    infile.close();
    outfile.close();
    remove("D:/Account.txt");
    rename("D:/Account_Temp.txt", "D:/Account.txt");
    this_thread::sleep_for(chrono::milliseconds(5000));
}

int main()
{
    Account user;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome To Bank Account Management System" << endl;
        cout << "\t*****************************************" << endl;
        cout << "\t1. Create New Account" << endl;
        cout << "\t2. Deposit Amount" << endl;
        cout << "\t3. Withdraw Amount" << endl;
        cout << "\t4. Exit" << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        switch (val)
        {
        case 1:
            openAccount(user);
            break;
        case 2:
            addCash();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            system("cls");
            exit = true;
            cout << "\tHave a good day!" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            break;
        default:
            cout << "\tInvalid Choice!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            break;
        }
    }

    return 0;
}
