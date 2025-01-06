**Payroll Management System**


A collaborative C++ project to develop a comprehensive Payroll Management System
that calculates weekly pay for employees based on their employment type, generates
detailed reports,update ,delete, and provides a search feature for specific records.


**Overall Structure**

The main.cpp file forms the core of the Payroll Management System. It is modularly designed with functions handling different functionalities and a well-organized structure to manage employee data. The code begins with global constants and variables to define the maximum number of employees and store their data. Key function prototypes and utility functions, such as clearing input buffers and converting strings to lowercase, ensure smooth operation.
The main program includes a menu-driven interface that allows users to interact with various features such as adding, viewing, searching, updating, deleting employees, and generating summary reports.

**Main Functionalities**
Add Employee:
Adds a new employee's details, including name, gender, ID, employment type, and salary. Input validation ensures accurate data entry and prevents duplicate IDs.

View Employee:
Displays all employee records in a formatted tabular layout, including name, ID, gender, type, and salary.

Search Employee:
Allows users to search for employees by name, gender, or salary. It provides results in a structured format for clarity.

Update Employee:
Updates an existing employee's details, including their ID, name, gender, employment type, or salary. It validates new entries for accuracy and consistency.

Delete Employee:
Deletes an employee record after confirmation, adjusting the data arrays to maintain integrity.

Summary Report:
Generates a report summarizing the number of employees by gender and type, total salaries paid, and statistics like maximum, minimum, and average salaries.

**Key Global Variables and Constants**
**Constants:**
max_employees defines the maximum number of employees (100).
Global Variables:
onames[], gender[], employee_type[]: Arrays to store employee details.
ohoursWorked[], salary[]: Arrays to track hours worked and salaries.
oworker_count: Tracks the current number of employees.
oworker_id[]: Stores unique IDs for each employee.
This structured approach ensures scalability, ease of maintenance, and efficient handling of employee data.


**Contributions**

This project is a team effort developed by:

Contributor 1: Ahlam Ahmed(ETS 0115/16) role- implementting the search functionality

Contributor 2: Alehegne Geta(ETS 0130/16) role-implementing the summary report functionality

Contributor 3: Amanawit Behailu(ETS 0135/16) role-implementing the delete employee functionality

Contributor 4: Amanuel Ayele(ETS 0140/16) role-implementing the update employee functionality

contributor 5:Amanuel Getachewu(ETS 0147/16) role-implementing the view employees functionality

contributor 6:Amanuel Habtamu(ETS 0148/16) role-implementing the add employee functionality
