/*
 * Roll no.- 2459
 * Name- Sharvari Sonkusare
 * CNumber- C22019221458
 * Assignment number- 2
 *
 * Problem statement -
 * Department of Computer Engineering has &#39;CSI student branch&#39;. Students
of second, third and final year can subscribe to membership. Design a
system to maintain CSI student branch membership information. Choose
appropriate data structure. Write a program using C++ for following
operations:
 Add new members.
 Compute total number of members at branch.
 Display member information.
 Remove member details.
*/



#include <iostream>
using namespace std;

class node{          //node class
public:
	int Roll,Year;
	string Name;
	node *next;

	node(){
		next=NULL;
	}

	node(string name,int rn,int year)    //initialize all variables
	{
     Roll=rn;
     Year=year;
     Name=name;
     next=NULL;                           //initialize link to Null
    }
    friend class list;
};

class list                                  //class list
{
public:
 int count=0;
 node *head;
 list(){
	 head=NULL;
 }
 list(node *n){
	 head=n;
 }

 void create(node *n)                       //create Linked List
 {
 	 node* ptr=head;
 	if(head==NULL){
 		head=n;
 		cout<<"DATA INSERTED"<<endl;
 		count+=1;
 	}
 	else{

 	 while(ptr->next!=NULL)
 		{
 		ptr= ptr->next;
 		}
 		ptr->next=n;
 		cout<<"DATA ACCEPTED"<<endl;
 		count+=1;

 	}

 }

 void display()                      //display the data
 {
 	if(head==NULL){
 	  cout<<"No Members registered";
 	}
 	else{
 	   cout<<endl<<"MEMBER DATA: ";
 	   node* temp=head;
 	  cout<<"\nROLL NO.\tYEAR \t NAME \n"<<endl;
        while(temp!=NULL){
 	   cout<<"\n"<<temp->Roll<<"\t\t"<<temp->Year<<"\t "<<temp->Name<<endl;
 	   temp= temp->next;
 		}
 	}
 }

 void member_info(int rn)                      //display the data of particular member
 {
	 node* temp=head;
	 while(temp->Roll!=rn){
		 temp=temp->next;
	 }
	 if(temp->Roll==rn){
	 cout<<endl<<"MEMBER DATA: ";
 	 cout<<"\nROLL NO.\tYEAR \t NAME \n"<<endl;
 	 cout<<"\n"<<temp->Roll<<"\t\t"<<temp->Year<<"\t "<<temp->Name<<endl;
	 }
	 else{
		 cout<<"MEMBER WITH GIVEN ROLL NUMBER DOESN'T EXIST"<<endl;
	 }

 }




 void total(){
 	cout<<"THE TOTAL NUMBER OF MEMBERS PRESENT ARE:"<<count<<endl;
 }

 void insert(node *n)                       //insert new node at particular position
 {
 	node* ptr= head;
 	int p;
 	cout<<"Enter the position where you want to insert data";
 	cin>>p;
 	if(p==1){
 		n->next=head;
 		head=n;
 		cout<<"DATA INSERTED"<<endl;
 		count+=1;
 	}
 	else{
 		for(int i=1; i<p-1; i++){
 			ptr=ptr->next;
 		}
 		n->next=ptr->next;
 		ptr->next=n;
 		cout<<"DATA INSERTED"<<endl;
 		count+=1;
 	}


 }

 void del(int rn)                              //delete the node of given Roll no
 {
 	if(head==NULL){
 			cout<<"NO DATA PRESENT"<<endl;

 		}
 	else if(head!=NULL){
 		if(head->Roll==rn){                 //here if we want to delete the first node.
 				head=head->next;
 				cout<<"DATA ENTRY REMOVED"<<endl;
 				count= count-1;
 			}

 	    else{                                  //deleting any other random node.
 			node *temp=NULL;
 			node *prevptr=head;
 			node *curptr=head->next;
 			while(curptr!=NULL){
 				if(curptr->Roll==rn){
 					temp=curptr;
 					curptr=NULL;
 				}
 				else{
 					prevptr=prevptr->next;
 					curptr=curptr->next;

 				}
 			}
 			if(temp!=NULL){
 				prevptr->next=temp->next;
 				cout<<"DATA ENTRY REMOVED"<<endl;
 				count= count-1;
 			}
 	       else{
 		      cout<<"\nMEMBER DOESN'T EXIST WITH GIVEN ROLL NUMBER"<<endl;
 			}

 		}
 	}

 }




};

int main(){
	list l;                                     //object of list class
	int ch,rn,yr;
	string N;

	do{

		cout<<"\nMENU \n1.CREATE MEMBERSHIP \n2. INSERT MEMBER \n3. DISPLAY DATA \n4. DISPLAY REQUIRED MEMBER DATA \n5.DELETE MEMBER DATA \n6. TOTAL NUMBER OF MEMBERS \n7.EXIT"<<endl;
        cout<<"Enter a choice";
        cin>>ch;
        node* n1= new node();
        switch(ch){
        case 1:
	        cout<<"Enter Roll no., Year and Name of the member: "<<endl;
	   		cin>>rn;
  			cin>>yr;
	    	cin>>N;
	   		n1->Roll= rn;
	    	n1->Name=N;
	    	n1->Year= yr;
	    	l.create(n1);
	    	break;
        case 2:
        	cout<<"Enter Roll no., year and name of the member: "<<endl;
            cin>>rn;
  			cin>>yr;
			cin>>N;
        	n1->Roll= rn;
        	n1->Name=N;
            n1->Year= yr;
        	l.insert(n1);
        	break;
        case 3:
       	 l.display();
       	 break;
        case 4:
        	cout<<"\nEnter the roll number of member whose data is required: "<<endl;
        	cin>>rn;
        	l.member_info(rn);
        	break;
        case 5:
        	cout<<"enter the roll number of member which u want to remove"<<endl;
            cin>>rn;
            l.del(rn);
            break;
        case 6:
        	l.total();
        	break;
        case 7:
        	cout<<"EXIT"<<endl;
        }
	}while(ch!=7);

}



/* OUTPUT
  SAMPLE OUTPUT:

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice1
Enter Roll no., Year and Name of the member:
1
2018
Sid
DATA INSERTED

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice1
Enter Roll no., Year and Name of the member:
2
2019
Ryo
DATA ACCEPTED

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice2
Enter Roll no., year and name of the member:
3
2020
Kiya
Enter the position where you want to insert data2
DATA INSERTED

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice3

MEMBER DATA:
ROLL NO.	YEAR 	 NAME


1		2018	 Sid

3		2020	 Kiya

2		2019	 Ryo

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice4

Enter the roll number of member whose data is required:
1

MEMBER DATA:
ROLL NO.	YEAR 	 NAME


1		2018	 Sid

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice6
THE TOTAL NUMBER OF MEMBERS PRESENT ARE:3

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice5
enter the roll number of member which u want to remove
2
DATA ENTRY REMOVED

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice3

MEMBER DATA:
ROLL NO.	YEAR 	 NAME


1		2018	 Sid

3		2020	 Kiya

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice6
THE TOTAL NUMBER OF MEMBERS PRESENT ARE:2

MENU
1.CREATE MEMBERSHIP
2. INSERT MEMBER
3. DISPLAY DATA
4. DISPLAY REQUIRED MEMBER DATA
5.DELETE MEMBER DATA
6. TOTAL NUMBER OF MEMBERS
7.EXIT
Enter a choice7
EXIT

TIME COMPLEXITIES:

1.CREATE=O(N)
2.DISPLAY=O(N)
3.TOTAL=O(1)
4.MEMBER INFO=O(N)
5.INSERT=O(N)
6. DELETE=O(N)

 */











