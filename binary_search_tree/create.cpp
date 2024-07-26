#include<bits/stdc++.h>
using namespace std;


class Node{
public:
	Node* left;
	Node* right;
	int val;

	Node(int value){
		left=right=NULL;
		val = value;
	}
};

class BST{
public:
	Node* root;
	BST(){
		root = NULL;
	}
};


// find lcs in binary search tree 

Node* lcs(Node* root, int x, int y){
	if(root==NULL){
		return root;
	}
	if(root->val>x && root->val>y){
		return lcs(root->left,x,y);
	}
	else if(root->val<x && root->val<y){
		return lcs(root->right,x,y);
	}
	else{
		return root;
	}
}

Node* largestNodeBst(Node* root){
	Node* curr = root;
	while(curr && curr->right!=NULL){
		curr = curr->right;
	}

	return curr;

}

// check perfect 
class perfectBinary{
public:

	int depth(Node* root){
		if(root==NULL){
			return 0;
		}
		return max(depth(root->left),depth(root->right))+1;
	}

	bool checkPerfectRoot(Node* root,int d, int level = 0){
		if(root==NULL)return true;
		if(root->left==NULL && root->right==NULL){
			return (d==level+1);
		}
		if(root->left==NULL || root->right==NULL){
			return false;
		}
		return checkPerfectRoot(root->left,d,level+1) && checkPerfectRoot(root->right,d,level+1);
	}
	bool check_perfect(Node* root){
		int d = depth(root);
		return checkPerfectRoot(root,d);
	}

	bool checkComplete(Node* root){
		queue<Node*>q;
		q.push(root);
		bool flag = false;
		while(!q.empty()){
			Node* temp = q.front();
			q.pop();
			if(temp==NULL){
				flag = true;
			}
			else{
				if(flag){
					return false;
				}
				q.push(temp->left);
				q.push(temp->right);
			}
		}
		return true;
	}
};

// top view and right most view of a tree

class view{
public:
	void right_view(Node* root){
		queue<Node*>q;
		q.push(root);
		while(!q.empty()){
			int size  =q.size();
			int l = size;
			while(size){
				Node*temp = q.front();
				q.pop();
				if(size==1){
					cout<<temp->val<<" ";
				}
				if(temp->left){
					q.push(temp->left);
				}
				if(temp->right){
					q.push(temp->right);
				}
				size--;
			}
		}

	}
	void top_view(Node*root){
		map<int,int>mp;
		queue<pair<Node*,int>>q;
		q.push(make_pair(root,0));
		while(!q.empty()){
			int size = q.size();
			while(size--){
				pair<Node*,int>temp = q.front();
				Node* currNode = temp.first;
				int currCol = temp.second;
				q.pop();
				if(mp.find(currCol)==mp.end()){
					mp[currCol] = currNode->val;
				}
				if(currNode->left){
					q.push(make_pair(currNode->left,currCol-1));
				}
				if(currNode->right){
					q.push(make_pair(currNode->right,currCol+1));
				}
			}
		}
		for(auto x:mp){
			cout<<x.second<<" ";
		}
		cout<<endl;
	}
};



Node* delete_bst(Node* root,int key){
	if(root==NULL)return root;
	// no child 
	if(root->val<key)root->right = delete_bst(root->right,key);
	else if(root->val>key)root->left = delete_bst(root->left,key);
	else { // root is the node to be delete 
		if(root->left==NULL && root->right==NULL){
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else{
			Node* justsmall = largestNodeBst(root->left);
			root->val = justsmall->val;
			root->left = delete_bst(root->left,justsmall->val);

		}

	}
	return root;
}

void insertBST(Node* &root, int value){
	Node* newNode = new Node(value);
	if(root==NULL){
		root = newNode;
		return;
	}
	Node* curr = root;
	while(true){
		if(curr->val>value){
			if(curr->left==NULL){
				curr->left = newNode;
				return;
			}
			curr = curr->left;
		}
		else{
			if(curr->right==NULL){
				curr->right = newNode;
				return;
			}
			curr = curr->right;
		}
	}
}

// insert bst recursevely

Node* insert_bst(Node* &root,int value){
	Node* newNode = new Node(value);
	if(root==NULL){
		root = newNode;
		return newNode;
	}
	if(root->val>value){
		root->left = insert_bst(root->left,value);
	}
	else if(root->val<value){
		root->right = insert_bst(root->right,value);
		
	}
	return root;
}

// remove all leafnode from binary tree

Node* removeLeaf(Node* root){

	if(root==NULL)return NULL;
	if(root->left==NULL && root->right==NULL){
		return NULL;
	}
	root->left = removeLeaf(root->left);
	root->right= removeLeaf(root->right);
	return root;
}

// inorder traversal
void inorder_traversal(Node* root){
	if(root==NULL)return;


	inorder_traversal(root->left);
	cout<<root->val<<" ";
	inorder_traversal(root->right);
}


// level order;
void level_order_display(Node* root, int n){
	if(root==NULL)return;
	if(n==1){cout<<root->val<<" ";return;}
	level_order_display(root->left,n-1);
	level_order_display(root->right,n-1);
}
int main(){
	BST bst;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int ele;
		cin>>ele;
		insert_bst(bst.root,ele);
	}
	inorder_traversal(bst.root);
	cout<<endl;
	cout<<"LCS"<<endl;
	cout<<lcs(bst.root,4,7)->val<<endl;
	// removeLeaf(bst.root);
	inorder_traversal(bst.root);
	cout<<endl;
	for(int i=0; i<n; i++){
		level_order_display(bst.root,i);
		cout<<endl;
	}
}