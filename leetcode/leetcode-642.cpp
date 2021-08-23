struct TrieNode
{
public:
    vector<TrieNode*> children;
    string content;
    bool isEnd;
    int count;
    TrieNode()
    {
        this->isEnd = false;
        this->content = "";
        // one extra for ' '
        this->children = vector<TrieNode*>(27,nullptr);
        this->count = 0;
    }
    
};

class Compare
{
public:
    bool operator()(pair<string,int>& lhs, pair<string,int>& rhs)
    {
        if(lhs.second == rhs.second)
        {
            if(strcmp(lhs.first.c_str(),rhs.first.c_str()) < 0)
            {
                return false;
            }
            return true;
        }
        else if(lhs.second < rhs.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};
class AutocompleteSystem {
private:
    string buffer;
    TrieNode* root;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        int size = sentences.size();
        for(int i=0;i<size;i++)
        {
            TrieNode* current = root;
            for(int j=0;j<sentences[i].size();j++)
            {
                char ch = sentences[i][j];
                int index = -1;
                if(ch == ' ')
                {
                    index = 26;
                }
                else
                {
                    index = ch - 'a';
                }
                if(current->children[index] == nullptr)
                {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
            }
            current->isEnd = true;
            current->count = current->count + times[i];
            current->content = sentences[i];
        }
        return;
    }
    
    void insertContent(string content)
    {
        TrieNode* current = root;
        for(int i=0;i<content.size();i++)
        {
            char ch = content[i];
            int index = -1;
            if(ch == ' ')
            {
                index = 26;
            }
            else
            {
                index = ch - 'a';
            }
            if(current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
        current->count += 1;
        current->content = content;
        return;
    }
    
    void getRemains(TrieNode* root, vector<pair<string,int>>& result)
    {
        //base condition when the current node is already end
        if(root->isEnd == true)
        {
            pair<string,int> temp(root->content,root->count);
            result.push_back(temp);
        }
        for(int i=0;i<=26;i++)
        {
            if(root->children[i] == nullptr)
            {
                continue;
            }
            else
            {
                getRemains(root->children[i],result);
            }
        }
        return;
        
    }
    
    vector<string> getHot(string prefix)
    {
        TrieNode* current = root;
        for(int i=0;i<prefix.size();i++)
        {
            char ch = prefix[i];
            int index = -1;
            if(ch == ' ')
            {
                index = 26;
            }
            else
            {
                index = ch - 'a';
            }
            if(current->children[index] == nullptr)
            {
                return vector<string>();
            }
            current = current->children[index];
        }
        vector<pair<string,int>> tempbuffer;
        getRemains(current,tempbuffer);
        priority_queue<pair<string,int>,vector<pair<string,int>>,Compare> pq;
        for(int index = 0; index < tempbuffer.size();index++)
        {
            pq.push(tempbuffer[index]);
        }
        
        int popSize = 3;
        if(pq.size()<3)
        {
            popSize = pq.size();
        }
        int currentPop = 0;
        vector<string> result;
        while(currentPop < popSize)
        {
            result.push_back(pq.top().first);
            pq.pop();
            currentPop++;
        }
        return result;
    }
    
    vector<string> input(char c) {
        if(c == '#')
        {
            insertContent(buffer);
            buffer = "";
            return vector<string>();
        }
        else
        {
            buffer = buffer + c;
            return getHot(buffer);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */