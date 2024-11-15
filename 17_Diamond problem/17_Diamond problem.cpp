#include <iostream>
#include "Student.h"
#include "Employee.h"
#include "StudentEmployee.h"
using namespace std;
int main()
{
	Student stud("DENIS", "CS");
	stud.print();
	cout << "\n\n";

	Employee emp("denis", "Manager");
	emp.print();
	cout << "\n\n";

	StudentEmployee se("Vasil", "Front-end", "Traines");
	/*se.Student::print();
	se.Employee::print();*/
	se.print();

	/*StudentEmployee se(stud, emp);
	se.print();
	cout << "\n\n";*/
}
