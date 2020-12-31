#include <iostream>
#include <map>

#include "../include/hr.hpp"

using namespace std;

int main()
{
    HRMS Hr;
    Employee person;

    //id - xyz(x=Departament, yz=Number of employee)
    //name - name of employee
    //surname - surname of employee
    //position - position of employee

    person.id = 1001;
    person.name = "Janusz";
    person.surname = "Benz";
    person.position = "Owner";
    Hr.add(person, "Management", 54025.22);

    person.id = 1002;
    person.name = "Grazyna";
    person.surname = "Benz";
    person.position = "Owner";
    Hr.add(person, "Management", 53757.02);

    person.id = 1003;
    person.name = "Jezy";
    person.surname = "Owsiak";
    person.position = "Manager";
    Hr.add(person, "Management", 15005.02);

    person.id = 2001;
    person.name = "Jan";
    person.surname = "Kowalski";
    person.position = "Manager";
    Hr.add(person, "Innowation", 14068.92);

    person.id = 3001;
    person.name = "Stanisław";
    person.surname = "Buczek";
    person.position = "Manager";
    Hr.add(person, "Testers", 16000.00);

    person.id = 1004;
    person.name = "Marcin";
    person.surname = "Kilar";
    person.position = "Programmer";
    Hr.add(person, "Management", 7512.99);

    person.id = 2002;
    person.name = "Tomasz";
    person.surname = "Kowalczyk";
    person.position = "Lead developer";
    Hr.add(person, "Innowation", 10054.99);

    person.id = 2003;
    person.name = "Zbigniew";
    person.surname = "Nowak";
    person.position = "Programmer";
    Hr.add(person, "Innowation", 7200.99);

    person.id = 3003;
    person.name = "Aleksandra";
    person.surname = "Szewczyk";
    person.position = "Programmer";
    Hr.add(person, "Testers", 8092.99);

    person.id = 3002;
    person.name = "Zenon";
    person.surname = "Martyniuk";
    person.position = "Lead developer";
    Hr.add(person, "Testers", 11482.99);

    Hr.printDepartment("Management");
    cout << endl;
    Hr.printDepartment("Innowation");
    cout << endl;
    Hr.printDepartment("Testers");
    cout << endl;

    Hr.printSalaries();
    cout << endl;

    Hr.printSortedSalaries();
    cout << endl;

    Hr.printEmployee(3002);
    cout << endl;
    Hr.changeSalary(3002, 11900.99);
    cout << endl;
    Hr.printEmployee(3002);

    cout << endl
         << endl;

    Hr.printPosition("Testers", "Programmer");

    cout << endl;

    return 0;
}