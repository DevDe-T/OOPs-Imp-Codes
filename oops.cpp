#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Employee{
public:
	virtual int CalcSalary(int x){
		return x;
	}
};

class Hr : public Employee{
public:
	int CalcSalary(int x){
		return x*2;
	}
};

class Eng : public Employee{
public:
	int CalcSalary(int x){
		return x*3;
	}
};

class Manager : public Employee{
public:
	int CalcSalary(int x){
		return x*4;
	}
};

int main(){
	Employee **e = new Employee*[20];
	Hr h;
	Eng en;
	Manager mg;

	// Employee *e = new Employee;
	// e = &h;
	// cout<<e->CalcSalary(20);

	for(int i=0;i<5;i++){
		e[i] = &h;
	}
	for(int i=5;i<12;i++){
		e[i] = &en;
	}
	for(int i=12;i<20;i++){
		e[i] = &mg;
	}

	for(int i=0;i<20;i++){
		cout<<e[i]->CalcSalary(20)<<endl;
	}
	



	


	return 0;
}