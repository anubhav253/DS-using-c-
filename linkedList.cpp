#include<iostream>
using namespace std;

class Node{
	private:
		Node *next;
		int val;
	public:
		Node(int v){
			val=v;
			next=NULL;
		}
		void setVal(Node* n){
			next=n;
		}
		int getVal(){
			return val; 
		}
		void setNext(Node* a){
			next=a;
		}
		Node* getNext(){
			return next;
		}
};

class linkedList{
	private:
		Node* head;
	public:
		linkedList(){
			head=NULL;
		}
		linkedList(Node* n){
			head=n;
		}
		void setHead(Node* h){
			head=h;
		}
		Node* getHead(){
			return head;
		}
		void addNodeBeg(Node* newNode){
			if(head == NULL){
				head = newNode;
			}
			else{
				newNode->setNext(head);
				head=newNode;
			}
		}
		void printList(){
			Node* temp = head;
			cout<<"--------------"<<endl;
			while(temp != NULL){
				cout<<temp->getVal()<<endl;
				temp = temp->getNext();
			}
			cout<<"--------------"<<endl;
		}
		
		
		void addNodeEnd(Node* newNode){
			if(head == NULL){
				head = newNode;
			}
			else{
				Node* temp = head;
				while(temp->getNext() != NULL){
					temp = temp->getNext();
				}
				temp->setNext(newNode);
			}
		}
};


int main(){
	int n,val;
	linkedList* ob = new linkedList();
	Node* x;
	while(1){
		cout<<"\n1.Print list"<<endl;
		cout<<"2.Add node at beginning"<<endl;
		cout<<"3.Add node at end"<<endl;
		cout<<"Choose your option: ";
		
		
		cin>>n;
		switch(n){
			case 1:
				ob->printList();
				break;
			case 2:
				cout<<"\nNode value: "<<endl;
				cin>>val;
				x = new Node(val);
				ob->addNodeBeg(x);
				break;
			case 3:
				cout<<"\nNode value: "<<endl;
				cin>>val;
				x = new Node(val);
				ob->addNodeEnd(x);
				break;
		}
	}
	return 0;
}

