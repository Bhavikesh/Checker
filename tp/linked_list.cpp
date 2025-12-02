/*------------ Single linked list --------------*/


// #include<iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node* next;

//         Node(int data){
//             this -> data = data;
//             this -> next = NULL;
//         }

//         ~Node(){
//             int value = this -> data;
//             if(this -> next != NULL){
//                 delete next;
//                 this->next = NULL;
//             }
//         }
// };

// void insertAtHead(Node* &head, int d){
//     Node *temp = new Node(d);
//     temp->next = head;
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d){
//     Node* temp = new Node(d);
//     tail -> next = temp;
//     tail = temp;
// }
 
// void insertAtPosition(Node* &tail, Node* &head, int pos, int d){
//     if(pos == 1){
//         insertAtHead(head,d);
//         return;
//     }

//     Node *temp = head;
//     int cnt = 1;
//     while(cnt<pos-1){
//         temp = temp->next;
//         cnt++;
//     }

//     if(temp->next == NULL){
//         insertAtTail(tail,d);
//         return;
//     }

//     Node *insertToPosition = new Node(d);
//     insertToPosition-> next = temp->next;
//     temp->next = insertToPosition;
// }

// void deleteAtPosition(Node* &head, Node* &tail, int pos){

//     // deleting first node
//     if(pos == 1){
//         Node* temp = head;
//         head = head -> next;
//         temp -> next = NULL;
//         delete temp;
//     }

//     else{
//         // deleting middle and last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt=1;
//         while(cnt<pos){
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }
//         prev -> next = curr->next;

//         if(curr->next == NULL){
//             tail = prev;
//         }
//         curr ->next = NULL;
//         delete curr;

//     }

// }

// void printNode(Node *&head){
//     Node* temp = head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }cout<<endl;

// }

// int main(){
//     Node *n1 = new Node(10);
//     // cout<< n1->data<<endl;
//     // cout<< n1->next<<endl;

//     Node *head = n1;
//     Node *tail = n1;
//     printNode(head);

//     insertAtTail(tail , 13);
//     printNode(head);

//     insertAtTail(tail,34);
//     printNode(head);

//     insertAtPosition(tail, head, 4, 15);
//     printNode(head);

    
//     cout<<"Head : "<<head->data<<endl;
//     cout<<"Tail : "<<tail->data<<endl;
    
//     deleteAtPosition(head,tail, 4);
//     printNode(head);
//     cout<<"Tail : "<<tail->data<<endl;
// }



/*------------------ Double Linked list -----------------*/

// #include<iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node *next;
//         Node *prev;

//         // Constructor
//         Node(int data){
//             this->data = data;
//             this->prev = NULL;
//             this->next = NULL;
//         }

//         ~Node(){
//             int val = this->data;
//             if(this->next != NULL){
//                 delete next;
//                 this->next = NULL;
//             }
//         }
// };

// void printNode(Node* &head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }cout<<endl;
// }

// int getLength(Node* &head){
//     Node *temp = head;
//     int len = 0;
//     while(temp != NULL){
//         len++;
//         temp = temp -> next;
//     }
//     return len;
// }

// void insertAtHead(Node* &head, int d){
//     Node* temp = new Node(d);
//     temp->next = head;
//     head->prev = temp;
//     head = temp;
// }

// void insertAtTail(Node* &tail, int d){
//     Node* temp = new Node(d);
//     tail->next = temp;
//     temp->prev = tail;
//     tail = temp;

// }

// void insertAtPosition(Node* &tail, Node* &head, int pos, int d){

//     if(pos == 1){
//         insertAtHead(head, d);
//         return;
//     }

//     else{

//         Node* temp = head;
//         int cnt = 1;
//         while(cnt < pos-1){
//             temp = temp->next;
//             cnt++;
//         }

//         if(temp -> next == NULL){
//             insertAtTail(tail, d);
//             return;
//         }

//         Node *nodeToInsert = new Node(d);
//         nodeToInsert->next = temp->next;
//         temp->next->prev = nodeToInsert;
//         temp->next = nodeToInsert;
//         nodeToInsert->prev = temp;

//     }

// }

// void deleteAtPosition(Node* &head, int pos){


//     if(pos == 1){
//         Node* temp = head;
//         temp->next->prev = NULL;
//         head = temp -> next;
//         temp->next = NULL;
//         delete temp;
//     }

//     else{
//         Node*curr = head;
//         Node*prev = NULL;

//         int cnt=1;
//         while(cnt<pos){
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         curr->prev = NULL;
//         prev -> next = curr->next;
//         curr -> next = NULL;

//         delete curr; 

//     }
// }

// int main(){
//     Node *n1 = new Node(10);
//     Node* head = n1;
//     Node* tail = n1;
//     printNode(head);
//     cout<<"\nLength : " << getLength(n1)<<endl;

//     insertAtHead(head,11);
//     printNode(head);

//     insertAtHead(head,12);
//     printNode(head);

//     insertAtHead(head,13);
//     printNode(head);

//     insertAtTail(tail, 25);
//     printNode(head);

//     insertAtPosition(tail, head, 1, 101);
//     printNode(head);

//     insertAtPosition(tail, head, 3, 100);
//     printNode(head);

//     insertAtPosition(tail, head, 8, 102);
//     printNode(head);

//     deleteAtPosition(head, 8);
//     printNode(head);

//     return 0;
// }



/*------------- single circular linked list ------------*/


#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        ~Node(){
            int val = this -> data;
            if(this->next != NULL){
                delete next;
                this-> next = NULL;
            }
        }
};


void insert(Node* &tail, int element, int d){

    // if empty list
    if(tail == NULL){
        Node *newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }

    else{
        Node *curr = tail;
        while(curr->data != element){
            curr = curr -> next;
        }

        Node *temp = new Node(d);
        temp -> next = curr ->next;
        curr -> next = temp;
    }

}

void deleteNode(Node* &tail, int val){

    if(tail == NULL){
        cout<<"Please create the list first\n";
        return;
    }

    else{
        Node *prev = tail;
        Node *curr = prev -> next;

        while( curr->data != val){
            prev = curr;
            curr = curr->next;
        }

        prev -> next = curr -> next;
        curr->next = NULL;
        if(tail == curr){
            tail = prev;
        }
        delete  curr;
    }
}

void print(Node* &tail){
    Node *temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }
    while(tail != temp);
    cout<<endl;

}

int main(){
    
    Node *tail = NULL;

    insert(tail, 5, 4);
    print(tail);

    insert(tail, 4, 5);
    print(tail);

    insert(tail, 5, 7);
    print(tail);

    insert(tail, 7, 9);
    print(tail);

    insert(tail, 9, 1);
    print(tail);

    deleteNode(tail, 4);
    print(tail);
    return 0;
}