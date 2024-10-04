#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
   float value;
   Node * next;
};

void output(Node *&);    // Function Prototype to output list
void creates_list(Node *&);    // Function Prototype to create list
void deletes_node(Node *&);    // Function Prototype to delete node
void inserts_node(Node *&);    // Function Prototype to insert node
void deletes_list(Node *&);    // Function Prototype to delete list

// (code would only function passing pointers by reference, might be an Xcode compiler thing)

int main()
{
   Node *head = nullptr;    // head pointer initialized to nullptr
    
    creates_list(head);    // Function call to create linked list
    deletes_node(head);    // Function call to delete node
    inserts_node(head);    // Function call to insert node
    deletes_list(head);    // Function call to delete linked list
    
   return 0;
}


void output(Node * &hd)
{
    Node *current = hd;    // current pointer points to head of list
    int count = 1;    // count int variable to number each node in the list
    
    if (!hd) {    // Output statement if list is empty
       cout << "Empty list.\n";
       return;
   }
  
   while (current) {
       cout << "[" << count++ << "] " << current->value << endl;
       current = current->next;
   }
   cout << endl;
}

void creates_list(Node * &head)    // function creates a linked list of size SIZE
{
       for (int i = 0; i < SIZE; i++) {    // list is filled with values of random numbers from 0-99
           int tmp_val = rand() % 100;
           Node *newVal = new Node;
   
           if (!head) {    // if head is not set yet, newVal is set as the new head
               head = newVal;
               newVal->next = nullptr;
               newVal->value = tmp_val;
           }
           else {    // second or subsequent nodes placed at the head
               newVal->next = head;
               newVal->value = tmp_val;
               head = newVal;
           }
       }
       output(head);
}

void deletes_node(Node * &head)
{
    Node *current = nullptr;
    Node *prev = nullptr;
    int entry;
    
    cout << "Which node to delete? " << endl;    // User prompted to enter the node they wish to delete
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    
    current = head;    // current & prev set to point at head (start of the list)
    prev = head;
    
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }

    if (current) {
        if (current == head) {
            Node * temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
        else {
            prev->next = current->next;
            delete current;
            current = nullptr;
        }
    }
    
    output(head);
}

void inserts_node(Node * &head)
{
    Node * current = nullptr;
    Node * prev = nullptr;
    int entry;

    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    current = head;
    prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    
    if (entry == 1) {
        Node * newnode = new Node;
        newnode->value = 10000;
        newnode->next = head->next;
        head = newnode;
    }
    if (entry > 1) { //at this point, insert a node between prev and current
        Node * newnode = new Node;
        newnode->value = 10000;
        newnode->next = current;
        prev->next = newnode;
    }
    output(head);
}

void deletes_list(Node * &head)
{
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}
