//Including necessary files
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <bits/stdc++.h>
#include "bank.h"
using namespace std;
float managerSalary;
float cashierSalary;

//Employee class
class Employee : public Bank
{

private:
    int EmpID;
    //char EmpName[50], Department[10];
    //vector<string> EmpName;
    vector<string> EmpName;
    vector<string> Department;
    vector<string> Post;

public:
    float Salary;

    list<int> li;
    //int managerSalary;
    //Function to set Salary of employee
    void setSalary(int sal)
    {
        Logger::Info("Setting Salary Of Employee");
        Salary = sal;
    }
    /*Virtual Function to get salary of Employee*/
    virtual int getSalary()
    {
        Logger::Info("Getting Salary Of Employee");
        cout << "Salary is: " << Salary;
        return Salary;
    }

    /*Function to Read data about Employee*/
    void ReadData()
    {
        Logger::Info("Writing data about Employee");
        string name;
        cout << "Employee ID: ";
        cin >> EmpID;
        cin.ignore();
        li.push_back(EmpID);
        cout << "Employee Name: ";
        cin >> name;
        EmpName.push_back(name);
        cin.ignore();
        int n = EmpName.size();
        cout << "Current Size is: " << n << "\n";
        cout << EmpName[n - 1] << "\n";
        string post;
        cout << "Employee's Post: ";
        cin >> post;
        Post.push_back(post);
        cin.ignore();

        if (post == "Manager")
        {
            cout << "Manager's Salary: ";
            cin >> managerSalary;
            cout << "Manager Salary input: " << managerSalary;
        }
        else if (post == "Cashier")
        {
            cout << "Cashier's Salary: ";
            cin >> cashierSalary;
            cout << "Cashier Salary input: " << cashierSalary;
        }
        else
        {
            cout << "Salary: ";
            cin >> Salary;
        }
        cin.ignore();
        string department;
        cout << "\nEmployee's Department:";
        cin >> department;
        Department.push_back(department);
        cin.ignore();
        /*
        cout << "Current Size is: " << EmpName.size() << "\n";
        cout << "Current Size is: " << Department.size() << "\n";
        cout << "Current Size is: " << Post.size() << "\n";*/
    }
    //Function to export data of employee
    void exportDataAsTxt()
    {
        Logger::Info("Exporting Data of Employee in txt format");
        ofstream MyFile("employeeData.txt", ios::out | ios::app);
        //MyFile << GetID();
        int n = EmpName.size() - 1;
        MyFile << "Employee ID: " << EmpID << "\nEmployee Name: " << EmpName[n] << "\nDepartment: " << Department[n] << "\nSalary: " << Salary << "\n";
        MyFile.close();
        for (int i = 0; i < EmpName.size(); i++)
        {
            cout << EmpName[i] << " " << Department[i] << " ";
        }
    }

    //Function to export data as csv
    void exportDataAsCSV()
    {
        Logger::Info("Exporting data in csv format");
        fstream fout;
        fout.open("employeedata.csv", ios::out | ios::app);
        int n = EmpName.size();
        int m = Department.size();
        //cout << "Size of EmpName vector is: " << n;
        //cout << EmpID << EmpName[n - 1] << Department[m - 1] << Salary << endl;
        fout << EmpID << "," << EmpName[n - 1] << "," << Post[n - 1] << "," << Department[m - 1] << "," << Salary << "\n";
        //
    }

    //Function to display employment details
    void getEmployeeDetails(int id)
    {
        fstream fin;
        fin.open("employeeData.csv", ios::in);
        int ID, sal;
        int count = 0;
        string name, department, word, line;
        vector<string> row;
        while (fin.good())
        {
            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }
            /*
            for (int i = 0; i > row.size(); i++)
            {
                cout << row[i] << endl;
            }*/
            // convert string to integer for comparision
            ID = stoi(row[0]);

            // Compare the with the present ID
            if (ID == id)
            {

                // Print the found data
                count = 1;
                cout << "Details of Employment ID: " << row[0] << " : \n";
                cout << "Name: " << row[1] << "\n";
                cout << "Post: " << row[2] << "\n";
                cout << "Department: " << row[3] << "\n";
                cout << "Salary: " << row[4] << "\n";
                break;
            }
        }

        if (count == 0)
            cout << "Record not found\n";
    }

    //Function to get Salary of Manager
    int getManagerSalary()
    {
        Logger::Info("Getting Salary Of Manager");
        return managerSalary;
    }
    //Function to get ID of Employee
    int GetID()
    {
        Logger::Info("Getting ID Of Employee");
        cout << "Employment ID: " << EmpID;
        return EmpID;
    }

    //Function to get Total number of Employees
    int getEmployeeCount()
    {
        return li.size();
    }
};

//Class Manager
class Manager : public Employee
{
public:
    //Overriden function to get salary of Manager
    int getSalary()
    {
        Logger::Info("Getting salary of Manager");
        cout << "Manager salary is: " << managerSalary;
        return managerSalary;
    }
};
//class Cashier
class Cashier : public Employee
{
public:
    //Overriden function to get salary of Cashier
    int getSalary()
    {
        Logger::Info("Getting salary of Cashier");
        cout << "Cashier salary is: " << cashierSalary;
        return cashierSalary;
    }
};
