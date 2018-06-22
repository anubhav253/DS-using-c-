#include<iostream>

using namespace std;

class Node{
	private:
		int val;
		Node* next;
		Node* prev;
	public:
		Node(int v){
			val=v;
			next=NULL;
			prev=NULL;
		}	
		void setVal(int v){
			val=v;
		}
		int getVal(){
			return val;
		}
		void setNext(Node* n){
			next=n;
		}
		Node* getNext(){
			return next;
		}
		void setPrev(Node* p){
			prev=p;
		}
		Node* getPrev(){
			return prev;
		}
};

class doublyLinkedList{
	private:
		Node* head;
	public:
		doublyLinkedList(){
				head=NULL;
		}
		doublyLinkedList(Node* n){
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
				return;
			}
			head->setPrev(newNode);
			newNode->setNext(head);
			head=newNode;
		}
		void addNodeEnd(Node* newNode){
			if(head == NULL){
				head = newNode;
				return;
			}
			Node* temp = head;
			while(temp->getNext() != NULL){
				temp = temp->getNext();
			}
			temp->setNext(newNode);
			newNode->setPrev(temp);
		}
		void printList(){
			Node *temp = head;
			cout<<"--------------"<<endl;
			while(temp != NULL){
				cout<<temp->getVal()<<" -> ";
				temp = temp->getNext();
			}
			cout<<"\n--------------"<<endl;
		}
};

int main(){
	int n, val;
	doublyLinkedList* ob = new doublyLinkedList();
	Node* x;
	
	while(1){
		cout<<"1.Print list"<<endl;
		cout<<"2.Add node at beginning"<<endl;
		cout<<"3.Add node at end"<<endl;
		cout<<"Enter your choice: ";
		
		cin>>n;
		switch(n){
			case 1:
				ob->printList();
				break;
			case 2:
				cout<<"\nEnter node value: ";
				cin>>val;
				x = new Node(val);
				ob->addNodeBeg(x);
				break;
			case 3:
				cout<<"\nEnter node value: ";
				cin>>val;
				x = new Node(val);
				ob->addNodeEnd(x);
				break;
			default:
				return 0;
		}
			
	}
	
	
	return 0;
}
