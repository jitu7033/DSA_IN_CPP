#include<bits/stdc++.h>
using namespace std;
#define nline "\n"

class Node{
public:
	int val;
	Node* left;
	Node* right;

	Node(int val){
		this->val = val;
		left = right = NULL;
	}
	Node(){

	}
};
// 1 2 3 4 5 
// 0 1 2 3 4 

Node* buildTree(vector<int>&v,Node*& root, int i, int n){

	if(i<n){
		root = new Node(v[i]);
		buildTree(v,root->left,2*i+1,n);
		buildTree(v,root->right,2*i+2,n);
	}
	return root;
}

void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}


int heightOfTree(Node * root){
	if(root==NULL){
		return 0;
	}
	int left = heightOfTree(root->left);
	int right = heightOfTree(root->right);
	return max(left,right)+1;
}

bool checkBalancedTree(Node* root){
	if(root==NULL){
		return true;
	}
	int lh = heightOfTree(root->left);
	if(root->left!=NULL)lh++;
	int rh = heightOfTree(root->right);
	if(root->right)rh++;
	if(abs(lh-rh)>1)return false;

	return checkBalancedTree(root->left) && checkBalancedTree(root->right);

}



int main(){
	Node* root = NULL;
	int n;
	cout<<"enter size"<<endl;
	cin>>n;
	vector<int>v(n);
	cout<<"enter value"<<"\n";
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	buildTree(v,root,0,n);
	inorder(root);
	cout<<nline;
	cout<<"heightOfTree"<<nline;
	cout<<heightOfTree(root)<<endl;
	cout<<"check balanced binary tree"<<nline;
	cout<<checkBalancedTree(root);
}
