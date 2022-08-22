#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Sort{
public:
	int n;
	int *arr;

	Sort(int arr[], int size){
		this->n = size;
		this->arr = arr;
		// for(int i=0;i<n;i++){
		// 	this->arr[i] = arr[i];
		// }
	}

	int bubble_sort(){
		int swaps = 0;
		for(int i=0;i<n-1;i++){
			int f = 0;
			for(int j=0;j<n-i-1;j++){
				if(arr[j] > arr[j+1]){
					swaps++;
					f=1;
					swap(arr[j], arr[j+1]);
				}
			}
			if(f == 0){
				break;
			}
		}
		return c;
	}
	int selection_sort(){
		int swaps = 0;
		for(int i=0;i<n;i++){
			int min_idx = i;
			for(int j=i+1;j<n;j++){
				if(arr[min_idx] > arr[j]){
					swaps++;
					min_idx = j;
				}
			}
			swap(arr[min_idx], arr[i]);
		}
		return c;
	}
	int insertion_sort(){

		int swaps = 0;
		for(int i=1;i<n;i++){
			int j = i-1;
			int key = arr[i];
			while(j>=0 && arr[j]>key){
				swaps++;
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = key;
		}
		return c;
	}
	void shell_sort(){
		for(int gap = n/2;gap>0;gap=gap/2){
			for(int i=gap;i<n;i++){
				int temp = arr[i];
				int j = i;
				for(j=i;j>=gap && arr[j-gap]>temp;j++){
					arr[j] = arr[j-gap];
				}
				arr[j] = temp;
			}
		}
	}
	int partition(int p, int q){
		int i=p-1,pivot = arr[q];

		for(int j=p;j<q;j++){
			if(arr[j] <= pivot){
				i++;
				swap(arr[i], arr[j]);
			}
			
		}
		swap(arr[i+1], pivot);
		return i+1;
	}

	void quick_sort(int p, int r){
		if(p<r){
			int q = partition(p, r);
			quick_sort(p,q-1);
			quick_sort(q+1,r);
		}
	}

	void print(){
		for(int i=0;i<n;i++){
			cout<<arr[i]<<endl;
		}
	}

};


void print(int arr[], int n){
	for(int i=0;i<n;i++){
			cout<<arr[i]<<endl;
		}
}

int partition(int arr[],int p, int r){
		int i=p-1,pivot = arr[r];

		for(int j=p;j<r;j++){
			if(arr[j] <= pivot){
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i+1], arr[r]);
		return i+1;
	}

	void quick_sort(int arr[], int p, int r){
		if(p<r){
			int q = partition(arr, p, r);
			quick_sort(arr, p,q-1);
			quick_sort(arr, q+1,r);
		}
	}

void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	for(int i=0;i<n1;i++){
		L[i] = arr[l+i];
	}
	for(int j=0;j<n2;j++){
		R[j] = arr[m+1+j];
	}

	int i=0,j=0,k=l;

	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else if(L[i] > R[j]){
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int l, int r){
	if(l<r){
		int m = l+(r-l)/2;
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}



struct Item{
	int value;
	int weight;
};



bool comp(pair<int,double> a, pair<int,double> b){
	return a.second>b.second;
}

double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        map<pair<int,int>, double> newItem;
        vector<pair<int,double>> v;
        struct newItemClass{
            int value;
            int weight;
            double pwr;
        };

        newItemClass arr1[3];

        for(int i=0;i<n;i++){
        	double v = arr[i].value;
        	double w = arr[i].weight;
            newItem[{arr[i].value, arr[i].weight}] =  v/w ;
        }
        int i=0;
        for(auto it : newItem){
            v.push_back({i, it.second});
            i++;
        }
        sort(v.begin(), v.end(), comp);
        reverse(v.begin(), v.end());

        double ans=0;
        for(auto it : v){
        	for(auto it2 : newItem){
        		if(it.second == it2.second){
        			if(W >= it2.first.second){
        				ans+=it2.first.first;
        				W-=it2.first.second;
        			}
        			else{
        				ans+=it.second * W;
        				return ans;
        			}
        		}
        	}
        }
        return ans;


        
        
        
        
    }


int main(){
	int n = 3;
	Item arr[n];
	int W = 60;
	for(int i=0;i<n;i++){
		int v,w;
		cin>>v>>w;
		arr[i].weight = w;
		arr[i].value = v;
	}
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i].weight<<endl;
	// 	cout<<arr[i].value<<endl;
	// }
	cout<<fractionalKnapsack(W, arr, n);


	return 0;
}