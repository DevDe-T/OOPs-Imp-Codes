#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Employee{
public:
	virtual void print() = 0;
};

class Manager : public Employee{
public:
	void print(){
		cout<<"Manager's here"<<endl;
	}
};

int main(){
	Manager m;
	m.print();
	
	return 0;
}