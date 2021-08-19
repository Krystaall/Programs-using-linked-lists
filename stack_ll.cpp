#include<iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;

	Node(){
		val=0;
		next= NULL;
	}
	Node(int v){
		val=v;
	}
};
class stack_ll{
public:
	Node* top;
	int c=0;
	stack_ll(){
		top= NULL;
	}


bool isEmpty(){
	if(top==NULL){
		return true;
	}
	else{
		return false;
	}
}


void push(int v){
	Node* temp= new Node();
	temp->val= v;
	temp->next= top;
	top=temp;
	c+=1;
	cout<<"value pushed"<<endl;
}

void pop(){
	if(top==NULL){
		cout<<"stack underflow"<<endl;
	}
	else{
		cout<<"the popped element is "<<top->val<<endl;
		top=top->next;
		c=c-1;
	}
}
void display(){
	Node* ptr;
	if(top==NULL){
		cout<<"stack is empty"<<endl;;
	}
	else{
	ptr=top;
	cout<<"the stack elements are: "<<endl;
	while(ptr!= NULL){
		cout<<ptr->val<<" "<<endl;
		ptr=ptr->next;
	}
	}
}
int count(){
	return c;
}


};

int main(){
	stack_ll s;
	int d, ch;
	do{
		cout<<"enter a choice. Enter 0 if u want to exit"<<endl;
		cout<<"1.isEmpty"<<endl;
		cout<<"2.push"<<endl;
		cout<<"3.pop"<<endl;
		cout<<"4.display"<<endl;
		cout<<"5.count"<<endl;
		cin>>ch;
		switch(ch){
		case 1: if(s.isEmpty()){
			cout<<"the stack is empty"<<endl;
		}
		else{
			cout<<"stack is not empty"<<endl;
		}
		break;
		case 2: cout<<"enter the value u want to push"<<endl;
		cin>>d;
		s.push(d);
		break;
		case 3:
			s.pop();
			break;
		case 4:
			s.display();
			break;
		case 5:
			cout<<"the count is "<< s.count()<<endl;;
			break;
		default:
			cout<<"enter a valid choice"<<endl;
		}
	}while(ch!=0);
return 0;
}




