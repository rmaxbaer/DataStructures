#pragma once
#include <string>
#include <sstream>
#include <iostream>

#include "LinkedListInterface.h"
using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
	
	
	
  struct Node {
    T value;
    Node* next = NULL; // This is a pointer of type Node because it points to the next node
    
    Node(T newValue){
        value = newValue;
    }
    Node(T newValue, Node* newNode){
        value = newValue;
        next = newNode;
    }
  };
  
  Node* head = NULL; // a Node is an object that has a value and a pointer
  int listSize = 0;

public:
	LinkedList(){};
	~LinkedList(){
		clear();
	}; // destructor

	//LinkedListInterface(void) {};
	//virtual ~LinkedListInterface(void) {};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value){
		//cout << "running head" << endl;
		//cout << "value: " << value << endl;
		//cout << "new" << endl;
		if(head == NULL){ //If there is no head...
		//	cout << "head head" << endl;
			Node* newNode = new Node(value); // add a new Node with a value; it's pointer should be null
			head = newNode; // set head to the new head node
			listSize = listSize + 1;
		//	cout << "we inserted new head: " << value << endl;
			//cout << "listSize: " << listSize << endl;
			cout << "new head: " << head->value << endl;
		}else { // if there is a head...
		//	cout << "head second" << endl;
			// don't allow duplicates
			if(!find(value)){
		//		cout << "head second not duplicate" << endl;
		//		cout << "we inserted value: " << value << " at head" << endl;
				Node* newNode = new Node(value, head); // add the new node and have it point to the current head
				head = newNode; // set head to the new head node
				listSize = listSize + 1;
			}
		}	  
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value){
		//cout << "running tal" << endl;
		if(head == NULL){ //If there is no head...
		//	cout << "tail head" << endl;
			insertHead(value);
		}else { // if there is a head...
			//don't allow duplicates
		if(!find(value)){
			Node* newNode = new Node(value); // add the new node and have it point to NULL
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next; // set the temp pointer to the next element until next is null
			}
			temp->next = newNode; // set the pointer of the last value to point to the new tail 
			listSize = listSize + 1;
			}
		}	  
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode){
		//cout << "running after" << endl;
	    if(head == NULL){ //If there is no head...
	    //	cout << "after head" << endl;
	        insertHead(value);
	    }else { // if there is a head...
	        //don't allow duplicates
	        if(!find(value)){ // if there is a value to insert after..
				if(find(insertionNode)){ // Only attempt to insert it after if the insertNode exists
				//Insert node
				Node* temp = head;
				while(temp->value != insertionNode){
				  temp = temp->next; 
				}
				Node* newNode = new Node(value, temp->next); // make a new node with the given value; have it point to the Node after our Temp(our insertionNode)
				temp->next = newNode; //Point the node before our new Node to our new Node
				listSize = listSize + 1;
				}else{
		//		cout << "Insertion Node not found.  Nothing inserted" << endl;
	          }
	        }
	    }	  
	  
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value){
	//	cout << "run remove on: " << value << endl << endl;
		if(!find(value)){ // first check if the value is in our list
			//cout << "error: can't find/remove value" << endl; 
		}else{
			if(value == (head->value)){ // check if we are removing the head
	//			cout << "remove head" << endl;	
				Node* temp = head;
				head = head->next;
				delete temp;
				temp = NULL;
				listSize = listSize - 1;
			}else{ // if we are not removing the head...
	//			cout << "remove other" << endl;
				Node* temp2 = head;
				while(temp2->next->value != value){
					temp2 = temp2->next;
				}
				Node* temp3 = temp2->next;
				temp2->next = temp3->next;
				delete temp3;
				temp3 = NULL;
				listSize = listSize - 1;
			}
		}
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear(){
	//	cout << "run clear on list of size: " << listSize << endl << endl;
		while(listSize != 0){ // if empty, head should = null
	//		cout <<"head not eq null" << endl;
	//		cout << "removing " << head->value << " ... ";
			remove(head->value);
	//		cout << "removed" << endl;
		}
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index){
		/*
		
		catch(string myError){
			//cout << "it is " << myError << endl;
			cout << myError;
		}
		*/
		if((index < 0) || (index > (listSize - 1)) ){ //or just listSize?
		//	cout << index << " is out_of_range: 0-" << (listSize - 1) << endl; // are we to use try catch here? or do I print to the file?
			throw std::out_of_range("Error");
		} 
		if((index > -1) && (index <= (listSize - 1))) {
		//	cout << "listSize: " << listSize << " Index: " << index << endl;
			Node* temp = head;
			for(int i = 0; i < index; ++i){
				temp = temp->next;
			}
			return temp->value;
		}
	  
	}


	int size(){
	//	cout << "run size " << listSize << endl << endl;
		return listSize;
	}


	string toString(){
	//	cout << "run print" << endl;
		Node* temp = head;
		stringstream ss;
		for(int i = 0; i < listSize; ++i){
			ss << temp->value;
			if(i < (listSize - 1)){
				ss << " ";
			}
			temp = temp->next;
		}
		if(listSize > 0){
			return ss.str();
		}else{
			return "";
		}
	}
	
	
	bool find(T findValue){
		//cout << "run find" << endl;	
		//cout << "list Size: " << listSize << endl;
		if((head == NULL) ||(listSize <= 0)){
			return false;
		}
		Node* temp = head;
		//cout << "find 2" << endl;
		if(temp->value == findValue){ //check if the head value holds the value we are searching for
			//cout << "find 3 true" << endl;
			return true;
		}
		//cout << "find 4 " << endl;
		int i = 0;
		//cout << toString() << endl; // this prints my current list
		//cout << temp-> next << endl; // this should be null; am I not deleting things correctly
		while((temp->next) != NULL){ // check the middle elements
		//	cout << "find 5" << endl;
			temp = temp->next;
			//cout << "find 5b" << endl;
			
			//cout << "find 5c" << temp->value << endl;// so temp->value is null somehow
			
			if(temp->value == findValue){
			//	cout << "find 6" << endl;
				return true;
			}
			//cout << "find 6b" << endl;
			i = i + 1;
			if(i > 290){
				cout << endl << endl << "HIT 60 " << endl << endl;
				return false;
			}
		}
		//cout << "find 7" << endl;
		return false;
	}
	
};
