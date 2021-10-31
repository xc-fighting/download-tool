/*
Passing Yearbooks
There are n students, numbered from 1 to n, each with their own yearbook. They would like to pass their yearbooks around and get them signed by other students.
You're given a list of n integers arr[1..n], which is guaranteed to be a permutation of 1..n (in other words, it includes the integers from 1 to n exactly once each, in some order). The meaning of this list is described below.
Initially, each student is holding their own yearbook. The students will then repeat the following two steps each minute: Each student i will first sign the yearbook that they're currently holding (which may either belong to themselves or to another student), and then they'll pass it to student arr[i-1]. It's possible that arr[i-1] = i for any given i, in which case student i will pass their yearbook back to themselves. Once a student has received their own yearbook back, they will hold on to it and no longer participate in the passing process.
It's guaranteed that, for any possible valid input, each student will eventually receive their own yearbook back and will never end up holding more than one yearbook at a time.
You must compute a list of n integers output, whose element at i-1 is equal to the number of signatures that will be present in student i's yearbook once they receive it back.
Signature
int[] findSignatureCounts(int[] arr)
Input
n is in the range [1, 100,000].
Each value arr[i] is in the range [1, n], and all values in arr[i] are distinct.
Output
Return a list of n integers output, as described above.
Example 1
n = 2
arr = [2, 1]
output = [2, 2]
Pass 1:
Student 1 signs their own yearbook. Then they pass the book to the student at arr[0], which is Student 2.
Student 2 signs their own yearbook. Then they pass the book to the student at arr[1], which is Student 1.
Pass 2:
Student 1 signs Student 2's yearbook. Then they pass it to the student at arr[0], which is Student 2.
Student 2 signs Student 1's yearbook. Then they pass it to the student at arr[1], which is Student 1.
Pass 3:
Both students now hold their own yearbook, so the process is complete.
Each student received 2 signatures.
Example 2
n = 2
arr = [1, 2]
output = [1, 1]
Pass 1:
Student 1 signs their own yearbook. Then they pass the book to the student at arr[0], which is themself, Student 1.
Student 2 signs their own yearbook. Then they pass the book to the student at arr[1], which is themself, Student 2.
Pass 2:
Both students now hold their own yearbook, so the process is complete.
Each student received 1 signature.

*/
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findSignatureCounts(vector <int> arr) {
  // Write your code here
  int n = arr.size();
  unordered_map<int,int> sign_freq;
  vector<int> currentHolding(n,-1);
  for( int i = 0; i < n; i++ ) {
      sign_freq[i+1] = 0;
      //initially they all have their own book
      currentHolding[i] = i + 1;
  }
  int sign_num = 0;
  bool firstRound = true;
  while(sign_num < n) {
    vector<int> tempbuffer(n,0);
    for(int index = 0; index < n; index++ ) {
        int bookHolding = currentHolding[index];
        if( firstRound == false && bookHolding == index + 1) {
            sign_num++;
        }
        else {
            sign_freq[bookHolding]++;
        }
        
        int nextStudent = arr[index];
        tempbuffer[nextStudent-1] = bookHolding;
    }
    for(int index = 0; index < n ; index++ ) {
        currentHolding[index] = tempbuffer[index];
    }
    if(firstRound) {
       firstRound = false;
    }
    
  }
  vector<int> result(n,-1);
  for(int index = 0; index < n; index++ ) {
     result[index] = sign_freq[index+1];
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
  vector <int> arr_1{2, 1};
  vector <int> expected_1{2, 2};
  vector <int> output_1 = findSignatureCounts(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{1, 2};
  vector <int> expected_2{1, 1};
  vector <int> output_2 = findSignatureCounts(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}