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

void levelorder_traversal(Node* root){
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		int size = q.size();
		Node* node = q.front();
		q.pop();
		cout<<node->data<<" ";
		while(size--){
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(root->right);
			}
		}
	}
}

void buildtree(Node* &root){
	int x;
	cin>>x;
	int first,second;
	queue<Node*>q;
	root = new Node(x);
	q.push(root);
	while(!q.empty()){
		Node*temp = q.front();
		q.pop();
		cin>>first; // left node value 
		if(first!=-1){
			temp->left = new Node(first);
			q.push(temp->left);
		}
		cin>>second;
		if(second!=-1){
			temp->right = new Node(second);
			q.push(temp->right);
		}
	}
}

void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


// heigth of binary tree ppt -> ques(9);
int heightOfTree(Node * root){
	if(root==NULL){
		return 0;
	}
	int left = heightOfTree(root->left);
	int right = heightOfTree(root->right);
	return max(left,right)+1;
}

// check balance tree or not ppt question ->   ques(10);
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
// ppt ques(11)  ->  sum root to leaf number ... 

void SRTLN(Node* root,vector<string>&ans, string temp){
	if(root==NULL){
		temp = "";
		return;
	}
	temp+= root->data+'0';
	if(root->left==NULL && root->right==NULL)ans.push_back(temp);
	SRTLN(root->left,ans,temp);
	SRTLN(root->right,ans,temp);
	temp.pop_back();
}
void solve_SRTLN(Node* root){
	vector<string>ans;
	string temp = "";
	SRTLN(root,ans,temp);
	int sum = 0;
	for(int i=0; i<ans.size(); i++){
		sum+=stoi(ans[i]);
	}
	cout<<sum<<endl;
}

// end ... sum root to leaf number 

// ppt ques(12) -> lowest common ancestor 


bool contain(Node* root,int x){
	if(root==NULL){
		return false;
	}
	if(root->data==x)return true;
	return contain(root->left,x) || contain(root->right,x);
}

int LCA(Node* root,int x, int y){
	if(root->data==x || root->data==y){
		return root->data;
	}
	bool left = contain(root->left,x);
	bool right = contain(root->right,y);
	if(left && right){return root->data ;}
	if(!left && right)return LCA(root->right,x,y);
	if(left && !right)return LCA(root->left,x,y);
	return root->data;

}

int main(){
	Node * root = NULL;
	buildtree(root);
	// inorder(root);
	// cout<<endl;
	cout<<"print Level order traversal -> : ";
	// levelorder_traversal(root);
	cout<<endl;
	cout<<"check checkBalancedTree or Not ->  : ";
	cout<<checkBalancedTree(root)<<endl;
	cout<<"sum of root to leaf number : -> ";
	solve_SRTLN(root);
	cout<<"Lowest common ancestor of the tree -> : ";
	cout<<LCA(root,4,5)<<endl;
}
