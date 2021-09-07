#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> split(string input,string splitter)
{
        vector<string> result;
        string tempstr = input+splitter;
        int pos = tempstr.find(splitter);
        int splitterSize = splitter.size();
        while(pos != string::npos)
        {
            string component = tempstr.substr(0,pos);
            result.push_back(component);
            tempstr = tempstr.substr(pos+splitterSize);
            pos = tempstr.find(splitter);
        }
        return result;
}

int main()
{
    string test("this is a discussion please talk");
    string splitter(" ");
    vector<string> result = split(test,splitter);
    for(string str:result)
    {
        cout<<str<<endl;
    }
    cout<<"end here"<<endl;
}
