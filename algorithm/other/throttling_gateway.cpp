#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool filterPerSecond(map<int,int>& time_requests,int cur)
{
    if(time_requests.find(cur) == time_requests.end())
    {
    	return true;
    }
    int totalSum = time_requests[cur];
    if( totalSum >= 3 )
    {
    	return false;
    }
    return true;
}

bool filterTenSeconds(map<int,int>& time_requests,int cur)
{
   int lowerKey = max(1,cur-9);
   int curKey = cur;
   map<int,int>::iterator it_low,it_high;
   it_low = time_requests.lower_bound(lowerKey);
   it_high = time_requests.upper_bound(curKey);
   map<int,int>::iterator it;
   int numRequest = 0;
   for(it=it_low;it!=it_high;it++)
   { 
      numRequest += it->second;
   }
   if(numRequest>=20)
   {
   	  return false;
   }
   return true;

}

bool filterMinute(map<int,int>& time_requests,int cur)
{
   int lowerKey = max(1,cur-59);
   int curKey = cur;
   map<int,int>::iterator it_low,it_high;
   it_low = time_requests.lower_bound(lowerKey);
   it_high = time_requests.upper_bound(curKey);
   map<int,int>::iterator it;
   int numRequest = 0;
   for(it=it_low;it != it_high;it++)
   { 
      numRequest += it->second;
   }
   if(numRequest>=60)
   {
   	  return false;
   }
   return true;
}

int dropRequest(vector<int>& requests,int n)
{
	map<int,int> time_requests;
    int result = 0;
    for(int i=0;i<requests.size();i++)
    {
    	int request = requests[i];
    	if(filterPerSecond(time_requests,request) 
    		&& filterTenSeconds(time_requests,request)
    		&& filterMinute(time_requests,request)
    	)
    	{
            //pass the conditions
            cout<<"request:"<<request<<"passed"<<endl;
    	}
    	else
    	{
    		cout<<"drop the request:"<<request<<endl;
    		result++;
    	}
    	if(time_requests.find(request)==time_requests.end())
    	{
    		time_requests[request]=0;
    	}
    	time_requests[request]++;
    }
    return result;
}

int main()
{
    vector<int> input{1,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,11,11,11,11};
  /*  for(int e:input)
    {
    	cout<<e;
    } */
    cout<<dropRequest(input,27)<<endl;
	return 0;
}