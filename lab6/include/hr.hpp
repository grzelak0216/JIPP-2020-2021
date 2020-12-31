#pragma one

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

bool sortSalary(const pair<int, double> x, const pair<int, double> y)
{
    return x.second > y.second;
}

class Employee
{
public:
    short int id;
    string name;
    string surname;
    string department;
    string position;

    void print(double salary)
    {
        cout << id << ": " << surname << " " << name << ": " << position << "- Salary: " << salary << endl;
    }
};

class HRMS
{
private:
    int employerId;
    map<int, Employee> mapEmplyees;
    map<string, vector<int>> mapDepartments;
    map<int, double> mapSalaries;

public:
    void add(Employee &worker, string department, double salary)
    {
        mapEmplyees[worker.id] = worker;
        mapSalaries[worker.id] = salary;

        worker.department = department;
        vector<int> &vect = mapDepartments[department];
        vect.push_back(worker.id);
    }

    void dismiss(int id)
    {
        string dep = mapEmplyees[id].department;

        mapEmplyees.erase(id);
        mapSalaries.erase(id);

        vector<int> &vect = mapDepartments[dep];
        for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
        {
            if (*it == id)
            {
                vect.erase(it);
                return;
            }
        }
    }

    void changeSalary(int employed, double newSalary)
    {
        mapSalaries[employed] = newSalary;
        // cout << newSalary << endl;
        // cout << mapSalaries[employed] << endl;
        cout << "\n *Salary changed* \n";
    }

    void printDepartment(string department)
    {
        vector<int> &vect = mapDepartments[department];
        cout << "Employees of department: " << department << endl;
        for (int id : vect)
        {
            mapEmplyees[id].print(mapSalaries[id]);
        }
    }

    void printEmployee(int id)
    {
        cout << id << ": " << mapEmplyees[id].surname << " " << mapEmplyees[id].name << endl
             << mapEmplyees[id].department << ": " << mapEmplyees[id].position << endl
             << " Salary: " << mapSalaries[id] << endl;
    }

    void printSalaries()
    {
        map<int, Employee>::iterator it;
        cout << "Salaries of workers: " << endl;
        for (it = mapEmplyees.begin(); it != mapEmplyees.end(); ++it)
        {
            it->second.print(mapSalaries[it->first]);
        }
    }

    void printSortedSalaries()
    {
        list<pair<int, double>> sortList;
        map<int, double>::iterator it;
        for (it = mapSalaries.begin(); it != mapSalaries.end(); ++it)
        {
            sortList.push_back(make_pair(it->first, it->second));
        }

        sortList.sort(sortSalary);

        list<pair<int, double>>::iterator it2;
        cout << "Sorted salaries of workers: " << endl;
        for (it2 = sortList.begin(); it2 != sortList.end(); ++it2)
        {
            mapEmplyees[it2->first].print(it2->second);
        }
    }

    void printPosition(string dep, string pos)
    {
        vector<int> &vect = mapDepartments[dep];
        cout << pos << " of department: " << dep << endl;
        for (int id : vect)
        {
            if (mapEmplyees[id].position == pos)
            {
                mapEmplyees[id].print(mapSalaries[id]);
            }
        }
    }
};