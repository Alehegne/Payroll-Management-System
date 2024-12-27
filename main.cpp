
#include <iostream>
#include <string>  // for string manipulation
#include <cctype>  // for character manipulation
#include <cstdlib> //
#include <iomanip> // for formatting output

using namespace std;

// Function prototypes
void addEmployee();
void viewEmployee();
void searchEmployee();
void viewSummaryReport(int worker_count, char gender[], string employee_type[], double salary[]);
// global variables
int main()
{
    while (true)
    {
        // the initialization is just for testing purposes
        string names[100] = {"John", "Jane", "Doe", "Mary", "Peter", "Paul", "James", "Alice", "Bob", "Eve"};
        char gender[100] = {'m', 'f', 'm', 'f', 'm', 'f', 'm', 'f', 'm', 'f'};
        string employe_Type[100] = {"manager", "hourly_worker", "piece_worker", "commission_worker", "hourly_worker", "piece_worker", "commission_worker", "hourly_worker", "piece_worker", "commission_worker"};
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
            viewSummaryReport(worker_count, gender, employe_Type, salary);
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

void viewEmployee()
{

    cout << "View Employee" << endl;
}

void searchEmployee()
{
    cout << "Search Employee" << endl;
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

    cout << "******************************************************************************************" << endl;
    cout << "Summary Report" << endl;
    cout << "*******employee information**********" << endl;
    cout << "Total number of employees: " << worker_count << endl;
    cout << "male employees: " << gender_count[0] << endl;
    cout << "female employees: " << gender_count[1] << endl;
    cout << "Emplyee Types:" << "\n"
         << "Manager: " << employee_type_count[0] << "\n"
         << "Hourly Worker: " << employee_type_count[1] << "\n"
         << "Piece Worker: " << employee_type_count[2] << "\n"
         << "Commission Worker: " << employee_type_count[3] << endl;
    cout << "*********Summary Statistics***********" << endl;
    cout << "company capital: " << endl;
    cout << "Total salary paid: " << total_salary << endl;
    cout << "maximum salary: " << max_salary << endl;
    cout << "minimum salary: " << min_salary << endl;
    cout << "average salary: " << average_salary << endl;

    cout << "******************************************************************************************" << endl;
}