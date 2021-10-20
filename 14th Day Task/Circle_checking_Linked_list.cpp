/* Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.



Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;

    }
};
void insertAtTail(node* &head, int val){
            node* n= new node(val);
            node* temp=head;

            if(head==NULL){
                head=n;
                return;
            }
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next =n;
}
void makeCycle(node* &head, int pos){
        node* temp =head;
        node* startNode;

        int count=1;
        while(temp->next!=NULL){
            if(count==pos){
                startNode=temp;
            }
            temp=temp->next;
            count++;
        }
        temp->next=startNode;
}
bool detectCycle(node* &head){
        node* slow=head;
        node* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow){
                return true;
            }
        }
        return false;
}
void display(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
}
int main(){
        int pos;
        node* head=NULL;
        insertAtTail(head, 3);
        insertAtTail(head, 2);
        insertAtTail(head, 0);
        insertAtTail(head, -4);
        cout<<"Linked List is: \n";
        display(head);
        cout<<"Enter the postion: ";
        cin>>pos;
        makeCycle(head,pos);
        cout<<detectCycle(head);


 return 0;
}
