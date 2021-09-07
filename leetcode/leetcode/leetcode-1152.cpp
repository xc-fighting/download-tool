bool compare(tuple<string,string,int>& lhs,tuple<string,string,int>& rhs)
{
    int ltime = std::get<2>(lhs);
    int rtime = std::get<2>(rhs);
    if(ltime<rtime)
    {
        return true;
    }
    return false;
}
class Solution {
private:
    vector<string> split(string input,string splitter)
    {
        string tempstr = input+splitter;
        int pos = tempstr.find(splitter);
        vector<string> result;
        while(pos != string::npos)
        {
            string component = tempstr.substr(0,pos);
            result.push_back(component);
            int index = pos+splitter.size();
            tempstr = tempstr.substr(index);
            pos = tempstr.find(splitter);
        }
        return result;
    }
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<tuple<string,string,int>> tuplelist;
        
        for(int i=0;i<username.size();i++)
        {
            tuplelist.push_back(tuple<string,string,int>(username[i],website[i],timestamp[i]));
        }
        sort(tuplelist.begin(),tuplelist.end(),compare);
            
        unordered_map<string,vector<string>> name_visits;
        for(int i=0;i<tuplelist.size();i++)
        {
            string uname = get<0>(tuplelist[i]);
            string site = get<1>(tuplelist[i]);
            if(name_visits.find(uname) == name_visits.end())
            {
                name_visits[uname] = vector<string>();
            }
            name_visits[uname].push_back(site);
        }
        unordered_map<string,set<string>> pattern_names;
        for(auto item:name_visits)
        {
            string name = item.first;
            vector<string> websites = item.second;
            if(websites.size()<3)
            {
                continue;
            }
            for(int i=0;i<websites.size()-2;i++)
            {
              //  cout<<"1"<<endl;
                for(int j=i+1;j<websites.size()-1;j++)
                {
                   // cout<<"2"<<endl;
                    for(int k =j+1;k<websites.size();k++)
                    {
                        string pattern = websites[i] + ":"+ websites[j] + ":" +websites[k];
                        if(pattern_names.find(pattern)==pattern_names.end())
                        {
                            pattern_names[pattern] = set<string>();
                        }
                        pattern_names[pattern].insert(name);
                    }
                }
            }
        }
     
        int result = 0;
        string result_str = "";
        for(auto item:pattern_names)
        {
            if(item.second.size() > result)
            {
                result = item.second.size();
                result_str = item.first;
            }
            else if(item.second.size() == result)
            {
                if(item.first.compare(result_str)<0)
                {
                    result_str = item.first;
                }
            }
            
        }
     //   cout<<"finish here"<<endl;
        return split(result_str,":");
       
    }
};