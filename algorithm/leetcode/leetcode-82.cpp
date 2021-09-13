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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* newcur = dummy;
        ListNode* cur = head;
        while(cur != nullptr) {
            //look ahead
            if(cur->next != nullptr) {
                int curVal = cur->val;
                if(cur->next->val != curVal) {
                    newcur->next = cur;
                    ListNode* oldnext = cur->next;
                    cur->next = nullptr;
                    newcur = newcur->next;
                    cur = oldnext;
                }
                else {
                    ListNode* duplicate = cur->next;
                    ListNode* pre = cur;
                    while(duplicate != nullptr && duplicate->val == curVal) {
                        pre = duplicate;
                        duplicate = duplicate->next;
                    }
                   
                    pre->next = nullptr;
                    cur = duplicate;
                    newcur->next = nullptr;
                    
                }
            }
            else {
                newcur->next = cur;
                newcur = newcur->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};