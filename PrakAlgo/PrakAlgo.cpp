#include <iostream>
#include <string>
using namespace std;


struct Node {
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

Node* START = NULL;

void addNode() {
	Node* newNode = new Node(); // step1: create a new code
	cout << "\nEnter the roll number of the student: ";
	cin >> newNode->noMhs; // Asign value to the data field of the new node
	cout << "\nEnter the name of the srudent: ";
	cin >> newNode->name;

	// Insert the new node in the list 
	if (START == NULL || newNode->noMhs <= START->noMhs) {
		if (START != NULL && newNode->noMhs == START->noMhs) {
			cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
			return;
			
		}
		// if the list is empty make the new node the START
		newNode->next = START;
		if (START != NULL) {
			START->prev = newNode;

		}
		newNode->prev = NULL;
		START = newNode;
	}
	else {
		Node* current = START; //step 1.a: start from the first node 
		Node* previous = NULL;// step1.b:previous node is NULL intilialyy

		while (current != NULL && current->noMhs < newNode->noMhs) {

		}

	}
	


}

