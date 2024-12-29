#include <iostream>
#include <string>  // for string manipulation
#include <cctype>  // for character manipulation
#include <cstdlib> //
#include <iomanip> // for formatting output
#include <limits>  // for numeric_limits

using namespace std;

// To define the maximum number of employees
const int max_employees = 100;

// Function prototypes
void addEmployee();
void viewEmployee();
void searchEmployee();
void viewSummaryReport();
void updateEmployee();
void deleteEmployee();

// Function to clear the input buffer
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Function to convert a string to lower case
std::string toLowerCase(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}

// global variables
string names[100];
char gender[100];
string employee_type[100];
// manager working hours are not needed, is zero
double hoursWorked[100];
double salary[100];
int worker_count = 0; // to keep track of the number of workers
int worker_id[100];

int main()
{
    while (true)
    {
        // the initialization is just for testing purposes

        int choice;
        while (true)
        {
            // Menu
            do
            {
                cout << endl;
                cout << "******************************************************************************************" << endl;
                cout << "Payroll Management System" << endl;
                cout << "1. Add Employee" << endl;
                cout << "2. View Employee" << endl;
                cout << "3. Search Employee" << endl;
                cout << "4. View summary report" << endl;
                cout << "5.update Employee details" << endl;
                cout << "6.delete Employee record" << endl;
                cout << "7. Exit" << endl;
                cout << "******************************************************************************************" << endl;
                // User input
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice < 1 || choice > 7)
                {
                    cout << "Invalid choice" << endl;
                }
                if (cin.fail())
                {
                    clearInputBuffer();
                    cout << "Invalid input. Please enter a number(1-5)." << endl;
                }
            } while (choice < 1 || choice > 7);

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
                updateEmployee();
                break;
            case 6:
                deleteEmployee();
                break;
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0; // Exit the program
            default:
                cout << "Invalid choice" << endl;
            }
        }
    }
}
void addEmployee()
{
    if (worker_count >= max_employees)
    {
        cout << "Maximum employee capacity reached. Cannot add more employees.\n";
        return;
    }

    cout << "\nAdd Employee Record\n";

    while (true)
    {
        string name;
        char emp_gender;
        int type;
        double emp_hoursWorked = 0, emp_salary = 0;

        // Get employee name
        do
        {
            cout << "Enter Employee Name (or 0 to stop): ";
            clearInputBuffer();
            getline(cin, name);
            if (name == "0")
                return;
            if (name.empty())
            {
                cout << "Name cannot be empty. Please enter a name. \n";
            }
        } while (name.empty());

        // enter id
        bool isIdTaken = false;
        do
        {
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;
            if (cin.fail())
            {
                cout << "Invalid ID. Please enter a number.\n";
                clearInputBuffer();
                continue;
            }
            // check if the id is already taken
            if (worker_count == 0)
            {
                worker_id[worker_count] = id;
            }
            else
            {
                for (int i = 0; i < worker_count; i++)
                {
                    if (id == worker_id[i])
                    {
                        cout << "ID already taken. Please enter a different ID.\n";
                        isIdTaken = true;
                        break;
                    }
                    else
                    {
                        worker_id[worker_count] = id;
                        isIdTaken = false;
                    }
                }
            }
        } while (isIdTaken);

        // Get employee gender
        do
        {
            cout << "Enter Gender (M/F): ";
            cin >> emp_gender;
            clearInputBuffer();
            emp_gender = toupper(emp_gender);
            if (emp_gender != 'M' && emp_gender != 'F')
            {
                cout << "Invalid gender. Please enter 'M' or 'F'.\n";
            }
        } while (emp_gender != 'M' && emp_gender != 'F');

        // Get employment type
        do
        {
            cout << "Enter Employment Type (1: Manager, 2: Hourly Worker, 3: Commission Worker, 4: Pieceworker): ";
            cin >> type;
            if (cin.fail())
            {
                clearInputBuffer();
                cout << "enter a correct employment type." << endl;
            }
        } while (type < 1 || type > 4);

        // Process based on type
        switch (type)
        {
        case 1: // Manager
            emp_hoursWorked = 0;
            salary[worker_count] = 3000; // Fixed weekly salary
            employee_type[worker_count] = "Manager";
            break;

        case 2: // Hourly Worker
        {
            double hourlyWage = 0;
            do
            {
                cout << "Enter Hourly Wage: ";
                cin >> hourlyWage;
                if (cin.fail())
                {
                    cout << "enter a valid hourly wage";
                    clearInputBuffer();
                }
            } while (hourlyWage < 0);

            do
            {
                cout << "Enter Hours Worked: ";
                cin >> emp_hoursWorked;
                if (emp_hoursWorked < 0 || cin.fail())
                {
                    cout << "Invalid hours worked. Please enter a positive number.\n";
                }
            } while (emp_hoursWorked < 0);

            salary[worker_count] = (emp_hoursWorked <= 40) ? (hourlyWage * emp_hoursWorked) : (hourlyWage * 40 + hourlyWage * 1.5 * (emp_hoursWorked - 40));
            employee_type[worker_count] = "Hourly Worker";
            break;
        }
        case 3: // Commission Worker
            double weeklySales;
            do
            {
                cout << "Enter Weekly Sales: ";
                cin >> weeklySales;
                if (cin.fail() || weeklySales < 0)
                {
                    cout << "enter a valid weekly sales";
                    clearInputBuffer();
                }
            } while (weeklySales < 0);

            salary[worker_count] = 250 + weeklySales * 0.057;
            employee_type[worker_count] = "Commission Worker";
            break;

        case 4: // Pieceworker
        {
            double pieceRate;
            double noOfItems;

            do
            {

                cout << "Enter Number of Items Produced: ";
                cin >> noOfItems; // Items produced
                if (noOfItems < 0 || cin.fail())
                {
                    cout << "Invalid number of items. Please enter a positive number.\n";
                    clearInputBuffer();
                }

                cout << "Enter Fixed Amount Per Item: ";
                cin >> pieceRate;
                if (pieceRate < 0 || cin.fail())
                {
                    cout << "Invalid amount. Please enter a positive number.\n";
                    clearInputBuffer();
                }
            } while (emp_hoursWorked < 0 || pieceRate < 0);

            salary[worker_count] = noOfItems * pieceRate;
            employee_type[worker_count] = "Pieceworker";
            break;
        }
        default:
            cout << "Invalid employment type.\n";
            continue;
        }

        // Assign details to the arrays
        names[worker_count] = name;
        gender[worker_count] = emp_gender;
        hoursWorked[worker_count] = emp_hoursWorked;

        worker_count++;
        cout << "Employee record added successfully!\n";
    }
}

void viewEmployee()
{
    if (worker_count == 0)
    {
        cout << "No employees to display." << endl;
        return;
    }

    cout << "View All Employee" << endl;
    cout << "******************************************************************************************" << endl;
    cout << left << setw(15) << "Name" << setw(10) << "Id" << setw(10) << "Gender" << setw(20) << "Type" << setw(15) << "Weekly Pay (ETB)" << endl;
    for (int i = 0; i < worker_count; ++i)
    {
        cout << left << setw(15) << names[i] << setw(10) << worker_id[i] << setw(10) << gender[i] << setw(20) << employee_type[i] << setw(15) << fixed << setprecision(2) << salary[i] << endl;
    }
    cout << "******************************************************************************************" << endl;
}

void searchEmployee()
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

void updateEmployee()
{
}
void deleteEmployee()
{
}
void viewSummaryReport()
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
        if (employee_type[i] == "Manager")
        {
            employee_type_count[0]++;
        }
        else if (employee_type[i] == "Hourly Worker")
        {
            employee_type_count[1]++;
        }
        else if (employee_type[i] == "Piece Worker")
        {
            employee_type_count[2]++;
        }
        else if (employee_type[i] == "Commission Worker")
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
