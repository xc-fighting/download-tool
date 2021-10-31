#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
bool crossEqual(string first, string second) {
   if( first[0] == second[2] || first[2] == second[0] ) {
       return true;
   }
   return false;
}
string str_reverse(string input) {
  string ret(input);
  int left = 0;
  int right = ret.size() - 1;
  while( left < right ) {
     char temp = ret[left];
     ret[left] = ret[right];
     ret[right] = temp;
     left++;
     right--;
  }
  return ret;
}
int matchingPairs(string s, string t) {
  // Write your code here
  unordered_map<string,int> matching_freq;
  unordered_map<string,int> unmatching_freq;
  unordered_set<char> unmatchS;
  unordered_set<char> unmatchT;
  int len = s.size();
  int matching_pairs = 0;
  for( int index = 0; index < len; index++ ) {
      if( s[index] == t[index] ) {
          string matching_key('a',3);
          matching_key[0] = s[index];
          matching_key[1] = ':';
          matching_key[2] = t[index];
          if( matching_freq.find(matching_key) == matching_freq.end() ) {
              matching_freq[matching_key] = 0;
          }
          matching_pairs++;
          matching_freq[matching_key]++;
      }
      else {
         string unmatching_key('a',3);
         unmatching_key[0] = s[index];
         unmatching_key[1] = ':';
         unmatching_key[2] = t[index];
         cout<<"unmatching key is:" << unmatching_key<<endl;
          if( unmatching_freq.find(unmatching_key) == unmatching_freq.end() ) {
              cout<<"should set here"<<endl;
              unmatching_freq[unmatching_key] = 0;
          }
          unmatching_freq[unmatching_key]++;
          cout<<"final"<<endl;
          cout<<unmatching_freq[unmatching_key]<<endl;
          unmatchS.insert(s[index]);
          unmatchT.insert(t[index]);
      }
  }
  if( matching_pairs == len ) {
      bool nochange = false;
      for(auto entry: matching_freq) {
         cout<<entry.first<<","<<entry.second;
         if( entry.second > 1 ) {
             nochange = true;
             break;
         }
      }
      if(nochange == true ) {
         return matching_pairs;
      }
      return matching_pairs-1;
  }
  //cout<<matching_pairs<<endl;
  //traverse the unmatching pairs
  unordered_map<string,int>::iterator entry = unmatching_freq.begin();
  while(entry != unmatching_freq.end()) {
     string key = entry->first;
     string rkey = str_reverse(key);
     //cout<<"key is"<<key<<endl;
     cout<<"reverse key is:"<<rkey<<endl;
     cout<<unmatching_freq[rkey]<<endl;
     if( unmatching_freq.count(rkey) > 0 ) {
         //perfect pair
         cout<<"find it"<<endl;
         matching_pairs += 2;
         return matching_pairs;
     }
     entry++;
     
  }
  
  //no perfect matching pair
  for(char ch: unmatchS) {
     if( unmatchT.count(ch) > 0 ) {
        matching_pairs++;
        return matching_pairs;
     }
  }
  
  return matching_pairs;
  
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
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}