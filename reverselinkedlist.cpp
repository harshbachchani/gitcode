#include <iostream>
using namespace std;


//program to reverse a linked list

//class to represent the structure of the node of a linked list
class Node{
    public:
    int data;
    Node* next;
        Node(int d){
            this->data=d;
            this->next=NULL;
        }
};

//function to insert an element at head of linked list 
void insertathead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

//function for reverse the linked list
void reverse(Node* &head){
    Node* prev=NULL;
    Node* next=NULL;
    Node* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

//function to print a linked list
void print(Node* &head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=NULL;
    insertathead(head,5);
    insertathead(head,10);
    insertathead(head,15);
    insertathead(head,20);
    insertathead(head,25);
    print(head);
    reverse(head);
    print(head);
    return 0;   
}