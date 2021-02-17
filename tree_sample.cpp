#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
struct Node *root=NULL;

struct Node * build(int n){
	int i,val;
	struct node *temp,*curr;
	for(i=0;i<n;i++){
		cout << "Enter Node Data" ;
		cin >>val;
		temp=new Node(val);
		if(root==NULL){
			root=temp;
			curr=temp;
		}
		else{
			while(1){
				if(curr->left==NULL){
					curr->left=temp;
					break;
				}
				else(curr->right==NULL){
					curr->right=temp;
				}
				if(curr->left->left!=NULL && curr->left->right!=NULL){
					curr=curr->right;
					break;
				}
				else{
					curr=curr->left;
					break;
				}
			}
		}

	}
}
int main(){
	if(root==NULL){
		root=new Node(1);
	}
	else{
		root->left=new Node(2);
		root->right=new Node(3);
	}
	cout << "%d\t" << root->data;
	return 0;
}