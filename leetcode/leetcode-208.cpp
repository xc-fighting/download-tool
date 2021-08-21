struct TrieNode
{
  public:
       vector<TrieNode*> children;
       bool isEnd;
       TrieNode()
       {
           children = vector<TrieNode*>(26,nullptr);
           isEnd = false;
       }
};
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            int index = ch - 'a';
            if(current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] - 'a';
            if(current->children[index]==nullptr)
            {
                return false;
            }
            else
            {
                current = current->children[index];
            }
        }
        if(current->isEnd == true)
        {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         TrieNode* current = root;
        for(int i=0;i<prefix.size();i++)
        {
            int index = prefix[i] - 'a';
            if(current->children[index]==nullptr)
            {
                return false;
            }
            else
            {
                current = current->children[index];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */