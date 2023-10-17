#include <iostream>  
  
using namespace std;  
  
// Node class  
class Node {  
public:  
  int data;  
  Node *next;  
  
  Node(int data) {  
    this->data = data;  
    this->next = nullptr;  
  }  
};  
  
// Linked list class  
class LinkedList {  
private:  
  Node *head;  
  
public:  
  LinkedList() {  
    this->head = nullptr;  
  }  
  
  void insertAtBeginning(int data) {  
    Node *newNode = new Node(data);  
    newNode->next = head;  
    head = newNode;  
  }  
  
  void insertAtEnd(int data) {  
    Node *newNode = new Node(data);  
    if (head == nullptr) {  
      head = newNode;  
      return;  
    }  
    Node *temp = head;  
    while (temp->next != nullptr) {  
      temp = temp->next;  
    }  
    temp->next = newNode;  
  }  
  
  void deleteAtBeginning() {  
    if (head == nullptr) {  
      return;  
    }  
    Node *temp = head;  
    head = head->next;  
    delete temp;  
  }  
  
  void deleteAtEnd() {  
  if (head == nullptr) {  
    return;  
  }  
  if (head->next == nullptr) {  
    delete head;  
    head = nullptr;  
    return;  
  }  
  Node *temp = head;  
  while (temp->next->next != nullptr) {  
    temp = temp->next;  
  }  
  delete temp->next;  
  temp->next = nullptr;  
}  
  
void printList() {  
  Node *temp = head;  
  while (temp != nullptr) {  
    cout << temp->data << " ";  
    temp = temp->next;  
  }  
  cout << endl;  
}  
};  
  
int main() {  
// Create a linked list  
LinkedList List;  
  
// Insert some nodes at the beginning of the list  
list.insertAtBeginning(3);  
list.insertAtBeginning(2);  
list.insertAtBeginning(1);  
  
// Insert some nodes at the end of the list  
list.insertAtEnd(4);  
list.insertAtEnd(5);  
list.insertAtEnd(6);  
  
// Print the list  
cout << "Original list: ";  
list.printList();  
  
// Delete a node at the beginning of the list  
list.deleteAtBeginning();  
  
// Print the List again  
cout << "List after deleting a node at the beginning: ";  
list.printList();  
  
// Delete a node at the end of the list  
list.deleteAtEnd();  
  
// Print the List again  
cout << "List after deleting a node at the end: ";  
list.printList();  
  
return 0;  
}  
