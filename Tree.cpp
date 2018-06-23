#include<iostream>
#include<algorithm>

using namespace std;

class Node{
	private:
		int val;
		Node* left;
		Node* right;
	public:
		Node(int v){
			val=v;
			left=NULL;
			right=NULL;
		}
		void setVal(int v){
			val = v;
		}
		int getVal(){
			return val;
		}
		void setLeft(Node* l){
			left=l;
		}
		Node* getLeft(){
			return left;
		}
		void setRight(Node* r){
			right=r;
		}
		Node* getRight(){
			return right;
		}
};

class Tree{
	private:
		Node* root;
	public:
		Tree(){
				root=NULL;
		}
		Tree(Node* n){
			root=n;
		}
		void setRoot(Node* h){
			root=h;
		}
		Node* getRoot(){
			return root;
		}
		
		void addNodeToTree(Node* curr, Node* newNode ){
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
			Node* newNode =new Node(n);
			if(root==NULL){
				root=newNode;
			}
			else{
				addNodeToTree(root,newNode);
			}
		}
		
		void InOrderPrint(Node* curr){
			if(curr == NULL) return;
			InOrderPrint(curr->getLeft());
			cout<<curr->getVal()<<endl;
			InOrderPrint(curr->getRight());
			
		}
		void PreOrderPrint(Node* curr){
			if(curr == NULL) return;
			cout<<curr->getVal()<<endl;
			InOrderPrint(curr->getLeft());
			InOrderPrint(curr->getRight());
			
		}
		void PostOrderPrint(Node* curr){
			if(curr == NULL) return;
			InOrderPrint(curr->getLeft());
			InOrderPrint(curr->getRight());
			cout<<curr->getVal()<<endl;	
		}
		
		int heightOfTree(Node* curr){
			if(curr == NULL) return 0;
			int leftHeight = heightOfTree(curr->getLeft());
			int rightHeight = heightOfTree(curr->getRight());
			return (max(leftHeight, rightHeight) + 1);
		}
		
		int minHeightOfTree(Node* curr){
			if(curr == NULL) return 0;
			int leftHeight = heightOfTree(curr->getLeft());
			int rightHeight = heightOfTree(curr->getRight());
			return (min(leftHeight, rightHeight) + 1);
		}
		
		
};

int main(){
	Tree* t = new Tree();
	int ch, val;
	
	while(1){
		cout<<"\n1.Insert Element into the Tree"<<endl;
		cout<<"2.Print tree in Inorder"<<endl;
		cout<<"3.Print tree in Preorder"<<endl;
		cout<<"4.Print tree in Postorder"<<endl;
		cout<<"5.Height of tree"<<endl;
		cout<<"6.Minimum height of tree"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		switch(ch){
			case 1:
				cout<<"\nEnter node value: ";
				cin>>val;
				t->addNode(val);
				break;
			case 2:
				cout<<"\nPrinting tree in inorder: "<<endl;
				t->InOrderPrint(t->getRoot());
				break;
			case 3:
				cout<<"\nPrinting tree in preorder: "<<endl;
				t->PreOrderPrint(t->getRoot());
				break;
			case 4:
				cout<<"\nPrinting tree in postorder: "<<endl;
				t->PostOrderPrint(t->getRoot());
				break;
			case 5:
				val = t->heightOfTree(t->getRoot());
				cout<<"\nHeight of tree is "<<val<<endl;
				break;
			case 6:
				val = t->minHeightOfTree(t->getRoot());
				cout<<"\nMinimum height of tree is "<<val<<endl;
				break;
			default:
				return 0;
		}
		
	}
	
	return 0;
}
