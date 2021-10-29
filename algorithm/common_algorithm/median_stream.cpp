/*
Median Stream
You're given a list of n integers arr[0..(n-1)]. You must compute a list output[0..(n-1)] such that, for each index i (between 0 and n-1, inclusive), output[i] is equal to the median of the elements arr[0..i] (rounded down to the nearest integer).
The median of a list of integers is defined as follows. If the integers were to be sorted, then:
If there are an odd number of integers, then the median is equal to the middle integer in the sorted order.
Otherwise, if there are an even number of integers, then the median is equal to the average of the two middle-most integers in the sorted order.
Signature
int[] findMedian(int[] arr)
Input
n is in the range [1, 1,000,000].
Each value arr[i] is in the range [1, 1,000,000].
Output
Return a list of n integers output[0..(n-1)], as described above.
Example 1
n = 4
arr = [5, 15, 1, 3]
output = [5, 10, 5, 4]
The median of [5] is 5, the median of [5, 15] is (5 + 15) / 2 = 10, the median of [5, 15, 1] is 5, and the median of [5, 15, 1, 3] is (3 + 5) / 2 = 4.
Example 2
n = 2
arr = [1, 2]
output = [1, 1]
The median of [1] is 1, the median of [1, 2] is (1 + 2) / 2 = 1.5 (which should be rounded down to 1).

*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
class small_comp {
public:
   bool operator()(int& lhs, int& rhs) {
       if( lhs < rhs ) {
           return false;
       }
       return true;
   }
};

class large_comp {
public:
  bool operator()(int& lhs, int& rhs) {
      if( lhs < rhs ) {
         return true;
      }
      return false;
  }
};

vector <int> findMedian(vector <int> arr) {
  // Write your code here
  //largest elem
  priority_queue<int,vector<int>,small_comp> small_pq;
  
  priority_queue<int,vector<int>,large_comp> large_pq;
  int len = arr.size();
  vector<int> result(len,-1);
  for( int index = 0; index < len; index++ ) {
       large_pq.push(arr[index]);
       small_pq.push(large_pq.top());
       large_pq.pop();
       while( large_pq.size() < small_pq.size() ) {
           large_pq.push(small_pq.top());
           small_pq.pop();
       }
       if( large_pq.size() == small_pq.size() ) {
           int l = large_pq.top();
           int s = small_pq.top();
           result[index] = ( l + s ) / 2;
       }
       else if( large_pq.size() > small_pq.size() ) {
           result[index] = large_pq.top();
       }
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
  vector <int> arr_1{5, 15, 1, 3};
  vector <int> expected_1{5, 10, 5, 4};
  vector <int> output_1 = findMedian(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{2, 3, 4, 3, 4, 3};
  vector <int> output_2 = findMedian(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}