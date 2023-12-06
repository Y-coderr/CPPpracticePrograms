#include <iostream> 
#include <string> 
#include <stdexcept> 
using namespace std; 

class EmployeeDetails { 
protected: 
   string name; 
   int age; 
   double salary; 
public: 
   virtual void inputDetails() { 
   cout << "Enter employee name: "; 
   cin >> name; 
   cout << "Enter employee age: "; 
   cin >> age; 
   cout << "Enter employee salary: "; 
   cin >> salary; 
} 
virtual void displayDetails() const { 
   cout << "\nEmployee Name: " << name << endl; 
   cout << "Employee Age: " << age << endl; 
   cout << "Employee Salary: " << salary << endl; 
} 
virtual ~EmployeeDetails() {} 
}; 
class EmployeeDetailsWithExceptionHandling : public EmployeeDetails { 
friend void checkSalary(const EmployeeDetailsWithExceptionHandling &emp); 
public: 
   void inputDetails() override { 
   cout << "Enter employee name: "; 
   cin >> name; 
   cout << "Enter employee age: "; 
   cin >> age; 
   while (true) { 
try { 
   cout << "Enter employee salary: "; 
   cin >> salary; 
   checkSalary(*this); 
   break;  
} catch (const exception &e) { 
  cerr << "Exception: " << e.what() << endl; 
} 
} 
} 
}; 
void checkSalary(const EmployeeDetailsWithExceptionHandling &emp) { 
if (emp.salary <= 0) { 
   throw invalid_argument("Salary must be a positive number!"); 
} 
} 
int main() { 
   EmployeeDetailsWithExceptionHandling employees[5]; 
   cout << "Enter details for 5 employees:\n"; 
   for (int i = 0; i < 5; ++i) { 
   cout << "\nEnter details for Employee " << (i + 1) << ":" << endl; 
   employees[i].inputDetails(); 
} 
   cout << "\nEmployee Details:\n"; 
   for (int i = 0; i < 5; ++i) { 
   cout << "\nDetails of Employee " << (i + 1) << ":" << endl; 
  employees[i].displayDetails(); 
  } 
  return 0; 
} 
