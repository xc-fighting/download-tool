/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        int listLen = 0;
        ListNode* cur = head;
        while( cur != nullptr ) {
            cur = cur->next;
            listLen++;
        }
        int singleLen = listLen / k;
        int extra = listLen % k;
        
        
        cur = head;
        int index = 0;
        
        while( cur != nullptr ) {
            int curLen = 1;
            ListNode* start = cur;
            if( index < extra ) {
                singleLen++;
            }
            cout<<singleLen<<endl;
            while( cur != nullptr && curLen < singleLen ) {
                cur = cur->next;
                curLen++;
            }
            if( cur != nullptr ) {
                ListNode* nextNode = cur->next;
                cur->next = nullptr;
                result[index] = start;
                cur = nextNode;
            }
            else {
                result[index] = start;
            }
            index++;
            singleLen = listLen / k;
        }
        
        return result;
    }
};
