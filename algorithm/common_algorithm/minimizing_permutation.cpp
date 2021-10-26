/*
Minimizing Permutations
In this problem, you are given an integer N, and a permutation, P of the integers from 1 to N, denoted as (a_1, a_2, ..., a_N). You want to rearrange the elements of the permutation into increasing order, repeatedly making the following operation:
Select a sub-portion of the permutation, (a_i, ..., a_j), and reverse its order.
Your goal is to compute the minimum number of such operations required to return the permutation to increasing order.
Signature
int minOperations(int[] arr)
Input
Array arr is a permutation of all integers from 1 to N, N is between 1 and 8
Output
An integer denoting the minimum number of operations required to arrange the permutation in increasing order
Example
If N = 3, and P = (3, 1, 2), we can do the following operations:
Select (1, 2) and reverse it: P = (3, 2, 1).
Select (3, 2, 1) and reverse it: P = (1, 2, 3).
output = 2
*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

string getKey(vector<int>& input) {
   string result = "";
   for(int elem: input) {
      result = result + ":" + to_string(elem);
   }
   return result;
}

void reverse( vector<int>& input, int left, int right ) {
    while( left < right ) {
        int temp = input[left];
        input[left] = input[right];
        input[right] = temp;
        left++;
        right--;
    }
    return;
}

bool isIncreasing( vector<int>& input ) {
    for( int index = 1; index < input.size(); index++ ) {
        if( input[index] >= input[index-1] ) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}
int minOperations(vector <int> arr) {
  // Write your code here
  queue<pair<string,vector<int>>> stateQueue;
  if( isIncreasing(arr) ) {
      return 0;
  }
  unordered_set<string> seen;
  string key = getKey(arr);
  seen.insert(key);
  pair<string,vector<int>> firstState(key,vector<int>(arr));
  stateQueue.push(firstState);
  int step = 0;
  int len = arr.size();
  while( stateQueue.empty() == false ) {
     int size = stateQueue.size();
     for( int i = 0; i < size; i++ ) {
         pair<string,vector<int>> frontState = stateQueue.front();
         stateQueue.pop();
         vector<int> curArr = frontState.second;
         if( isIncreasing(curArr) == true ) {
             return step;
         }
         for( int delta = 2; delta < len; delta++ ) {
             for( int startIdx = 0; startIdx < len; startIdx++ ) {
                  int endIdx = startIdx + delta - 1;
                  if( endIdx < len ) {
                      reverse(curArr,startIdx,endIdx);
                      string newkey = getKey(curArr);
                      if( seen.find(newkey) == seen.end() ) {
                          pair<string,vector<int>> newState(newkey,vector<int>(curArr));
                          seen.insert(newkey);
                          stateQueue.push(newState);
                      }
                      reverse(curArr,startIdx,endIdx);
                  }
             }
         }
     }
     step++;
  }
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  int n_1 = 5;
  vector <int> arr_1{1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}