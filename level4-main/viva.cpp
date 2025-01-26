#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void solve(TreeNode* root,vector<int>&v){
	if(root == nullptr){
		return;
	}
	solve(root->left,v);
	ans.push_back(root->val);
	solve(root->right);
}

bool validBst(TreeNode* root){
	vector<int>v;
	solve(root,v);
	for(int i = 1; i < v.size(); i++){
		if(v[i - 1] > v[i])return false;
	}
	return true;
}


// 2 1 5 6 2 3
// -1 -1 1 5 1 2 
// 5 5 6-1 3 -1




