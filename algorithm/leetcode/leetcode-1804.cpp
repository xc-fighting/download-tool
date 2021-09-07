struct TrieNode
{
public:
    vector<TrieNode*> children;
    bool isEnd;
    int count;
    TrieNode()
    {
        count = 0;
        isEnd = false;
        children = vector<TrieNode*>(26,nullptr);
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] - 'a';
            if(current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
        current->count++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] -'a';
            if(current->children[index] == nullptr)
            {
                return 0;
            }
            current = current->children[index];
        }
        if(current->isEnd == true)
        {
            return current->count;
        }
        return 0;
    }
    
    int countWordsStartingWith(string prefix) {
        
    }
    
    void erase(string word) {
        stack<TrieNode*> deleteStack;
       // stack<int> indexStack;
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i]-'a';
            if(current->children[index] == nullptr)
            {
                return;
            }
            current = current->children[index];
            deleteStack.push(current);
            //indexStack.push(i);
        }
        if(current->isEnd == false)
        {
            return;
        }
        //the case it is already end
        while(deleteStack.empty()==false)
        {
            
            TrieNode* candidate = deleteStack.top();
            deleteStack.pop();
            TrieNode** addr = &candidate;
            
            bool allEmpty = true;
            for(int i=0;i<candidate->children.size();i++)
            {
                if(candidate->children[i] != nullptr)
                {
                    allEmpty = false;
                    break;
                }
            }
            if(allEmpty== true)
            {
                *addr = nullptr;
            }
            else
            {
                break;
            }
            
        }
        return;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */



/// solution below

struct TrieNode
{
public:
    vector<TrieNode*> children;
    bool isEnd;
    int count;
    TrieNode()
    {
        count = 0;
        isEnd = false;
        children = vector<TrieNode*>(26,nullptr);
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] - 'a';
            if(current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
        current->count++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] -'a';
            if(current->children[index] == nullptr)
            {
                return 0;
            }
            current = current->children[index];
        }
        if(current->isEnd == true)
        {
            return current->count;
        }
        return 0;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* current = root;
        for(int i=0;i<prefix.size();i++)
        {
            int index = prefix[i] - 'a';
            if(current->children[index] == nullptr)
            {
                return 0;
            }
            current = current->children[index];
            
        }
        return getCounts(current);
    }
    
    int getCounts(TrieNode* node)
    {
        int result = 0;
        if(node->isEnd == true)
        {
            result = node->count;
        }
        for(int i=0;i<node->children.size();i++)
        {
            if(node->children[i] != nullptr)
            {
                result += getCounts(node->children[i]);
            }
        }
        return result;
    }
        
    
    void erase(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] - 'a';
            if(current->children[index] == nullptr)
            {
                return;
            }
            current = current->children[index];
            
        }
        if(current->isEnd == false)
        {
            return;
        }
        if(current->count > 0)
        {
            current->count = (current->count) - 1;
        }
        return;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */