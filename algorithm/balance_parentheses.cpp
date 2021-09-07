#include <iostream>
#include <map>
using namespace std;
bool isBalanced(map<char,int>& ch_freq)
{
	int smallParentheses = 0;
	int largeParentheses = 0;
	smallParentheses = ch_freq['('] - ch_freq[')'];
	largeParentheses = ch_freq['['] - ch_freq[']'];
	int totalBalance = abs(smallParentheses) + abs(largeParentheses);
	if(totalBalance == ch_freq['?'])
	{
		return true;
	}
	return false;
}
int getWays(string s)
{
  map<char,int> ch_freq;
  ch_freq['('] = 0;
  ch_freq[')'] = 0;
  ch_freq['['] = 0;
  ch_freq[']'] = 0;
  for(int i=0;i<s.size();i++)
  {
  	 ch_freq[s[i]]++;
  }
  map<char,int> rightPart;
  rightPart['('] = 0;
  rightPart[')'] = 0;
  rightPart['['] = 0;
  rightPart[']'] = 0;
  rightPart['?'] = 0;
  map<char,int> leftPart;
  leftPart['('] = 0;
  leftPart[')']= 0;
  leftPart['['] = 0;
  leftPart[']'] = 0;
  int ways = 0;

  for(int cut=0;cut<s.size()-1;cut++)
  {
  	 //define [0,cut]
  	 char current = s[cut];
  	 leftPart[current]++;
  	 rightPart['('] = ch_freq['('] - leftPart['('];
  	 rightPart['['] = ch_freq['['] - leftPart['['];
  	 rightPart[')'] = ch_freq[')'] - leftPart[')'];
  	 rightPart[']'] = ch_freq[']'] - leftPart[']'];
  	 if(isBalanced(leftPart) && isBalanced(rightPart))
  	 {
  	 	 cout<<"the cut place:"<<cut<<endl;
  	 	 ways++;
  	 }
  }
  return ways;
}
int main()
{
   cout<<getWays("(?][")<<endl;
}