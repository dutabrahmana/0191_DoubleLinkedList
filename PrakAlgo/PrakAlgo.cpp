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
			previous = current;
			current = current->next;
		}

		newNode->next = current;
		newNode->prev = previous;

		if (current != NULL) {
			current->prev = newNode;

		}
		if (previous != NULL) {
			previous->next = newNode;
		}
		else {

			START = newNode;
		}
	}

}
bool search(int rollNo, Node** previous, Node** current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;                                                                  //step 3get the roll number to be deleted

    if (START == NULL)
    {
        cout << "List is empety" << endl;
        return;
    }

    current = START;                                                               //step 1:start from the first node
    previous = NULL;

    //locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
        return;
    }

    //Node to be deleted is the firts node
    if (current == START)
    {
        START = START->next;                                            //step 2:update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;                                         //step
        }
    }
    else
    {   //Node to be deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        {   //if there's successor, update is prev pointer
            current->next->prev = previous;
        }
    }

    //release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

bool listempety()
{
    return (START == NULL);
}

void traverse()
{
    if (listempety())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecord is ascending order of roll number are:  " << endl;
        Node* currentNode = START;              //step 1
        while (currentNode != NULL)             //step 2
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;         //step 3
            currentNode = currentNode->next;                                        //step 4
        }
    }
}

void revtraverse()
{
    if (listempety())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecord is descending order of roll number are:  " << endl;
        Node* currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

void searchData()
{
    if (listempety() == true)
    {
        cout << "\nList is empty" << endl;
    }
    Node* prev, * curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
} }
}

