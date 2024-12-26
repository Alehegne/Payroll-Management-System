#include <iostream>
using namespace std;

void addEmployee()
{
    cout << "Add Employee" << endl;
}

void viewEmployee()
{
    cout << "View Employee" << endl;
}

void searchEmployee()
{
    cout << "Search Employee" << endl;
}
void viewSummaryReport()
{
    cout << "View Summary Report" << endl;
}

int main()
{

    string names[100];
    char gender[100];
    string employeType[100];

    cout << "Payroll Management System" << endl;

    cout << "1. Add Employee" << endl;
    cout << "2.view Employee" << endl;
    cout << "3.search Employee" << endl;
    cout << "4.view summary report" << endl;
    cout << "5.exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        addEmployee();
        break;
    case 2:
        viewEmployee();
        break;
    case 3:
        searchEmployee();
        break;
    case 4:
        viewSummaryReport();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}