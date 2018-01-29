#include<bits/stdc++.h>
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
		
		
		void printInOrder(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			printInOrder(curr->getLeft());
			cout<<(curr->getVal())<<endl;
			printInOrder(curr->getRight());
 		}

 		void printPostOrder(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			printPostOrder(curr->getLeft());
			printPostOrder(curr->getRight());
			cout<<(curr->getVal())<<endl;
 		}

 		void printPreOrder(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			cout<<(curr->getVal())<<endl;
			printPreOrder(curr->getLeft());
			printPreOrder(curr->getRight());
 		}
 		
 		int heightTree(TreeNode* curr){
 			if(curr==NULL)return 0;
 			return 1 + max(heightTree(curr->getLeft()) , heightTree(curr->getRight()));
 		}
 		
 		int sizeTree(TreeNode* curr){
 			if(curr==NULL) return 0;
 			return 1 + sizeTree(curr->getLeft()) + sizeTree(curr->getRight());
 		}
 		
};


int main(){
	Tree* t =new Tree();
	TreeNode* tempRoot;
	int choice,value;
	while(1){
		cout<<"\n1.Insert element to the tree\n2.Traverse the tree\n3.Delete\n4.Height of tree\n5.Size of tree\n6.Exit\nEnter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Value to be inserted:";
				cin>>value;
				t->addNode(value);
				break;
			case 2:
				cout<<"\nInorder: "<<endl;
				t->printInOrder(t->getRoot());
				cout<<"\nPreorder: "<<endl;
				t->printPreOrder(t->getRoot());
				cout<<"\nPostorder: "<<endl;
				t->printPostOrder(t->getRoot());
				break;
			case 4:
				cout<<"\nHeight of tree is:"<<endl;
				cout<<t->heightTree(t->getRoot())<<endl;
				break;
			case 5:
				cout<<"\nSize of tree is:"<<endl;
				cout<<t->sizeTree(t->getRoot())<<endl;
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"\nWrong Choice!"<<endl;
		}
	}
}







