#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
vector<int> v;
int size;
	Queue(){
		int size = 0;
	}
	void push(int x){
		v.push_back(x);
		size++;
	}
	void pop(){
		if(size == 0){
			return;
		}
		else{
			for(int i=0;i<v.size()-1;i++){
				v[i] = v[i+1];
			}
			size--;
		}
	}
	int front(){
		if(size == 0) return -1;
		else{
			return v[0];
		}
	}
	bool empty(){
		return v.size()<=0;
	}
};

class Stack{
public:
	vector<int> v;
	int size;

	Stack(){
		size = 0;
	}
	void push(int x){
		v.push_back(x);
		size++;
	}
	void pop(){
		if(size == 0){
			return;
		}
		else{
			v.pop_back();
			size--;
		}
	}
	int top(){
		return v.back();
	}
	bool empty(){
		return v.size()<=0;
	}
};

int main(){
	Queue q;
	q.push(10);
	q.push(100);
	q.push(1000);
	q.push(10000);

	cout<<q.front()<<endl;

	Stack s;
	s.push(10);
	s.push(100);
	s.push(1000);
	s.push(10000);

	cout<<s.top()<<endl;

	

	return 0;
}