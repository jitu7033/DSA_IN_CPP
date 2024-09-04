#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val){
		this->val = val;
		left=right = NULL;
	}
};

TreeNode* leastGreterBst(TreeNode* root, int ele,int &success){

	if(root==NULL){
		return new TreeNode(ele);
	}

	if(root->val>ele){
		success = root->val;
		root->left = leastGreterBst(root->left,ele,success);
	}
	else if(root->val<ele){
		root->right = leastGreterBst(root->right,ele,success);
	}
	return root;
}
int main(){
	TreeNode* root = NULL;
	int n;
	cin>>n;
	vector<int>ans(n);
	for(int i=0; i<n; i++){
		cin>>ans[i];
	}
	for(int i=n-1; i>=0; i--){;
		int success = -1;
		root = leastGreterBst(root,ans[i],success);
		ans[i] = success;
	}
	for(auto &i:ans){
		cout<<i<<" ";
	}
}