/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void printList(Node* head) {
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

void deleteList(Node* head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main(int argc, char* argv[])
{
  Node* head = new Node(1, nullptr);
  head->next = new Node(2, nullptr);
  head->next->next = new Node(3, nullptr);

  Node* odd = nullptr;
  Node* even = nullptr;

  split(head, odd, even);

  cout << "Odds: ";
  printList(odd);
  cout << "Evens: ";
  printList(even);

  deleteList(odd);
  deleteList(even);
}
