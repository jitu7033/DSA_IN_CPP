#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	vector<Node*>child;

	Node(int val){
		this->val = val;
	}
};

void preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->val<<" ";
	for(Node* child:root->child){
		preorder(child);
	}
	return;
}

void inorder(Node* root){
	if(root==NULL)return;

	int childNodes = root->child.size();

	for(int i=0; i<childNodes-1; i++){
		inorder(root->child[i]);
	}
	cout<<root->val<<" ";
	if(childNodes>0){
		inorder(root->child[childNodes-1]);
	}
}

void postorder(Node* root){
	if(root==NULL)return;

	for(Node* child:root->child){
		preorder(child);
	}
	cout<<root->val<<" ";
}

void levelorder(Node* root){
	if(root==NULL)return;

	queue<Node*>q;
	q.push(root);

	while(!q.empty()){
		int currNodeSize = q.size();
		while(currNodeSize--){
			Node* curr = q.front();
			q.pop();
			cout<<curr->val<<" ";
			for(Node* child:curr->child){
				q.push(child);
			}
		}
		cout<<endl;

	}
}


// just greater than target 
void justGreater(Node* root, int target, int &ans){
	if(root==NULL)return;
	
	int prev = root->val;
	if(ans>prev && prev>target){
		ans = prev;
	}

	for(Node*child: root->child){
		justGreater(child,target,ans);
	}
}

void mirrorview(Node* root){
	if(root==NULL)return;

	reverse(root->child.begin(),root->child.end());

	for(Node* child:root->child){
		mirrorview(child);
	}
}

void serializedTree(Node* root, string &ans){
	if(root==NULL)return;

	ans+= to_string(root->val) + ":" + to_string(root->child.size()) + ":";
	for(Node* child:root->child){
		ans+= to_string(child->val) +",";
	}
	if(root->child.size())ans.pop_back();
	ans+="\n";
	for(Node*child:root->child){
		serializedTree(child,ans);
	}
}

int main(){
	Node* root = new Node(1);
	root->child.push_back(new Node(2));
	root->child.push_back(new Node(3));
	root->child.push_back(new Node(4));
	root->child[0]->child.push_back(new Node(5));
	root->child[1]->child.push_back(new Node(7));

	cout<<root->val<<endl;
	for(Node* children:root->child){
		cout<<children->val<<" ";
	}
	cout<<endl;
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	levelorder(root);
	cout<<endl;
	int x = 10;
	justGreater(root,1,x);
	cout<<x<<endl;

	mirrorview(root);
	levelorder(root);

	string ans = "";
	serializedTree(root,ans);
	cout<<ans<<endl;
}