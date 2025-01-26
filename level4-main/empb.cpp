#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	Node* left;
	Node* right;
	int val;

	Node(int val){
		this->val = val;
		left = right = NULL;
	}
};


Node* insert(Node* root, int val){

	if(root == NULL)return new Node(val);

	if(val < root->val){
		root->left = insert(root->left,val);
	}
	if(val > root->val){
		root->right =  insert(root->right,val);
	}
	return root;
}

Node* insert_level_order(vector<int>&v){
	Node* root = new Node(v[0]);
	int i = 1;
	queue<Node*>q;
	q.push(root);
	while(i < v.size()){
		Node *curr = q.front();
		q.pop();


		//insert left child
		if(v[i] != -1){
			curr->left = new Node(v[i]);
			q.push(curr->left);
		}
		i++;
		if(i < v.size() and v[i] != -1){
			curr->right = new Node(v[i]);
			q.push(curr->right);
		}
		i++;
	}
	return root;

}


void inorder(Node *root){
	if(root == nullptr)return;
	inorder(root->left);
	cout<<root->val<<" "<<endl;
	inorder(root->right);
}


void dijkstra(int src,vector<vector<pair<int,int>>>&adj){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,0});
	vector<int>dist(n + 1, 0);
	vector<int>vis(n + 1, 0);
	vis[src] = 1;
	while(!pq.empty()){
		int currDist = pq.front().first;
		int currNode = pq.front().second;

		if(currDist > dist[currNode])continue;
		for(auto &node: adj[currNode]){
			int child = node.first;
			int dist = node.second;
			if(dist[child] > currDist + dist){
				dist[child] = currDist + dist;
				pq.push({dist[child],child});
			}
		}
	}
}


void solve(){
	int n;cin>>n;
	vector<int>v(n);
	for(auto &x: v){
		cin>>x;
	}
	Node* root = insert_level_order(v);
	inorder(root);
}

int main(){
	solve();
}