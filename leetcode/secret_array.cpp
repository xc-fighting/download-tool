#include <iostream>
#include <vector>
using namespace std;

int countAnalogousArrays(vector<int>& consecutive,int lower,int higher)
{
	int result = 0;
	for(int startElem = lower; startElem<=higher; startElem++)
	{
		int cur = startElem;
        bool valid = true;
		for(int i=0;i<consecutive.size();i++)
		{
            cur = cur - consecutive[i];
            if(cur>=lower && cur<=higher)
            {
            	continue;
            }
            else
            {
               valid = false;
               break;
            }
		}
		if(valid)
		{
			result++;
		}
	}
	return result;
}
int main()
{
   vector<int> input{-2,-1,-2,5};
   cout<<countAnalogousArrays(input,3,10);
}