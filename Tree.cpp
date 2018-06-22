#include<iostream>

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
			val v;
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

class treeNode{
	private:
		Node* root;
	public:
		treeNode(){
				root=NULL;
		}
		treeNode(Node* n){
			root=n;
		}
		void setRoot(Node* h){
			root=h;
		}
		Node* getRoot(){
			return root;
		}
};

int main(){
	
	
	return 0;
}
