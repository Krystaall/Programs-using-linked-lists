#include<iostream>
#include<queue>
using namespace std;


class Node{
public:
	int data;
	Node* next;
	Node(int d){
		data=d;
		next=NULL;
	}
	Node(){

	}
};
class Queue{
public:
Node* front;
Node* rear;
Node* temp;
int c;
int max;


Queue(){

	front=NULL;
	rear=NULL;
	c=0;

}
int isEmpty();
void dequeue();
void enqueue(int max);
void display();
int count();

};

int Queue::isEmpty(){
	if(rear==NULL && front==NULL){
		return(1);
	}
	else{
			return(0);
		}
	}

void Queue::enqueue(int x)
  {

      Node* temp = new Node(x);

      // If queue is empty
      if (rear == NULL) {
          front = rear = temp;
          cout<<"DATA INSERTED"<<endl;
          c=c+1;
          return;
      }

      // Adding the new node at the end
      rear->next = temp;
      rear = temp;
      cout<<"DATA INSERTED"<<endl;
      c=c+1;
  }

void Queue:: dequeue()
    {
        // for empty queue
        if (front == NULL){
        	cout<<"Queue is empty";
            return;
        }


        // move front one node ahead and then delete previous front
        Node* temp = front;
        front = front->next;
        cout<<"DATA REMOVED"<<endl;
        c=c-1;

        // If front becomes NULL, then change rear also as NULL
        if (front == NULL){
            rear = NULL;
        }

        delete (temp);
    }

void Queue::display(){
	Node* temp = new Node();
	temp = front;
	   if ((front == NULL) && (rear == NULL)) {
	      cout<<"Queue is empty"<<endl;

	      return;
	   }
	   cout<<"Queue elements are: ";
	      while (temp != NULL) {     //traverse the queue to display all elements
	         cout<<temp->data<<" ";
	         temp = temp->next;

	      }
	      cout<<endl;
}
int Queue::count(){
	return c;
}

int main(){

	Queue q;
	int ch,max,x;
	   cout<<"Enter the maximum number of values that queue can hold"<<endl;
	   cin>>max;

	   do {
		   cout<<"1) Insert element to queue"<<endl;
		   cout<<"2) Delete element from queue"<<endl;
     	   cout<<"3) Display all the elements of queue"<<endl;
     	   cout<<"4) Count number of elements"<<endl;
		   cout<<"5) Exit"<<endl;
	      cout<<"Enter your choice : "<<endl;
	      cin>>ch;
	      int k;
	      switch (ch) {
	         case 1:
	        	 cout<<"enter the value to be inserted"<<endl;
	        	 cin>>x;
	        	 q.enqueue(x);
	         break;
	         case 2: q.dequeue();
	         break;
	         case 3: q.display();
	         break;
	         case 4: k=q.count();
	         cout<<k<<endl;
	         break;
	         case 5:
	        	 q.waitList();
	         break;
	         case 6: cout<<"Exit"<<endl;
	         break;
	         default: cout<<"Invalid choice"<<endl;
	      }
	   } while(ch!=5);
	   return 0;

}





