#include<iostream>
using namespace std;



void isEmpty(int *f, int *r, vector<int>&q){
	if(q.size()==r && f==0){
		cout<<"que is full"<<nline;
	}
}

display(int *f, int *r, int q[]){
	while(f<=r){
		cout<<q[f]<<nline;
		f++;
	}
}

void delete(int *f,int *r, int q[]){
	if(isempty())return;
	f++;
}

insert(vector<int>&q, int *r,int ele){
	if(r==q.size()){
		return;
	}
	q[++r] = ele;
}
int main(){
	insert()

}