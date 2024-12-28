
#include <iostream>
#include <string>  // for string manipulation
#include <cctype>  // for character manipulation
#include <cstdlib> //
#include <iomanip> // for formatting output
#include <limits>  // for numeric_limits
#include <cmath>   // for math functions
#include <algorithm>

using namespace std;

// Function prototypes
void addEmployee();
void viewEmployee(int worker_count, string names[], char gender[], string employee_type[], double salary[]);
void searchEmployee(int worker_count, char gender[], string employee_type[], double salary[], string names[], double hoursWorked[]);
void viewSummaryReport(int worker_count, char gender[], string employee_type[], double salary[]);

// Function to clear the input buffer
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Function to convert a string to lower case
string toLowerCase(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}
// global variables
int main()
{
    while (true)
    {
        // the initialization is just for testing purposes
        string names[100] = {"John", "Jane", "Doe", "jane", "Peter", "Paul", "James", "Alice", "Bob", "Eve"};
        char gender[100] = {'m', 'f', 'm', 'f', 'm', 'f', 'm', 'f', 'm', 'f'};
        string employee_type[100] = {"manager", "hourly_worker", "piece_worker", "commission_worker", "hourly_worker", "piece_worker", "commission_worker", "hourly_worker", "piece_worker", "commission_worker"};
        // manager working hours are not needed, is zero
        double hoursWorked[100] = {0, 40, 50, 60, 40, 50, 60, 40, 50, 60};
        double salary[100] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

        int worker_count = 10; // to keep track of the number of workers

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
            if (cin.fail())
            {
                clearInputBuffer();
                cout << "Invalid input. Please enter a number(1-5)." << endl;
            }
        } while (choice < 1 || choice > 5);

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            viewEmployee(worker_count, names, gender, employee_type, salary);
            break;
        case 3:
            searchEmployee(worker_count, gender, employee_type, salary, names, hoursWorked);
            break;
        case 4:
            viewSummaryReport(worker_count, gender, employee_type, salary);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

void addEmployee()
{
    // update the worker_count while adding a new worker

    cout << "Add Employee" << endl;
}

void viewEmployee(int worker_count, string names[], char gender[], string employee_type[], double salary[])
{

    cout << "View All Employee" << endl;
    cout << "******************************************************************************************" << endl;
    cout << left << setw(15) << "Name" << setw(10) << "Gender" << setw(20) << "Type" << setw(15) << "Weekly Pay (ETB)" << endl;
    for (int i = 0; i < worker_count; ++i)
    {
        cout << left << setw(15) << names[i] << setw(10) << gender[i] << setw(20) << employee_type[i] << setw(15) << fixed << setprecision(2) << salary[i] << endl;
    }
    cout << "******************************************************************************************" << endl;
}

void searchEmployee(int worker_count, char gender[], string employee_type[], double salary[], string names[], double hoursWorked[])
{
    if (worker_count == 0)
    {
        cout << "No employees to search." << endl;
    }
    else
    {
        while (true)
        {

            int searchOption;

            do
            {
                cout << "\nSearch Employee" << endl;
                cout << "Search by:" << endl;
                cout << "1. Name" << endl;
                cout << "2. Gender" << endl;
                cout << "3. Salary" << endl;
                cout << "4. Exit search" << endl;
                cout << "Enter your choice: ";
                cin >> searchOption;

                if (cin.fail())
                { // if the user enters a non-integer value
                    clearInputBuffer();
                    cout << "Invalid input. Please enter a number(1-3)." << endl;
                }

                if (searchOption < 1 || searchOption > 4)
                {
                    cout << "Invalid option! Please try again." << endl;
                }
            } while (searchOption < 1 || searchOption > 4);

            if (searchOption == 4)
            {
                break;
            }
            switch (searchOption)
            {
            case 1:
            { // Search by Name
                string search_name;
                cout << "Enter the name of the employee to search: ";
                cin >> search_name;

                bool found = false;
                bool tableHeader = false;
                for (int i = 0; i < worker_count; i++)
                {
                    if (toLowerCase(names[i]) == toLowerCase(search_name))
                    {
                        found = true;
                        // creating a table to display the employee information
                        if (!tableHeader)
                        {
                            cout << "\nEmployee found!" << endl;
                            cout << left << setw(20) << "Name" << setw(10) << "gender" << setw(20) << "Employee Type" << setw(10) << "Hours Worked" << setw(24) << "Salary(usd)" << endl;
                            tableHeader = true;
                        }
                        cout << left << setw(20) << names[i] << setw(10) << (gender[i] == 'f' ? "Female" : "Male") << setw(20) << employee_type[i] << setw(10) << hoursWorked[i] << setw(20) << salary[i] << endl;
                    }
                }
                if (!found)
                    cout << "No employee found with the name: " << search_name << endl;
                break;
            }
            case 2:
            {
                // Search by Gender
                char search_gender;
                cout << "Enter gender to search (M/F): ";
                cin >> search_gender;
                clearInputBuffer();

                search_gender = toupper(search_gender);

                bool found = false;
                bool header_table = false;
                for (int i = 0; i < worker_count; i++)
                {
                    if (toupper(gender[i]) == search_gender)
                    {
                        found = true;
                        // creating a table to display the employee information
                        if (!header_table)
                        {
                            cout << "\nEmployee found!" << endl;
                            cout << left << setw(20) << "Name" << setw(10) << "gender" << setw(20) << "Employee Type" << setw(20) << "Hours Worked" << setw(20) << "Salary(usd)" << endl;
                            header_table = true;
                        }
                        cout << left << setw(20) << names[i] << setw(10) << (gender[i] == 'F' || gender[i] == 'f' ? "Female" : "Male") << setw(20) << employee_type[i] << setw(20) << hoursWorked[i] << setw(20) << salary[i] << endl;
                    }
                }
                if (!found)
                {
                    cout << "No employees found with the gender: " << search_gender << endl;
                    break;
                }

                break;
            }
            case 3:
            {
                double search_salary;
                cout << "Enter the salary to search: ";
                cin >> search_salary;
                if (cin.fail())
                {
                    clearInputBuffer();
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }

                bool found = false;
                bool header_table = false;
                for (int i = 0; i < worker_count; i++)
                {
                    if (salary[i] == search_salary)
                    {
                        found = true;
                        // creating a table to display the employee information
                        if (!header_table)
                        {
                            cout << "\nEmployee found!" << endl;
                            cout << left << setw(20) << "Name" << setw(10) << "gender" << setw(20) << "Employee Type" << setw(20) << "Hours Worked" << setw(20) << "Salary(usd)" << endl;
                            header_table = true;
                        }
                        cout << left << setw(20) << names[i] << setw(10) << (gender[i] == 'F' || gender[i] == 'f' ? "Female" : "Male") << setw(20) << employee_type[i] << setw(20) << hoursWorked[i] << setw(20) << salary[i] << endl;
                    }
                }
                if (!found)
                    cout << "No employees found with the salary: " << search_salary << endl;
                break;
            }
            default:
                cout << "Invalid search option!" << endl;
                break;
            }
        }
    }
}

void viewSummaryReport(int worker_count, char gender[], string employee_type[], double salary[])
{
    int gender_count[2] = {0, 0};              // to keep track of the number, the first element is male and the second element is female
    int employee_type_count[4] = {0, 0, 0, 0}; // to keep track of the number of employees in each category,index 0 is manager, index 1 is hourly worker, index 2 is piece worker, index 3 is commission worker

    double total_salary = 0;
    double max_salary = salary[0];
    double min_salary = salary[0];
    for (int i = 0; i < worker_count; i++)
    {
        // calculate the total salary
        total_salary += salary[i];
        // calculate the maximum and minimum salary
        if (salary[i] > max_salary)
        {
            max_salary = salary[i];
        }
        if (salary[i] < min_salary)
        {
            min_salary = salary[i];
        }
        // change it to lower case
        gender[i] = tolower(gender[i]);
        // gender count
        if (gender[i] == 'm')
        {
            gender_count[0]++;
        }
        else if (gender[i] == 'f')
        {
            gender_count[1]++;
        }

        // check the employee type
        if (employee_type[i] == "manager")
        {
            employee_type_count[0]++;
        }
        else if (employee_type[i] == "hourly_worker")
        {
            employee_type_count[1]++;
        }
        else if (employee_type[i] == "piece_worker")
        {
            employee_type_count[2]++;
        }
        else if (employee_type[i] == "commission_worker")
        {
            employee_type_count[3]++;
        }
    }
    // calculate the average salary
    double average_salary = total_salary / worker_count;
    if (worker_count == 0)
    {
        cout << "No employees to generate a summary report." << endl;
    }
    else
    {
        // Report Layout
        // Header
        cout << "**********************************************************" << endl;
        cout << "                       Summary Report                     " << endl;
        cout << "**********************************************************" << endl;

        // Employee Information Table
        cout << "+--------------------------------------------------------+" << endl;
        cout << "|                 Employee Information                   |" << endl;
        cout << "+-------------------------------+------------------------+" << endl;
        cout << left << setw(32) << "| Total number of employees: " << right << setw(22) << worker_count << " |" << endl;
        cout << left << setw(32) << "| Male employees: " << right << setw(22) << gender_count[0] << " |" << endl;
        cout << left << setw(32) << "| Female employees: " << right << setw(22) << gender_count[1] << " |" << endl;
        cout << "+-------------------------------+------------------------+" << endl;

        // Employee Types Table
        cout << "+--------------------------------------------------------+" << endl;
        cout << "|                    Employee Types                      |" << endl;
        cout << "+-------------------------------+------------------------+" << endl;
        cout << left << setw(32) << "| Manager: " << right << setw(22) << employee_type_count[0] << " |" << endl;
        cout << left << setw(32) << "| Hourly Worker: " << right << setw(22) << employee_type_count[1] << " |" << endl;
        cout << left << setw(32) << "| Piece Worker: " << right << setw(22) << employee_type_count[2] << " |" << endl;
        cout << left << setw(32) << "| Commission Worker: " << right << setw(22) << employee_type_count[3] << " |" << endl;
        cout << "+-------------------------------+------------------------+" << endl;

        // Summary Statistics Table
        cout << "+--------------------------------------------------------+" << endl;
        cout << "|                    Summary Statistics                  |" << endl;
        cout << "+-------------------------------+------------------------+" << endl;
        cout << left << setw(32) << "| Total salary paid (USD): " << right << setw(22) << total_salary << " |" << endl;
        cout << left << setw(32) << "| Maximum salary (USD): " << right << setw(22) << max_salary << " |" << endl;
        cout << left << setw(32) << "| Minimum salary (USD): " << right << setw(22) << min_salary << " |" << endl;
        cout << left << setw(32) << "| Average salary (USD): " << right << setw(22) << average_salary << " |" << endl;
        cout << "+--------------------------------------------------------+" << endl;
    }
}
