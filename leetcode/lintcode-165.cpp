/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        // write your code here
        if(l1 == nullptr)
        {
            return l2;
        }
        if(l2 == nullptr)
        {
            return l1;
        }
        ListNode* newhead = nullptr;
        ListNode* newcur = nullptr;
        
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                ListNode* nextNode =  l1->next;
                l1->next = nullptr;
                if(newhead == nullptr)
                {
                    newhead = l1;
                    newcur = l1;

                }
                else
                {
                    newcur->next = l1;
                    newcur = newcur->next;
                }
                l1 = nextNode;
            }
            else
            {
               ListNode* nextNode = l2->next;
               l2->next = nullptr;
               if(newhead == nullptr)
               {
                   newhead = l2;
                   newcur = l2;
               }
               else
               {
                   newcur->next = l2;
                   newcur = newcur->next;
               }
               l2 = nextNode;
            }
        }
        if(l1 != nullptr)
        {
            newcur->next = l1;
        }
        if(l2 != nullptr)
        {
            newcur->next = l2;
        }
        return newhead;
    }
};