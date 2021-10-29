/*
Minimum Length Substrings
You are given two strings s and t. You can select any substring of string s and rearrange the characters of the selected substring. Determine the minimum length of the substring of s such that string t is a substring of the selected substring.
Signature
int minLengthSubstring(String s, String t)
Input
s and t are non-empty strings that contain less than 1,000,000 characters each
Output
Return the minimum length of the substring of s. If it is not possible, return -1
Example
s = "dcbefebce"
t = "fd"
output = 5
Explanation:
Substring "dcbef" can be rearranged to "cfdeb", "cefdb", and so on. String t is a substring of "cfdeb". Thus, the minimum length required is 5.
*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
bool match(vector<int>& smap, vector<int>& tmap) {
    for( int index = 0; index < 26; index++ ) {
        if( tmap[index] == 0 ) {
            continue;
        }
        if( smap[index] < tmap[index] ) {
            return false;
        }
    }
    return true;
}

int minLengthSubstring(string s, string t) {
  // Write your code here
  vector<int> tmap(26,0);
  vector<int> smap(26,0);
  for( int index = 0; index < t.size(); index++ ) {
      tmap[t[index]-'a']++;
  }
  int left = 0;
  int right = 0;
  int result = INT_MAX;
  while( left < s.size() ) {
     while( right < s.size() && match(smap,tmap) == false ) {
        smap[s[right]-'a']++;
        right++;
     }
     if( match(smap,tmap) == true ) {
         result = min(result, right-left);
     }
     smap[s[left]-'a']--;
     left++;
  }
  if( result == INT_MAX ) {
      return -1;
  }
  return result;
  
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

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}