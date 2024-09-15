#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};
void inorderTraversal(node*root,int &count){
    if(root == NULL)
        return;
    inorderTraversal(root->left,count);
    if(root->left == NULL && root->right==NULL){
        count++;
        }
    inorderTraversal(root->right,count);
    
 
}
int countLeafNode(node* root){
    int count = 0;
    if(root == NULL) return count;
    inorderTraversal(root,count);
    return count;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<"Count of leaf nodes: "<<countLeafNode(root);
    return 0;
}