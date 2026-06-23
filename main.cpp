#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For formatting the salary output

class Employee {
private:
    int employeeID;
    std::string name;
    std::string gender;
    int age;
    std::string currentPosition;
    double lastMonthSalary;

public:
    // Constructor to initialize employee data
    Employee(int id, const std::string& n, const std::string& g, int a,
             const std::string& position, double salary)
        : employeeID(id), name(n), gender(g), age(a),
          currentPosition(position), lastMonthSalary(salary) {}

    // Getter functions
    int getEmployeeID() const { return employeeID; }
    const std::string& getName() const { return name; }
    const std::string& getGender() const { return gender; }
    int getAge() const { return age; }
    const std::string& getCurrentPosition() const { return currentPosition; }
    double getLastMonthSalary() const { return lastMonthSalary; }

    // Setter functions
    void setName(const std::string& newName) { name = newName; }
    void setGender(const std::string& newGender) { gender = newGender; }
    void setAge(int newAge) { age = newAge; }
    void setPosition(const std::string& newPosition) { currentPosition = newPosition; }
    void setSalary(double newSalary) { lastMonthSalary = newSalary; }

    // Function to display employee details
    void displayEmployeeDetails() const {
        std::cout << "Employee ID: " << employeeID << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Gender: " << gender << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Position: " << currentPosition << "\n";
        std::cout << "Last Month's Salary: $" << std::fixed
                  << std::setprecision(2) << lastMonthSalary << "\n";
    }
};

// Function to display employee details by ID
void displayEmployeeByID(const std::vector<Employee>& employees, int id) {
    bool found = false;

    for (const auto& employee : employees) {
        if (employee.getEmployeeID() == id) {
            employee.displayEmployeeDetails();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Employee with ID " << id << " not found.\n";
    }
}

// Function to add employee
void addEmployee(std::vector<Employee>& employees, int& nextID) {
    std::string name, gender, position;
    int age;
    double salary;

    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter Gender (Male/Female): ";
    std::getline(std::cin, gender);

    std::cout << "Enter Age: ";
    std::cin >> age;

    std::cout << "Enter Position: ";
    std::cin.ignore();
    std::getline(std::cin, position);

    std::cout << "Enter Last Month's Salary: $";
    std::cin >> salary;

    employees.push_back(Employee(nextID++, name, gender, age, position, salary));

    std::cout << "Employee added successfully!\n";
}

// Function to modify employee
void modifyEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter Employee ID to modify: ";
    std::cin >> id;

    bool found = false;

    for (auto& employee : employees) {
        if (employee.getEmployeeID() == id) {
            found = true;

            std::string name, gender, position;
            int age;
            double salary;

            std::cout << "Enter new Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            employee.setName(name);

            std::cout << "Enter new Gender (Male/Female): ";
            std::getline(std::cin, gender);
            employee.setGender(gender);

            std::cout << "Enter new Age: ";
            std::cin >> age;
            employee.setAge(age);

            std::cout << "Enter new Position: ";
            std::cin.ignore();
            std::getline(std::cin, position);
            employee.setPosition(position);

            std::cout << "Enter new Salary: $";
            std::cin >> salary;
            employee.setSalary(salary);

            std::cout << "Employee details updated successfully!\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Employee with ID " << id << " not found.\n";
    }
}

// Function to delete employee
void deleteEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter Employee ID to delete: ";
    std::cin >> id;

    auto it = employees.begin();

    while (it != employees.end()) {
        if (it->getEmployeeID() == id) {
            it = employees.erase(it);
            std::cout << "Employee deleted successfully.\n";
            return;
        } else {
            ++it;
        }
    }

    std::cout << "Employee with ID " << id << " not found.\n";
}

int main() {
    std::vector<Employee> employees;
    int nextID = 1;

    // Sample initial employees
    employees.push_back(Employee(nextID++, "John Doe", "Male", 30, "Software Engineer", 5000.0));
    employees.push_back(Employee(nextID++, "Jane Smith", "Female", 28, "Product Manager", 6500.0));

    int choice;

    do {
        std::cout << "\n*** Employee Billing System Menu ***\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Modify Employee\n";
        std::cout << "3. Delete Employee\n";
        std::cout << "4. Display Employee by ID\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(employees, nextID);
                break;

            case 2:
                modifyEmployee(employees);
                break;

            case 3:
                deleteEmployee(employees);
                break;

            case 4: {
                int id;
                std::cout << "Enter Employee ID to search: ";
                std::cin >> id;
                displayEmployeeByID(employees, id);
                break;
            }

            case 5:
                std::cout << "Exiting Employee Billing System.\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}