/*
Reverse Operations
You are given a singly-linked list that contains N integers. A subpart of the list is a contiguous set of even elements, bordered either by either end of the list or an odd element. For example, if the list is [1, 2, 8, 9, 12, 16], the subparts of the list are [2, 8] and [12, 16].
Then, for each subpart, the order of the elements is reversed. In the example, this would result in the new list, [1, 8, 2, 9, 16, 12].
The goal of this question is: given a resulting list, determine the original order of the elements.
Implementation detail:
You must use the following definition for elements in the linked list:
class Node {
    int data;
    Node next;
}
Signature
Node reverse(Node head)
Constraints
1 <= N <= 1000, where N is the size of the list
1 <= Li <= 10^9, where Li is the ith element of the list
Example
Input:
N = 6
list = [1, 2, 8, 9, 12, 16]
Output:
[1, 8, 2, 9, 16, 12]



*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

// Add any helper functions you may need here

bool isEven(Node* cur) {
   int value = cur->data;
   if( ( value % 2 ) == 0 ) {
       return true;
   }
   return false;
}
Node* reverse(Node *head) {
  // Write your code here
  if( head == nullptr || head->next == nullptr ) {
     return head;
  }
  Node* dummy = new Node(-1);
  dummy->next = head;
  Node* cur = head;
  Node* new_head = nullptr;
  Node* front = dummy;
  while( cur != nullptr ) {
      if( isEven(cur) ) {
          Node* nextNode = cur->next;
          cur->next = new_head;
          new_head = cur;
          cur = nextNode;
      }
      else {
          
          if( new_head != nullptr ) {
              Node* oldFrontNext = front->next;
              front->next = new_head;
              oldFrontNext->next = cur;
              new_head = nullptr;
          }
          front = cur;
          cur = cur->next;
      }
  }
  if( new_head != nullptr ) {
       Node* oldFrontNext = front->next;
       front->next = new_head;
       oldFrontNext->next = cur;
       new_head = nullptr;
  }
  
  return dummy->next;
  
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printLinkedList(Node *head) {
  cout << "[";
  while (head != NULL) {
    cout << head -> data;
    head = head -> next;
    if (head != NULL)
      cout << " ";
  }
  cout << "]";
}

int test_case_number = 1;

void check(Node *expectedHead, Node *outputHead) {
  bool result = true;
  Node *tempExpectedHead = expectedHead;
  Node *tempOutputHead = outputHead;
  while (expectedHead != NULL && outputHead != NULL) {
    result &= (expectedHead -> data == outputHead -> data);
    expectedHead = expectedHead -> next;
    outputHead = outputHead -> next;
  }
  if (!(expectedHead == NULL && outputHead == NULL)) result = false;

  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printLinkedList(tempExpectedHead); 
    cout << " Your output: ";
    printLinkedList(tempOutputHead);
    cout << endl; 
  }
  test_case_number++;
}

Node* createLinkedList(vector<int> arr) {
  Node *head = NULL;
  Node *tempHead = head;
  for (auto &v : arr) {
    if (head == NULL) head = new Node(v), tempHead = head;
    else {
      head -> next = new Node(v);
      head = head -> next;
    }
  }
  return tempHead;
}

int main() {

  Node *head_1 = createLinkedList({1, 2, 8, 9, 12, 16});
  Node *expected_1 = createLinkedList({1, 8, 2, 9, 16, 12});
  Node *output_1 = reverse(head_1);
  check(expected_1, output_1);

  Node *head_2 = createLinkedList({2, 18, 24, 3, 5, 7, 9, 6, 12});
  Node *expected_2 = createLinkedList({24, 18, 2, 3, 5, 7, 9, 12, 6});
  Node *output_2 = reverse(head_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
