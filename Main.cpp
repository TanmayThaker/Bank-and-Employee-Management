// Including necessary header files
#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include "employee.h"
#include "logger.h"
using namespace std;

// Function for displaying Employee Menu
void employeeMenu()
{
    Manager mg;
    Employee emp;
    Employee *emp1;
    Cashier cash;
    while (true)
    {
        // system("cls");
        int choice;
        cout << "\n\n Enter Your Choice";
        cout << "\n\n Employee Detailer";
        cout << "\n 1. Enter new record about Employee";
        cout << "\n 2. Set Employee's Salary";
        cout << "\n 3. Get Employee's Salary";
        cout << "\n 4. Get Employment ID";
        cout << "\n 5. Get Employee Count ";
        cout << "\n 6. Get Employment Details";
        cout << "\n 7. Export Data";
        cout << "\n 8. Get Manager's Salary";
        cout << "\n 9. Export Data in Text Format";
        cout << "\n 10. Get Cashier's Salary";
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            emp.ReadData();
            break;
        case 2:
            cout << "Enter the salary of Employee: ";
            int n;
            cin >> n;
            emp.setSalary(n);
            break;
        case 3:
            emp.getSalary();
            break;
        case 4:
            emp.GetID();
            break;
        case 5:
            cout << "Total number of employees are: " << emp.getEmployeeCount();
            break;
        case 6:
            int id;
            cout << "Welcome to Employee Search\n";
            cout << "Please enter employment ID: ";
            cin >> id;
            emp.getEmployeeDetails(id);
            break;
        case 7:
            emp.exportDataAsCSV();
            break;
        case 8:
            emp1 = &mg;
            emp1->getSalary();
            // mg.getSalary();
            break;

        case 9:
            emp.exportDataAsTxt();
            break;
        case 10:
            emp1 = &cash;
            emp1->getSalary();
            break;
        default:
            cout << "\n\n Invalid Value...Please Try Again";
        }
    }
}
// Function for displaying Loan Menu
void loanMenu()
{
    Logger::Info("Getting Loan Menu");
    Loan l;
    // rerun:
    system("cls");
rerun:
    int choice;
    cout << "\n\n Enter Your Choice";
    cout << "\n\n\t\t LOAN APPLICATIONS";
    cout << "\n 1. Get Loan";
    cout << "\n 2. Get Loan Applications Details";
    cout << "\n 3. Exit";
    cout << "\n Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        l.loanf();
        break;
    case 2:
        l.output();

        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "\n\n Invalid Value...Please Try Again";
    }
    getch();
    goto rerun;
}
// Function to show Bank menu
void bankMenu()
{
    Logger::Info("Bank Menu Called");
    system("cls");
    Bank bank;
    while (true)
    {
        int choice;
        cout << "\n\n\t\t ATM Management";
        cout << "\n\n 1. Create an account";
        cout << "\n 2. Withdraw Amount";
        cout << "\n 3. Deposit Amount";
        cout << "\n 4. Show Balance";
        cout << "\n 5. Show Bank Data";
        cout << "\n 6. Loan Applications";
        cout << "\n 7. Export Data as CSV";
        cout << "\n 8. Get Account Details";
        cout << "\n 9. Exit";
        cout << "\n\n Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.getData();
            break;
        case 2:
            bank.withdrawMoney();
            break;
        case 3:
            bank.deposit();
            break;
        case 4:
            bank.showBalance();
            break;
        case 5:
            bank.showBankData();
            break;
        case 6:
            loanMenu();
            break;
        case 7:
            bank.exportDataAsCSV();
            break;
        case 8:
            int an;
            cout << "Please enter your account number: ";
            cin >> an;
            bank.getBankDetails(an);
            break;
        case 9:
            exit(1);
            break;
        default:
            cout << "\n\n Invalid Value...Please Try Again";
        }
    }

    // getch();
}
// Main Function
int main()
{
    // Logger::EnableFileOutput("logs.txt");
    cout << "Welcome to Bank ";
    int choice;
    cout << "\n1. Bank Management";
    cout << "\n2. Employee Management";
    cout << "\n3. Loan Management";
    cout << "\n4. Exit";
    cout << "\nPlease Enter your choice: ";
    cin >> choice;
    // Loan loan;
    thread t1; // Creating a thread 1
    thread t2; // Creating a thread 2
    thread t3; // Creating a thread 3
    switch (choice)
    {
    case 1:
        t3 = thread(bankMenu);
        t3.join();
        break;
    case 2:
        t1 = thread(employeeMenu);
        t1.join();
        break;
    case 3:
        t2 = thread(loanMenu);
        t2.join();
        break;
    case 4:
        exit(1);
        break;
    }
    return 0;
}
