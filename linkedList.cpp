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
				cout<<temp->getVal()<<" -> ";
				temp = temp->getNext();
			}
			cout<<"\n--------------"<<endl;
		}
		
		void reversePrint(Node *head){
			if(head==NULL) return;
			reversePrint(head->getNext());
			cout<<head->getVal()<<" -> ";
		}
		
		void printListRec(Node *h){
			if(h==NULL)return;
			cout<<h->getVal()<<" -> ";
			printListRec(h->getNext());
		}
		
		Node* addAtEndRec(Node *h,Node* newNode ){
			if(head == NULL)  head = newNode;
			if(h==NULL) return newNode;
			h->setNext(addAtEndRec(h->getNext(), newNode));
		}
		
		void SumAllElementsRec(Node* h){
			
		}
		
		int searchElement(int n){
			Node* temp = head;
			if(temp == NULL) cout<<"Linked list is empty."<<endl;
			while(temp != NULL){
				if(temp->getVal() == n){
					cout<<"Value available in linked list."<<endl;
					return 0;
				}
				temp = temp->getNext();
			}
			cout<<"Value not available in linked list"<<endl;
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
		cout<<"4.Print reverse of linked list"<<endl;
		cout<<"5.Add mode at end using recursion"<<endl;
		cout<<"6.Search value"<<endl;
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
			case 4:
				ob->reversePrint(ob->getHead());
				break;
			case 5:
				cout<<"\nNode value: "<<endl;
				cin>>val;
				x = new Node(val);
				ob->addAtEndRec(ob->getHead(), x);
				break;
			case 6:
				cout<<"\nEnter value to search: "<<endl;
				cin>>val;
				ob->searchElement(val);
				break;
			default:
				return 0;
		}
	}
	return 0;
}

