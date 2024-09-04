#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	Node* left;
	Node* right;
	int val;

	Node(int value){
		val = value;
		left = right = NULL;
	}
};

class bst{
public:
	Node* root;

	bst(){
		root = NULL;
	}
};


Node* sorted_bst(vector<int>&v, int start, int end){
	if(start>end)return NULL;

	int mid = (start+end)/2;
	Node* root = new Node(v[mid]);
	root->left = sorted_bst(v,start,mid-1);
	root->right = sorted_bst(v,mid+1,end);

	return root;

}

void preorder(Node*root){
	if(root==NULL)return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main(){
	bst bst1;
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0; i<n;i++){
		cin>>v[i];
	}
	bst1.root = sorted_bst(v,0,n-1);
	preorder(bst1.root);
}