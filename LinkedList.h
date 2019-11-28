#pragma once
#include <string>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct Node {
		T data;
		Node* next;
		Node(const T& the_data, Node* next_val = NULL) :
			data(the_data) {next = next_val;}
	};
	
	Node *mylist;
	int num_items;

public:

	LinkedList(void) {
	    mylist = NULL;
		num_items = 0;
		cout << "In constructor"<<endl;
	};
	~LinkedList(void) {
	    cout << "In destructor"<<endl;
		clear();
	};
	
/*
insertHead

A node with the given value should be inserted at the beginning of the list.

Do not allow duplicate values in the list.
*/
	void insertHead(T value) {
	    cout << "In insertHead" << endl;
	    if (!find(value)) {
	        Node *newnode = new Node(value, NULL);
	        newnode->next = mylist;
	        mylist = newnode;
	        num_items++;
	    }
	};

/*
insertTail

A node with the given value should be inserted at the end of the list.

Do not allow duplicate values in the list.
*/
	void insertTail(T value) {
	    cout << "In insertTail" << endl;
	    if (!find(value)) {
    	    Node *ptr = mylist;
    		if (mylist == NULL) {
    			mylist = new Node(value, NULL);
    		}
    		else {
    			while (ptr != NULL) {
    				cout << ptr << ", data: " << ptr->data << ", next: " << ptr ->next << endl;
    				if (ptr->next == NULL) {
    					ptr->next = new Node(value, NULL);
    					break;
    				}
    				else {
    					ptr = ptr->next;
    				}
    			}
    		}
    		num_items++;
	    }
	};

/*
insertAfter

A node with the given value should be inserted immediately after the
node whose value is equal to insertionNode.

A node should only be added if the node whose value is equal to
insertionNode is in the list. Do not allow duplicate values in the list.
*/
	void insertAfter(T value, T insertionNode) {
	    cout << "In insertAfter"<< endl;
	    if (!find(value) && find(insertionNode)) {
	        cout << "Value: " << value << ", InsertionNode: " << insertionNode << endl;
	        Node *newnode = new Node(value, NULL);
			Node *ptr = mylist;
			
			while (ptr->next != NULL) {
			    if (ptr->data == insertionNode) {
			        newnode->next = ptr->next;
					ptr->next = newnode;
					num_items++;
					cout << "finished inserting " << value << endl;
				    break;
			    }
			    else ptr = ptr->next;
			}
	    }
	};

/*
remove

The node with the given value should be removed from the list.

The list may or may not include a node with the given value.
*/
	void remove(T value) {
	    cout << "In remove"<<endl;
	    if (find(value)) {
    	    Node *ptr = mylist;
    	    for (int i = 0; i < num_items; ++i) {
    	        if (i == 0 && ptr->data == value) {
        			Node *current = mylist;
        			mylist = mylist->next;
        			delete current;
        			num_items--;
        		}
        		else if (ptr->next->data == value) {
        		    Node *current = ptr->next;
					ptr->next = ptr->next->next;
					delete current;
					num_items--;
        		}
        		else {
					ptr = ptr->next;
        		}	
        	}
        }
	};

/*
clear

Remove all nodes from the list.
*/
	void clear() {
	    while (mylist != NULL) {
			Node *current = mylist;
			mylist = mylist->next;
			delete current;
		};
	};

/*
at

Returns the value of the node at the given index. The list begins at
index 0.

If the given index is out of range of the list, throw an out of range exception.
*/
	T at(int index) {
	    cout << "In at"<<endl;
		if(index >= num_items || index < 0) {
			throw std::out_of_range("At Error");
		} else {
			Node *ptr = mylist;
			for (int i = 0; i <= index; i++) {
				cout << "[" << i << "]" << ptr->data << endl;
				if (i == index) {
					return (ptr->data);
				}
				else {
					ptr = ptr->next;
				}
			}
		}
	};

/*
size

Returns the number of nodes in the list.
*/
	int size() {
	    cout << "In size"<<endl; 
		return(num_items);
	};

/*
toString

Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
There should be no trailing space at the end of the string

For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
"1 2 3 4 5"
*/
	string toString() {
	    ostringstream ss;
	    for (Node *ptr = mylist; ptr != NULL; ptr = ptr->next) {
			ss << ptr->data;
			if (ptr->next != NULL) {
			    ss << " ";
			}
		}
		return ss.str();
	};

	bool find(T value) {
	    if (mylist == NULL) {
	        return false;
	    }
	    else {
    	    Node *ptr = mylist;
    	    for (int i = 0; i < num_items; ++i) {
    	        if (ptr->data == value) {
    	            return true;
    	        }
    	        else {
    	            ptr = ptr->next;
    	        }
    	    }
    	    return false;
    	}
	};

};
