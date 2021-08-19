#include<iostream>
#include<math.h>
using namespace std;
class Node{
	int exp, coeff;
	Node* next;
	friend class LinkedList;
};
class LinkedList{
public:
	Node* head;
	int x;
	LinkedList(){
		head=NULL;
	}
	LinkedList(Node* n){
		head=n;
	}

void create(){
	int e,c;
	Node* next;
	Node* temp;
	int n;
	cout<<"Enter the number of terms in polynomial"<<endl;
	cin>>n;
	cout<<"enter coefficient"<<endl;
	cin>>c;
	cout<<"enter exponent"<<endl;
	cin>>e;
	temp= new Node;
	temp->coeff=c;
	temp->exp=e;
	temp->next=NULL;
	head=temp;
	for(int i=0; i<n-1; i++){
		cout<<"enter coeff"<<endl;
		cin>>c;
		cout<<"enter exponent"<<endl;
		cin>>e;
		temp->next= new Node;
		temp=temp->next;
		temp->coeff=c;
		temp->exp=e;
		temp->next=NULL;
	}
	cout<<"enter the value of x"<<endl;
	cin>>x;
}

void display(){
	cout<<"the polynomial is: "<<endl;
	Node* temp=head;
	while(temp->next!=NULL){
		cout<<temp->coeff<<"x^"<<temp->exp<<" + ";
		temp=temp->next;
	}
	cout<<temp->coeff<<"x^"<<temp->exp<<endl;
}

void eval_poly(){
	int res=0;
	Node* temp=head;
	while(temp!=NULL){
		res+=temp->coeff*pow(x,temp->exp);
		temp=temp->next;
	}
	cout<<"\n result:"<<res<<endl;
}
};

int main(){
	LinkedList eval;
	eval.create();
	eval.display();
	eval.eval_poly();
	return 0;
}
