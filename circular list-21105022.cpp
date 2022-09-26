
/*[Question.2]  What are the practical applications of a circular linked list? (Try to find applications in your respective fields).
Practical applications of circular linked list are :

Answer : Some of the practical applications of circular linked list are:

1)Audio/Video Streaming: Circular linked list is also used in audio and video streaming,for ex. when one complete audio list finishes
  playing in music player then it again starts playing from start.

2)Computing Resources: Circular Linked Lists is used to manage the computing resources of the computer.

3)Computer Networking:Circular linked list is also used in computer networking for token scheduling.

4)Fibonacci Heap: Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.


5)Implementation of Data Structure: Data structures such as stacks and queues are implemented with the help of the circular linked lists.
6)Multi-player Games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.
*/

/* Q1 we can use do while loop when the temp reaches back to head address it stops the do while loop
and do while loop first do the work and then move to the condition
*/
#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
      int data;
      Node * next;

};

void takeInput(Node *& head,Node*& tail) {
   int daa;
   cin >> daa;
   while (daa != -1) {
      Node * ptr = new Node();
      Node * temp =  head;
      ptr -> next =  head;
      ptr -> data = daa;
      if(head == NULL){
          ptr->next = ptr;
          head = ptr;
          tail = ptr;
      }else{
          tail->next = ptr;
          tail = ptr;
      }
      cin >> daa;
   }
}

void deleteNode(Node*& head, int key) {
    if (head == NULL) return;

    if(head->data==key && head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }

    Node *last=head,*d;
    if(head->data==key){
        while(last->next!=head) last=last->next;
        last->next=(head)->next;
        free(head);
        head=last->next;
        return;
    }
    while(last->next!=head&&last->next->data!=key)  last=last->next;

    if(last->next->data==key) {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else cout<<"no such keyfound";
}


void dis(Node * head) {
   Node * temp = head;
   if (head != NULL) {
      do {
         cout << temp -> data << " ";
         temp = temp -> next;
      }
      while (temp != head);
      cout << endl;
   }

}

int main() {
   Node * head = NULL;
   Node * tail = NULL;
   takeInput(head,tail);
   cout << "Display of Circular queue: ";
   dis(head);
   deleteNode(head,74);
   deleteNode(head,1);
   deleteNode(head,6);
   cout << "Display of Circular queue: ";
   dis(head);
}
