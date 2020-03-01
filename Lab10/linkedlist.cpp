#include <iostream>
using namespace std;

#include "function.h"

/* Node Definition:
 *
 * struct Node { 
 *    int data; 
 *    struct Node *next; 
 * };
 *
*/

/*
 * Lab10 Part 1: Implement push and print functions for creating
 * a linked list.
*/
Node* push(Node* head, int new_data) { 
   /*
    * Implement push function to add a new element to the linked list
    *
    * input parameter:   pointer to head of linked list,
    *                    new_data to add to the linked list
    * returns: Return the new head of the linked list after push
    *
    * E.g.  If linked list was 3->2->1->NULL before push  with 
    *       head pointing to 3 and new_data is 4, then after push ,
    *       linked list should be 4->3->2->1->NULL and head should
    *       point to 4.
   */

   // Your implementation here
   
   Node* new_head = new Node();
  
   new_head->data = new_data;
   cout << "Pushing:" << new_data <<endl;
   new_head->next = head;
   return new_head;

}

void print(Node* head) { 
   /*
    * Implement print function to print the entire linked list
    *
    * input parameter:   pointer to head of linked list
    * returns: void
    *
    * E.g.  Print linked list like this: 4->3->2->1->NULL
   */

   // Your implementation here
   Node* currentNode = head;
   if(head != NULL){
   while(currentNode->next != NULL){
	   cout << currentNode ->data << "->" ;
	   currentNode = currentNode ->next;
   }
   
   cout << currentNode ->data << "->" ;
   }
   cout << "NULL" <<endl;

}


/*
 * Lab10 Part 2: Implementing Stack using linked list.
 *                
 * Using previous implemention of push function, add 4 more functions
 * i.e. isEmpty, size, top and pop to complete the implementation of 
 * stack using linked list.
*/
bool isEmpty(Node* head) {
   /*
    * Implement isEmpty function to check if the stack is empty.
    *
    * input parameter:   pointer to head of stack
    * returns: bool i.e. If empty return true else return false
   */

   // Your implementation here
   if(head == NULL)
	return true;
	return false;

}

int size(Node* head) {
   /*
    * Implement size function to get number of elements in stack.
    *
    * input parameter:   pointer to head of stack
    * returns: size of stack. If empty, return 0
   */

   // Your implementation here 
   if(head == NULL)
		return 0;
   int size = 1;
   Node* currentNode = head;
   while(currentNode -> next != NULL){
	   size +=1;
	   currentNode= currentNode->next;
   }
   return size;
  

}

int top(Node* head) {
   /*
    * Implement top function to fetch the top element of stack
    *
    * input parameter:   pointer to head of stack
    * returns: Return the data in top element of the stack
    *
    * E.g.  If stack was 3->2->1->NULL then top should return 3
   */

   // Your implementation here
   return head->data;

}

Node* pop(Node* head) {
   /*
    * Implement pop function to remove the top element of stack
    *
    * input parameter:   pointer to head of stack
    * returns: Return the new head pointer of the stack after pop
    *
    * E.g.  If stack was 4->3->2->1->NULL before pop with 
    *       head pointing to 4, then after pop, stack should
    *       be 3->2->1->NULL with head pointing to 4
   */

   // Your implementation here
	Node* newHead = head->next;
	delete head;
	return newHead;

}


/*
 * Lab10 Part 3: Find the middle element of a linked list
*/
Node* middle_element(Node* head) {
   /* 
    * input parameter:   pointer to head of linked list
    * returns: Return the middle element of linked list
    *
    * E.g. For 4->3->2->1->NULL, return node with value 2. (Even size)
    *      For 5->4->3->2->1->NULL, return node with value 3 (Odd size)
   */

   // Your implementation here
   int sz = size(head);
   if(sz ==1)
		return head;
	//assuming index starts at 0
   int indexOfMiddle = sz/2;
   
   Node* curr = head;
   for(int i =0; i < indexOfMiddle; ++i)
	   curr = curr->next;
   return curr;

   

}

/*
 * Lab10 Part 4: Remove middle node from Linked List
*/
Node* remove_middle_element(Node* head, Node* middle_node) {
   /* 
    * input parameter:   pointer to head of linked list,
    *                    pointer to the node to remove
    * returns: Return the head pointer
    *
    * E.g. For 5->4->3->2->1->NULL, after this operation the
    *      linked list will become 5->4->2->1->NULL
   */

   // Your implementation here
   if(head ==NULL )
	return NULL;
	else if(head->next == NULL){
		delete head;
		return NULL;
	}
	else{
		Node* curr = head;
		while(curr->next!=middle_node){
			cout << curr->data<< endl;
			curr = curr->next;
		}
		curr->next = curr->next->next;
		//delete curr->next;
		return head;
	}
	
	
		

}