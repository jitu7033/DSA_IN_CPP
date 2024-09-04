#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v;
        left = right = NULL;
    }

};

// check binary tree is full or not

bool isFullBinaryTree(Node* root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }

    if(root->left && root->right){
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }
    return false;
}

void preorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->value<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->value<<" ";
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->value<<" ";
}

void levelorder_traversal(Node* root){
    if(root==NULL)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* currnode = q.front();
            q.pop();
            cout<<currnode->value<<" ";
            if(currnode->left!=NULL){
                q.push(currnode->left);
            }
            if(currnode->right!=NULL){
                q.push(currnode->right);
            }
        }
        cout<<endl;
    }
}

// find the max depth of the tree 

int max_depth(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = max_depth(root->left);
    int right = max_depth(root->right);

    return max(left,right)+1;
}

// print all the leaf node from the tree

int print_leafnode(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->value<<" "; // print the leaf Node 
        return 1;
    }
    int left = print_leafnode(root->left);
    int right = print_leafnode(root->right);
    return left+right;
}

// right view binary tree node 
vector<int>right_view(Node* root){
    queue<Node*>q;
    vector<int>ans;
    if(root==NULL)return ans;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size){
            Node* currnode = q.front();
            q.pop();
            if(size==1){
                ans.push_back(currnode->value);
            }
            if(currnode->left){
                q.push(currnode->left);
            }
            if(currnode->right){
                q.push(currnode->right);
            }
            size--;
        }
    }
    return ans;
}

// top most view of tree
vector<int>top_view(Node* root){
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    map<int,int>mp;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            pair<Node*,int>p = q.front();
            Node* currnode = p.first;
            int currCol = p.second;
            q.pop();
            if(mp.find(currCol)==mp.end()){
                mp[currCol] = currnode->value;
            }
            if(currnode->left){
                q.push(make_pair(currnode->left,currCol-1));
            }
            if(currnode->right){
                q.push(make_pair(currnode->right,currCol+1));
            }

        }
    }
    vector<int>ans;
    for(auto &i:mp){
        ans.push_back(i.second);
    }
    return ans;

}


int main(){

    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    root->right->right->right = new Node(12);

    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);
    cout<<endl;
    levelorder_traversal(root);
    cout<<max_depth(root);
    cout<<endl;
    cout<<print_leafnode(root);
    cout<<endl;

    vector<int>ans = right_view(root);
    for(auto &i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>topView = top_view(root);
    for(auto &i:topView){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<isFullBinaryTree(root)<<endl;;
}