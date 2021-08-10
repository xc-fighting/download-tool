#include <iostream>
#include <vector>
using namespace std;
vector<int> getCombination(vector<int>& input)
{
   vector<int> result;
   for(int i=0;i<input.size();i++)
   {
   	  if(input[i] % 2 != 0)
   	  {
   	  	 result.push_back(0);
   	  }
   	  else
   	  {
   	  	 int count_two = input[i] / 2;
   	  	 int count_four = count_two / 2;
   	  	 int ways = 1 + count_four;
   	  	 result.push_back(ways);
   	  }
   }
   return result;
}
int main()
{
   vector<int> input{4,5,6,8};
   vector<int> combines = getCombination(input);
   for(int i=0;i<combines.size();i++)
   {
   	 cout<<combines[i]<<" ";
   }
   cout<<endl;
}