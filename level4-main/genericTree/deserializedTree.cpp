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


Node* deserilizedHelperTree(int nodeValue,unordered_map<int,string>mp){
	Node* node = new Node(nodeValue);
	string nodestr = mp[nodeValue];

	if(nodestr[0]==0){
		return node;
	}
	int breakpos = nodestr.find(':');
	int childNodesNumber = stoi(nodestr.substr(0,breakpos));
	string chilNodesStr = nodestr.substr(breakpos+1);
	int start = 0;
	for(int i=0; i<childNodesNumber; i++){
		int end = chilNodesStr.find(',',start);
		if(end==string::npos)end = chilNodesStr.size();
		int childNodeValue = stoi(chilNodesStr.substr(start,end));
		node->child.push_back(deserilizedHelperTree(childNodeValue,mp));
		start = end+1;
	}

	return node;
}

Node* deserilized(string s){
	if(s==""){
		return NULL;
	}

	unordered_map<int,string>mp; // nodeValue and children string 
	int start = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i]==('\n')){
			string nodestr = s.substr(start,i-start);// "1:3:4,3,2" 
			int breakpos1 = nodestr.find(':');
			int nodeValue = stoi(nodestr.substr(0,breakpos1));// 1 
			mp[nodeValue] = nodestr.substr(breakpos1+1); // "3:4,3,2"
			start = i+1;
		}
	}
	int rootnodeValue = stoi(s.substr(0,s.find(':')));
	return deserilizedHelperTree(rootnodeValue,mp);
}


int main(){
	Node* root = new Node(1);
	root->child.push_back(new Node(2));
	root->child.push_back(new Node(3));
	root->child.push_back(new Node(4));
	root->child[0]->child.push_back(new Node(5));
	root->child[1]->child.push_back(new Node(7));

	levelorder(root);
	string s = "";
	serializedTree(root,s);
	cout<<s<<endl;
	deserilized(s);
	levelorder(root);
}
