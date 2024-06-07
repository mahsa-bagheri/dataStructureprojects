#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* link;
  Node(int data) 
  {
        this->data = data;
        this->link = nullptr;
  }
};


//to find prime number
  bool isPrime(int n) 
  {
      // Corner case
      if (n <= 1)
            return false;

      // Check from 2 to n-1
      for (int i = 2; i <= n / 2; i++)
          if (n % i == 0)
            return false;

      return true;
  }


//remove prime number
  void removePrimes(Node*& first) {
  Node* p = nullptr;
  Node* q = first;
  while (q) {
    if (isPrime(q->data)) {
      if (p) {
        p->link = q->link;
      } else {
        first = q->link;
      }
      delete q;
      q = p ? p->link : first;
    } else {
      p = q;
      q = q->link;
    }
  }
}


//merge 2 sorted list
Node* mergeLists(Node* first1, Node* first2) 
{
  Node* dummyFirst = new Node(0);
  Node* current = dummyFirst;

  while (first1 != nullptr && first2 != nullptr) 
  {

    if (first1->data <= first2->data) 
    {
      current->link = first1;
      first1 = first1->link;
    } 

    else 
    {
      current->link = first2;
      first2 = first2->link;
    }
    current = current->link;
  }

  if (first1 != nullptr) 
  {
    current->link = first1;
  } 
  else 
  {
    current->link = first2;
  }

  return dummyFirst->link;
}

void printList(Node* first) 
{
  while (first != nullptr) 
  {
    cout << first->data << " ";
    first = first->link;
  }
  cout << endl;
}

class Stack {
private:
  Node* first; // Pointer to the top of the stack (first)

public:
  Stack() {
    first = nullptr; // Initialize an empty stack
  }

  void Push(int item) {
    Node* newnode = new Node(0); // Create a new node
    newnode->data = item; // Assign data to the new node
    newnode->link = first; // Link the new node to the old first
    first = newnode; // Make the new node the new first
  }

  int Pop() {
    if (first == nullptr) {
      throw std::out_of_range("Stack underflow"); // Check for empty stack
    }

    int popped_data = first->data; // Get the data from the first node
    Node* temp = first; // Store the current first
    first = first->link; // Move the first to the link node
    delete temp; // Delete the popped node (avoid memory leaks)

    return popped_data;
  }

  bool IsEmpty() const {
    return first == nullptr;
  }
};


class Queue {
private:
  Node* front; // Pointer to the front of the queue
  Node* rear; // Pointer to the rear of the queue

public:
  Queue() {
    front = rear = nullptr; // Initialize an empty queue
  }

  void Add(int item) {
    Node* newNode = new Node(0); // Create a new node
    newNode->data = item; // Assign data to the new node
    newNode->link = nullptr; // Set the link pointer to null

    if (front == nullptr) { // If queue is empty, both front and rear point to the new node
      front = rear = newNode;
    } else { // If queue is not empty, add the new node to the rear
      rear->link = newNode;
      rear = newNode;
    }
  }

  int Delete() {
    if (front == nullptr) { // Check for empty queue
      throw std::out_of_range("Queue underflow");
    }

    int deleted_data = front->data; // Get the data from the front node
    Node* p = front; // Store the current front node
    front = front->link; // Move the front to the link node

    delete p; // Delete the Deleted node (avoid memory leaks)

    return deleted_data;
  }

  bool IsEmpty() const {
    return front == nullptr;
  }
};
int main() {

//sample for delete the prime number
    Node* first = nullptr;
    for (int i = 10; i > 0; i--) {
    Node* newNode = new Node(0);
    newNode->data = i;
    newNode->link = first;
    first = newNode;
  }

  // Sample for sorted linked lists
  Node* first1 = new Node(1);
  first1->link = new Node(3);
  first1->link->link = new Node(5);

  Node* first2 = new Node(2);
  first2->link = new Node(4);


  Node* mergedList = mergeLists(first1, first2);

    // call the delete prime number function
  removePrimes(first);
cout << "remove prime : ";
  // print the lists (without prime number)
  printList(first);
 
  cout << "-------------------------------"<<endl;
  cout << "merged list : ";
  //print the merged list
  printList(mergedList);

  cout << "-------------------------------"<< endl;
  cout << "Stack :";
  Stack myStack;

  myStack.Push(1);
  myStack.Push(2);
  myStack.Push(3);

  cout << "Popped: " << myStack.Pop() << endl;
  cout << "Popped: " << myStack.Pop() << endl;
  cout << "Popped: " << myStack.Pop() << endl;

  if (myStack.IsEmpty()) {
    cout << "Stack is empty" << endl;
  }

  cout << "-------------------------------"<<endl;
  
  Queue myQueue;
  myQueue.Add(1);
  myQueue.Add(2);
  myQueue.Add(3);

  cout << "Deleted: " << myQueue.Delete() << endl;
  cout << "Deleted: " << myQueue.Delete() << endl;
  cout << "Deleted: " << myQueue.Delete() << endl;

  if (myQueue.IsEmpty()) {
    cout << "Queue is empty" << endl;
  }

}