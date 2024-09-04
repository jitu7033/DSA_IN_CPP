#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this->data = data;
		left = right = NULL;
	}
	Node(){

	}
};


void  buildTree(vector<int>v, Node* &root, int i, int n){
	if(i<n){
		root = new Node(v[i]);
		buildTree(v,root->left,2*i+1,n);
		buildTree(v,root->right,2*i+2,n);
	}
}

int depth(Node* root){
	if(root==NULL){
		return 0;
	}
	return max(depth(root->left),depth(root->right))+1;
}
// check perfect 
class perfectBinary{
public:
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
void inorder(Node* root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void bfs(Node* root){
	queue<Node*>q;
	q.push(root);
	bool flag = true;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			Node *temp = q.front();
			cout<<temp->data<<" ";
			q.pop();
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right)q.push(temp->right);
		}
	}
}

// level order display 
int level(Node* root){
	if(root==NULL)return 0;
	return max(level(root->left),level(root->right));
}
void level_order_display(Node* root,int n){
	if(root==NULL)return;
	if(n==1){cout<<root->data<<" ";return;}
	level_order_display(root->left,n-1);
	level_order_display(root->right,n-1);
}

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
					cout<<temp->data<<" ";
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
					mp[currCol] = currNode->data;
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
int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(auto &i:v){
		cin>>i;
	}
	Node* root = new Node();
	buildTree(v,root,0,n);
	for(int i=0; i<n; i++){
		level_order_display(root,i);
	}
	cout<<endl;
	view v1;
	v1.top_view(root);
	cout<<endl;
	v1.right_view(root);
	
}