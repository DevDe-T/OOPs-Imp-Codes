#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Manager{
public:
	void print();

};

class Employee{
private:
	int x;
	int y;

	friend class Manager;
};

void Manager :: print(){
	Employee e;
	e.x = 20;
	e.y = 10;
	cout<<e.x<<" "<<e.y;
}

int main(){
	Manager m;
	m.print();
	
	return 0;
}