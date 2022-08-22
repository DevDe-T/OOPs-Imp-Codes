#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Employee{
public:
	int eid;
	char *name;
	double salary;

	Employee(int id, char *name, double salary){
		this->eid = id;
		this->name = name;
		this->salary = salary;
	}
	Employee(Employee &e){
		this->eid = e.eid;
		this->name = new char[strlen(e.name)+1];
		strcpy(this->name, e.name);
		this->salary = e.salary;
		strcpy(e.name, "Chaman");
	}

	friend double calcSalary(Employee);

	void print(){
		cout<<this->eid<<" "<<this->name<<" "<<this->salary<<endl;
	}
};

double calcSalary(Employee e){
	return e.salary*2;
}

struct Student{
	int id;
	char name;
	int rank;
};
 

int main(){
	// Solution s;
	char c[] = "Raman";
	Employee e(101, c, 100000);

	Employee e1(e);
	e1.salary = 150000;
	e1.print();
	e.print();
	Employee *e2 = new Employee(e1);

	strcpy(e2->name, "Dharam");
	e2->print();
	e2->salary = 320000;

	cout<<calcSalary(*e2);
	

	

	return 0;
}
