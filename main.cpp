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
void addEmployee(int &worker_count, string names[], char gender[], string employee_type[], double salary[], double hoursWorked[]);
void viewEmployee(int worker_count, string names[], char gender[], string employee_type[], double salary[]);
void searchEmployee(int worker_count, char gender[], string employee_type[], double salary[], string names[], double hoursWorked[]);
void viewSummaryReport(int worker_count, char gender[], string employee_type[], double salary[]);

// global variables
int main()
{
    // the initialization is just for testing purposes
    string names[max_employees] = {"John", "Jane", "Doe", "Mary", "Peter", "Paul", "James", "Alice", "Bob", "Eve"};
    char gender[max_employees] = {'m', 'f', 'm', 'f', 'm', 'f', 'm', 'f', 'm', 'f'};
    string employee_type[max_employees] = {"manager", "hourly_worker", "piece_worker", "commission_worker", "hourly_worker", "piece_worker", "commission_worker", "hourly_worker", "piece_worker", "commission_worker"};
    double hoursWorked[max_employees] = {0, 40, 50, 60, 40, 50, 60, 40, 50, 60};
    double salary[max_employees] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

    int worker_count = 10; // to keep track of the number of workers

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
            cout << "5. Exit" << endl;
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
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number(1-5)." << endl;
            }
        } while (choice < 1 || choice > 5);

        switch (choice)
        {
        case 1:
            addEmployee(worker_count, names, gender, employee_type, salary, hoursWorked);
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
            cout << "Exiting the program. Goodbye!" << endl;
            return 0; // Exit the program
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

void addEmployee(int &worker_count, string names[], char gender[], string employee_type[], 
                 double salary[], double hoursWorked[]) {
    if (worker_count >= max_employees) {
        cout << "Maximum employee capacity reached. Cannot add more employees.\n";
        return;
    }

    cout << "\nAdd Employee Record\n";

    while (true) {
        // Declare variables for new employee details
        string name;
        char emp_gender;
        int type;
        double emp_hoursWorked = 0, emp_salary = 0;

        // Get employee name
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "Enter Employee Name (or 0 to stop): ";
        getline(cin, name);

        if (name == "0") break; // Exit input loop

        // Get employee gender
        while (true) {
            cout << "Enter Gender (M/F): ";
            cin >> emp_gender;
            emp_gender = toupper(emp_gender);

            if (emp_gender == 'M' || emp_gender == 'F') break;
            cout << "Invalid input. Please enter 'M' or 'F'.\n";
        }

        // Get employment type
        while (true) {
            cout << "Enter Employment Type (1: Manager, 2: Hourly Worker, 3: Commission Worker, 4: Pieceworker): ";
            cin >> type;

            if (cin.fail() || type < 1 || type > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 4.\n";
            } else {
                break;
            }
        }

        // Collect details based on employment type
        switch (type) {
        case 1: // Manager
            emp_hoursWorked = 0;
            emp_salary = 3000; // Fixed weekly salary
            employee_type[worker_count] = "Manager";
            break;

        case 2: // Hourly Worker
            double hourlyWage;
            while (true) {
                cout << "Enter Hourly Wage: ";
                cin >> hourlyWage;

                if (cin.fail() || hourlyWage < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a positive number.\n";
                } else {
                    break;
                }
            }

            while (true) {
                cout << "Enter Hours Worked: ";
                cin >> emp_hoursWorked;

                if (cin.fail() || emp_hoursWorked < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a positive number.\n";
                } else {
                    break;
                }
            }

            emp_salary = (emp_hoursWorked <= 40) 
                        ? (hourlyWage * emp_hoursWorked)
                        : (hourlyWage * 40 + hourlyWage * 1.5 * (emp_hoursWorked - 40));
            employee_type[worker_count] = "Hourly Worker";
            break;

        case 3: // Commission Worker
            double weeklySales;
            while (true) {
                cout << "Enter Weekly Sales: ";
                cin >> weeklySales;

                if (cin.fail() || weeklySales < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a positive number.\n";
                } else {
                    break;
                }
            }

            emp_salary = 250 + weeklySales * 0.057;
            emp_hoursWorked = 0;
            employee_type[worker_count] = "Commission Worker";
            break;

        case 4: // Pieceworker
            double pieceRate;
            while (true) {
                cout << "Enter Number of Items Produced: ";
                cin >> emp_hoursWorked;

                if (cin.fail() || emp_hoursWorked < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a positive number.\n";
                } else {
                    break;
                }
            }

            while (true) {
                cout << "Enter Fixed Amount Per Item: ";
                cin >> pieceRate;

                if (cin.fail() || pieceRate < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a positive number.\n";
                } else {
                    break;
                }
            }

            emp_salary = emp_hoursWorked * pieceRate;
            employee_type[worker_count] = "Pieceworker";
            break;

        default:
            cout << "Invalid employment type.\n";
            continue;
        }

        // Assign details to the arrays
        names[worker_count] = name;
        gender[worker_count] = emp_gender;
        salary[worker_count] = emp_salary;
        hoursWorked[worker_count] = emp_hoursWorked;

        worker_count++;
        cout << "Employee record added successfully!\n";
    }
}


void viewEmployee(int worker_count, string names[], char gender[], string employee_type[], double salary[])
{
    if (worker_count == 0) {
        cout << "No employees to display." << endl;
        return;
    }

    cout << "View All Employee" << endl;
    cout << "******************************************************************************************" << endl;
    cout << left << setw(15) << "Name" << setw(10) << "Gender" << setw(20) << "Type" << setw(15) << "Weekly Pay (ETB)" << endl;
    for(int i = 0; i < worker_count; ++i) 
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
    int searchOption;
    do { 
        cout << "\nSearch Employee" << endl;
        cout << "Search by:" << endl;
        cout << "1. Name" << endl;
        cout << "2. Gender" << endl;
        cout << "3. Salary" << endl;
        cout << "Enter your choice: ";
        cin >> searchOption;

        if (searchOption < 1 || searchOption > 3) {
            cout << "Invalid option! Please try again." << endl;
        }
    } while (searchOption < 1 || searchOption > 3);

    switch (searchOption) {
        case 1: { // Search by Name
            string search_name;
            cout << "Enter the name of the employee to search: ";
            cin >> search_name;

            bool found = false;
            for (int i = 0; i < worker_count; i++) {
                if (names[i] == search_name) {
                    found = true;
                    cout << "\nEmployee found!" << endl;
                    cout << "Name: " << names[i] << endl;
                    cout << "Gender: " << gender[i] << endl;
                    cout << "Employee Type: " << employee_type[i] << endl;
                    cout << "Hours Worked: " << hoursWorked[i] << endl;
                    cout << "Salary: " << salary[i] << endl;
                    break;
                }
            }
            if (!found)
                cout << "No employee found with the name: " << search_name << endl;
            break;
        }
        case 2: { // Search by Gender
            char search_gender;
            cout << "Enter gender to search (M/F): ";
            cin >> search_gender;
             // to convert user input to lowecase to ensure case insensitivity
            search_gender = tolower(search_gender);

            bool found = false;
            for (int i = 0; i < worker_count; i++) {
                if (tolower(gender[i]) == search_gender) {
                    found = true;
                    cout << "\nEmployee found!" << endl;
                    cout << "Name: " << names[i] << endl;
                    cout << "Gender: " << gender[i] << endl;
                    cout << "Employee Type: " << employee_type[i] << endl;
                    cout << "Hours Worked: " << hoursWorked[i] << endl;
                    cout << "Salary: " << salary[i] << endl;
                }
            }
            if (!found)
                cout << "No employees found with the gender: " << search_gender << endl;
            break;
        }
        case 3: { // Search by Salary
            double search_salary;
            cout << "Enter the salary to search: ";
            cin >> search_salary;

            bool found = false;
            for (int i = 0; i < worker_count; i++) {
                if (salary[i] == search_salary) {
                    found = true;
                    cout << "\nEmployee found!" << endl;
                    cout << "Name: " << names[i] << endl;
                    cout << "Gender: " << gender[i] << endl;
                    cout << "Employee Type: " << employee_type[i] << endl;
                    cout << "Hours Worked: " << hoursWorked[i] << endl;
                    cout << "Salary: " << salary[i] << endl;
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

    cout << "******************************************************************************************" << endl;
    cout << "Summary Report" << endl;
    cout << "*******Employee Information**********" << endl;
    cout << "Total number of employees: " << worker_count << endl;
    cout << "Male employees: " << gender_count[0] << endl;
    cout << "Female employees: " << gender_count[1] << endl;
    cout << "Employee Types:" << "\n"
         << "Manager: " << employee_type_count[0] << "\n"
         << "Hourly Worker: " << employee_type_count[1] << "\n"
         << "Piece Worker: " << employee_type_count[2] << "\n"
         << "Commission Worker: " << employee_type_count[3] << endl;
    cout << "*********Summary Statistics***********" << endl;
    cout << "Company capital: " << endl;
    cout << "Total salary paid: " << total_salary << endl;
    cout << "Maximum salary: " << max_salary << endl;
    cout << "Minimum salary: " << min_salary << endl;
    cout << "Average salary: " << average_salary << endl;

    cout << "******************************************************************************************" << endl;
}
