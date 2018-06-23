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
		
		int diaMeterOfTree(Node* curr){
			if(curr == NULL) return 0;
			int leftHeight = heightOfTree(curr->getLeft());
			int rightHeight = heightOfTree(curr->getRight());
			return ((leftHeight + rightHeight) + 1);
		}
		
		bool searchValue(Node* curr, int n){
			if(curr == NULL) return 0;
			if(curr->getVal() == n) return 1;
			if(curr->getVal() > n) return searchValue(curr->getLeft(), n);
			return searchValue(curr->getRight(), n);
		}
		
		void printAllLeafNode(Node* curr){
			if(curr == NULL) return;
			if(curr->getLeft() == NULL && curr->getRight() == NULL) cout<<curr->getVal()<<endl;
			printAllLeafNode(curr->getLeft());
			printAllLeafNode(curr->getRight());
			
		}
		
		
		void printAllNodewithOneChild(Node* curr){
			if(curr == NULL) return;
			if(curr->getLeft() == NULL && curr->getRight() == NULL) return;
			printAllNodewithOneChild(curr->getLeft());
			printAllNodewithOneChild(curr->getRight());
			if((curr->getLeft() == NULL && curr->getRight() != NULL) || (curr->getLeft() != NULL && curr->getRight() == NULL))
				cout<<curr->getVal()<<endl;
			
		}
		
		void printLevelOrderTree(Node* curr){
			
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
		cout<<"7.Diameter of tree"<<endl;
		cout<<"8.Search node in tree"<<endl;
		cout<<"9.Get leaf nodes"<<endl;
		cout<<"10.Node with 1 child"<<endl;
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
			case 7:
				val = t->diaMeterOfTree(t->getRoot());
				cout<<"\nDiameter of tree is "<<val<<endl;
				break;
			case 8:
				cout<<"\nEnter value to be searched: ";
				cin>>val;
				if(t->searchValue(t->getRoot(),val)) cout<<"\nValue available"<<endl;
				else cout<<"\nValue not available"<<endl;
				break;
			case 9:
				cout<<"\nLeaf nodes: "<<endl;
				t->printAllLeafNode(t->getRoot());
				break;
			case 10:
				cout<<"\nNode with 1 child: "<<endl;
				t->printAllNodewithOneChild(t->getRoot());
				break;
			default:
				return 0;
		}
		
	}
	
	return 0;
}
