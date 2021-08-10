class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)
        {
            return "";
        }
        int len = palindrome.size();
        int half_index = (len/2) - 1;
        for(int i=0;i<=half_index;i++)
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[len-1] = 'b';
        return palindrome;
    }
};