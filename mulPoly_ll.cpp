//runs perfectly.
#include <iostream>
using namespace std;

struct Node {
	int coeff, power;
	Node* next;
};

// Function add a new node at the end of list
Node* addnode(Node* start, int coeff, int power)
{
	// Create a new node
	Node* newnode = new Node;
	newnode->coeff = coeff;
	newnode->power = power;
	newnode->next = NULL;

	// If linked list is empty
	if (start == NULL)
		return newnode;

	// If linked list has nodes
	Node* ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = newnode;

	return start;
}

// Function To Display The Linked list
void printList(struct Node* ptr)
{
	while (ptr->next != NULL) {
		cout << ptr->coeff << "x^" << ptr->power ;
	if( ptr->next!=NULL && ptr->next->coeff >=0)
		cout << "+";

		ptr = ptr->next;
	}
	cout << ptr->coeff << "\n";
}

// Function to add coefficients of
// two elements having same power
void removeDuplicates(Node* start)
{
	Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	// Pick elements one by one
	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;

		// Compare the picked element
		// with rest of the elements
		while (ptr2->next != NULL) {

			// If power of two elements are same
			if (ptr1->power == ptr2->next->power) {

				// Add their coefficients and put it in 1st element
				ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;

				// remove the 2nd element
				delete (dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

// Function two Multiply two polynomial Numbers
Node* multiply(Node* poly1, Node* poly2,
			Node* poly3)
{

	// Create two pointer and store the
	// address of 1st and 2nd polynomials
	Node *ptr1, *ptr2;
	ptr1 = poly1;
	ptr2 = poly2;
	while (ptr1 != NULL) {
		while (ptr2 != NULL) {
			int coeff, power;

			// Multiply the coefficient of both
			// polynomials and store it in coeff
			coeff = ptr1->coeff * ptr2->coeff;

			// Add the powerer of both polynomials
			// and store it in power
			power = ptr1->power + ptr2->power;

			// Invoke addnode function to create
			// a newnode by passing three parameters
			poly3 = addnode(poly3, coeff, power);

			// move the pointer of 2nd polynomial
			// two get its next term
			ptr2 = ptr2->next;
		}

		// Move the 2nd pointer to the
		// starting point of 2nd polynomial
		ptr2 = poly2;

		// move the pointer of 1st polynomial
		ptr1 = ptr1->next;
	}

	// this function will be invoke to add
	// the coefficient of the elements
	// having same power from the resultant linked list
	removeDuplicates(poly3);
	return poly3;
}

// Driver Code
int main()
{
	int t1, t2,c,p;

	Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;


	cout<<"Enter the number of terms in polynomial 1"<<endl;
	cin>>t1;
	for(int i=0; i<t1;i++){
		cout<<"enter coefficient and power respectively";
		cin>>c;
		cin>>p;
		poly1 = addnode(poly1, c, p);
	}
	cout<<"Enter the number of terms in polynomial 2"<<endl;
		cin>>t2;
	for(int i=0; i<t2;i++){
			cout<<"enter coefficient and power respectively";
			cin>>c;
			cin>>p;
			poly2 = addnode(poly2, c, p);
		}


	// Displaying 1st polynomial
	cout << "1st Polynomial:- ";
	printList(poly1);

	// Displaying 2nd polynomial
	cout << "2nd Polynomial:- ";
	printList(poly2);

	// calling multiply function
	poly3 = multiply(poly1, poly2, poly3);

	// Displaying Resultant Polynomial
	cout << "Resultant Polynomial:- ";
	printList(poly3);

	return 0;
}
