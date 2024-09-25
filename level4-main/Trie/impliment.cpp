#include<bits/stdc++.h>
using namespace std;


class Node{
public:
	vector<Node*>child;
	bool eow;

	Node(){
		child.resize(26,NULL);
		eow = false;
	}
};

Node* root = new Node();

void insert(string word){
	Node* curr = root;
	for(int i = 0; i < word.length(); i++){
		int idx = word[i]-'a';
		if(curr->child[idx] == NULL){
			curr->child[idx] = new Node();
		}

		if(i == word.length()-1)curr->child[idx]->eow = true;
		curr = curr->child[idx];
	}
}

int search(string word){
	Node* curr = root;
	for(int i = 0; i < word.length(); i++){
		int idx = word[i]-'a';
		Node* node = curr->child[idx];
		if(node == nullptr)return false;
		if(i == word.length()-1 && node->eow == false)return false;
		curr = node;
	}
	return true;
}


int main(){
	string word = "Hello";
	string find = "world";
	insert(word);
	insert("world");
	cout<<search(find)<<endl;
}
