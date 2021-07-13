#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
	string Name;
	string Company;
	int Age;

	Employee() {
		Name = "John";
		Company = "CMP";
		Age = 10;
	}

	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

	void printInfo() {
		cout << Name << " " << Company << " " << Age << "\n";
	}
};

int main() {
	Employee emp1;
	emp1.printInfo();

	Employee emp2("Shagun", "ASDSAD", 12);
	emp2.printInfo();
	return 0;
}