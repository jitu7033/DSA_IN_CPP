#include<bits/stdc++.h>
using namespace std;
static int edges[1000][1000];
class Graph{
	int n;
public:
	Graph(int val){
		n = val;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				edges[i][j] = 0;
			}
		}
	}
};
void display(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<edges[i][j]<<" ";
		}
		cout<<endl;
	}
}

void build(Node* &root,vector<int>&v){

}

void insert(int x, int y, int n){
	if(x<0 || y>n){
		cout<<"vertex x is not Valid"<<endl;
		return;
	}
	if(y<0 || y>n){
		cout<<"vertex is not valid"<<endl;
		return;
	}
	if(x==y){
		cout<<"same vertex "<<endl;
		return;
	}
	edges[x][y] = 1;
	edges[y][x] = 1;
}
int main(){
	int n,m;cin>>n>>m;
	Graph graph(n);
	// display(n);
	for(int i = 0; i<m; i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		insert(x,y,n);
	}
	display(n);
}