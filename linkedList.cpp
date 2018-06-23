#include<iostream>
#include <stdlib.h>
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
		
		void addNodePosi(Node* newNode, int p){
			Node* temp1 = head;
			Node* temp2 = head;
			for(int i=1;i<=p;i++){
				if(temp1 == NULL) break;
				temp2 = temp1;
				temp1 = temp1->getNext();
			}
			if(temp1 == NULL && temp2 == NULL){
				head = newNode;
			}
			else if(temp1 == NULL && temp2 != NULL){
				temp2->setNext(newNode);
			}
			else{
				temp2->setNext(newNode);
				newNode->setNext(temp1);
			}
		}
		void Delete(int n){
			Node* temp1 = head;
			Node* temp2 = head;
			for(int i=1;i<n;i++){
				if(temp1 == NULL) break;
				temp2 = temp1;
				temp1 = temp1->getNext();
			}
			if(temp1 == NULL) return;
			else if(n == 1){
				head = temp1->getNext();
				//free(temp1);
			}
			else{
				temp2->setNext(temp1->getNext());
			}
		}
		
		void printList(){
			Node* temp = head;
			if(temp == NULL){
				cout<<"\nList is empty."<<endl;
				return;
			}
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
		
		int SumAllElementsRec(Node* h){
			if(h == NULL) return 0;
			return h->getVal() + SumAllElementsRec(h->getNext());
		}
		
		int searchElement(int n){
			Node* temp = head;
			if(temp == NULL) {
				cout<<"\nLinked list is empty."<<endl;
				return 0;
			}
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
		void findMiddleElement(){
			Node* fast_ptr = head;
			Node* slow_ptr = head;
			if(head == NULL) return;
			while(fast_ptr != NULL && fast_ptr->getNext() != NULL){
				fast_ptr = fast_ptr->getNext()->getNext();
				slow_ptr = slow_ptr->getNext();
			}
			cout<<"\nMiddle element of the list is  "<<slow_ptr->getVal()<<endl;
		}
		
		void findNthFromEnd(int n){
			if(head == NULL) {
				cout<<"\nLinked list is empty."<<endl;
				return;
			}
			Node* main_ptr = head;
			Node* temp_ptr = head;
			int c=0;
			while(c<n){
				temp_ptr = temp_ptr->getNext();
				c++;
			}
			while(temp_ptr != NULL){
				main_ptr = main_ptr->getNext();
				temp_ptr = temp_ptr->getNext();
			}
			cout<<"\nValue at "<<n<<" position from end is "<<main_ptr->getVal()<<endl;
		}
};


int main(){
	int n,val,p;
	linkedList* ob = new linkedList();
	Node* x;
	while(1){
		cout<<"\n1.Print list"<<endl;
		cout<<"2.Add node at beginning"<<endl;
		cout<<"3.Add node at end"<<endl;
		cout<<"4.Print reverse of linked list"<<endl;
		cout<<"5.Add node at end using recursion"<<endl;
		cout<<"6.Search value"<<endl;
		cout<<"7.Sum of linked list"<<endl;
		cout<<"8.Add node at posotion"<<endl;
		cout<<"9.Delete node at position"<<endl;
		cout<<"10.Middle element of the list"<<endl;
		cout<<"11.Find value at Nth position from the end"<<endl;
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
			case 7:
				val=ob->SumAllElementsRec(ob->getHead());
				cout<<"\nSum of list is: "<<val<<endl;
				break;
			case 8:
				cout<<"\nNode value: "<<endl;
				cin>>val;
				cout<<"\nEnter position to enter: "<<endl;
				cin>>p;
				x = new Node(val);
				ob->addNodePosi(x, p);
				break;
			case 9:
				cout<<"\nEnter position to delete value: "<<endl;
				cin>>p;
				ob->Delete(p);
				break;
			case 10:
				ob->findMiddleElement();
				break;
			case 11:
				cout<<"\nEnter the position from end: ";
				cin>>val;
				ob->findNthFromEnd(val);
				break;
			default:
				return 0;
		}
	}
	return 0;
}

