#include <iostream>
using namespace std;

// Function prototypes
void addEmployee();
void viewEmployee();
void searchEmployee();
void viewSummaryReport();

int main()
{

    string names[100];
    char gender[100];
    string employe_Type[100];
    double hoursWorked[100];
    double salary[100];

    int worker_count = 0; // to keep track of the number of workers

    int choice;

    // Menu
    do
    {
        cout << endl;
        cout << "******************************************************************************************" << endl;
        cout << "Payroll Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2.view Employee" << endl;
        cout << "3.search Employee" << endl;
        cout << "4.view summary report" << endl;
        cout << "5.exit" << endl;
        cout << "******************************************************************************************" << endl;
        // User input
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 1 || choice > 5)
        {
            cout << "Invalid choice" << endl;
        }
    } while (choice < 1 || choice > 5);

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

void addEmployee()
{
    // update the worker_count while adding a new worker

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