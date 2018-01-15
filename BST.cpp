#include<iostream>
#include<stdlib.h>
using namespace std;

class TreeNode{
	private: 
		int val;
		TreeNode* left;
		TreeNode* right;

	
	public:
		TreeNode(int n){
			val=n;
			left=NULL;
			right=NULL;
		}
		
		void setVal(int v){
			val=v;
		}
		
		int getVal(){
			return val;
		}
		
		void setLeft(TreeNode* l){
			left=l;
		}
		
		TreeNode* getLeft(){
			return left;
		}
		
		void setRight(TreeNode* r){
			right=r;
		}
		
		TreeNode* getRight(){
			return right;
		}
};


class Tree{
	private:
		TreeNode* root;
	public:
		Tree(){
			root=NULL;
		}
		
		Tree(TreeNode* n){
			root=n;
		}
		
		TreeNode* getRoot(){
			return root;
		}
		
		void addNodeToTree(TreeNode* curr,TreeNode* newNode ){
			if(curr->getVal() > newNode->getVal()){
				if(curr->getLeft()==NULL)
					curr->setLeft(newNode);
				else
					addNodeToTree(curr->getLeft(),newNode);
			}
			else{
				if(curr->getRight()==NULL)
					curr->setRight(newNode);
				else
					addNodeToTree(curr->getRight(),newNode);
			}
		}
		
		void addNode(int n){
			TreeNode* newNode = new TreeNode(n);
			if(root==NULL){
				root=newNode;
			}
			else addNodeToTree(root,newNode);
		}
		
};


int main(){
	Tree* t =new Tree();
	TreeNode* tempRoot;
	int choice,value;
	while(1){
		cout<<"\n1.Insert element to the tree\n6.Exit\nEnter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Value to be inserted:";
				cin>>value;
				t->addNode(value);
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"\nWrong Choice!"<<endl;
		}
	}
}







