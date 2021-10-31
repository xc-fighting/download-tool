#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> CountSubarrays(vector <int> arr) {
  // Write your code here
  int len = arr.size();
  vector<int> leftSubArrayNum(len,-1);
  vector<int> rightSubArrayNum(len,-1);
  stack<int> increaseStack;
  for( int index = 0; index < len; index++ ) {
      //traverse from left to right
      if( increaseStack.empty() == true ) {
          leftSubArrayNum[index] = index;
          increaseStack.push(index);
      }
      else {
        while( increaseStack.empty() == false 
               && arr[index] > arr[increaseStack.top()] ) {
             increaseStack.pop();
        }
        if( increaseStack.empty() == true ) {
            leftSubArrayNum[index] = index;
        }
        else {
            leftSubArrayNum[index] = index - increaseStack.top() - 1;
        }
        increaseStack.push(index);
      }
  }
  
  while( increaseStack.empty() == false ) {
       increaseStack.pop();
  }
  
  for( int index = len - 1; index >= 0; index-- ) {
      if( increaseStack.empty() == true ) {
          rightSubArrayNum[index] = len - 1 - index;
          increaseStack.push(index);
      }
      else {
        while( increaseStack.empty() == false 
               && arr[index] > arr[increaseStack.top()] ) {
             increaseStack.pop();
        }
        if( increaseStack.empty() == true ) {
            rightSubArrayNum[index] = len - 1 - index;
        }
        else {
            rightSubArrayNum[index] = increaseStack.top() - index - 1;
        }
        increaseStack.push(index);
      }
  }
  
  vector<int> result(len,-1);
  for( int index = 0; index < len; index++ ) {
      cout<<index<<":"<<leftSubArrayNum[index]<<" "<<rightSubArrayNum[index]<<endl;
      result[index] = leftSubArrayNum[index] + rightSubArrayNum[index] + 1;
  }
  return result;
  
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}