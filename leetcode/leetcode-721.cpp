class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //set up the map from email to name
        int count = accounts.size();
        vector<int> parents(count,-1);
        for(int i=0;i<count;i++)
        {
            parents[i] = i;
        }
      //  cout<<"finish 1"<<endl;
        map<string,vector<int>> emailAccountMap;
        int realCount = count;
        for(int i=0;i<count;i++)
        {
            vector<string>& accountInfo = accounts[i];
            for(int index = 1;index<accountInfo.size();index++)
            {
                string email = accountInfo[index];
                if(emailAccountMap.find(email) == emailAccountMap.end())
                {
                    emailAccountMap[email] = vector<int>();
                }
                emailAccountMap[email].push_back(i);
            }
        }
     //   cout<<"finish 2"<<endl;
        
        //make the union
        for(auto &mapPair: emailAccountMap)
        {
            vector<int>& accountsIndex = mapPair.second;
            for(int i=0;i<accountsIndex.size();i++)
            {
                for(int j=i+1;j<accountsIndex.size();j++)
                {
                    int p1 = findParent(parents,accountsIndex[i]);
                    int p2 = findParent(parents,accountsIndex[j]);
                    if(p1 != p2)
                    {
                        parents[p1] = p2;
                        
                    }
                }
            }
        }
      //  cout<<"finish 3"<<endl;
        //pre solve the output
        unordered_map<int,unordered_set<string>> temp_buffer;
        for(int i=0;i<count;i++)
        {
            int root = findParent(parents,i);
            cout<<root<<endl;
            if(temp_buffer.find(root) == temp_buffer.end())
            {
               // cout<<"initialize the set"<<endl;
                temp_buffer[root] = unordered_set<string>();
            }
            for(int index=1;index<accounts[i].size();index++)
            {
                cout<<accounts[i][index]<<endl;
                temp_buffer[root].insert(accounts[i][index]);
            }
        }
      //  cout<<"finish 4"<<endl;
        
        //generate the output
        vector<vector<string>> result;
        for(auto temp_pair:temp_buffer)
        {
            string name = accounts[temp_pair.first][0];
            unordered_set<string>& emailset = temp_pair.second;
            vector<string> emaillist = vector<string>(emailset.begin(),emailset.end());
            sort(emaillist.begin(),emaillist.end());
            vector<string> item;
            item.push_back(name);
            for(int i=0;i<emaillist.size();i++)
            {
                item.push_back(emaillist[i]);
            }
            result.push_back(item);
        }
        
        return result;
        
    }
    
    int findParent(vector<int>& parents,int cur)
    {
        if(parents[cur] == cur)
        {
            return cur;
        }
        int root = findParent(parents,parents[cur]);
        parents[cur] = root;
        return parents[cur];
    }
};