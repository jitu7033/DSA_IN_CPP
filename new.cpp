#include<bits/stdc.h>
using namespace std;


void bubble_sort(vector<int>&v){
	int n = v.size();
	for(int i=0; i<n; i++){
		for(int j = 0; j < n-i-1; j++){
			if(v[j]>v[j+1]]){
				swap(v[j],v[j+1]);
			}
		}
	}
}


int main(){
	int n;
	vector<int>v(n);
	for(auto &i:v){
		cin>>i;
	}
	bubble_sort(v);
	for(auto &i:v){
		cout<<i<<" ";
	}
	cout<<endl;
}