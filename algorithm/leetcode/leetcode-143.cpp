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
    ListNode* reverse(ListNode* head) {
        ListNode* newhead = nullptr;
        ListNode* cur = head;
        while( cur != nullptr ) {
            ListNode* curNext = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = curNext;
        }
        return newhead;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr 
           || head->next == nullptr 
           || head->next->next == nullptr) {
            return;
        }
        //find the mid point
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast != nullptr && fast->next != nullptr ) {
             slow = slow->next;
             fast = fast->next->next;
        }
        //break it, slow is the mid part 
        ListNode* rightPart = slow->next;
        slow->next = nullptr;
        //reverse the right part
        rightPart = reverse(rightPart);
        //connect two together
        ListNode* leftPart = head;
        ListNode* newhead = nullptr;
        ListNode* cur = nullptr;
        while( leftPart != nullptr && rightPart != nullptr ) {
            ListNode* leftNext = leftPart->next;
            ListNode* rightNext = rightPart->next;
            leftPart->next = nullptr;
            rightPart->next = nullptr;
            if( newhead == nullptr ) {
                newhead = leftPart;
                leftPart->next = rightPart;
                cur = rightPart;
                leftPart = leftNext;
                rightPart = rightNext;
            }
            else {
                cur->next = leftPart;
                leftPart->next = rightPart;
                cur = rightPart;
                leftPart = leftNext;
                rightPart = rightNext;
            }
        }
        
        if( leftPart != nullptr ) {
            cur->next = leftPart;
        
        }
        
        if( rightPart != nullptr ) {
            cur->next = rightPart;
            
        }
        head = newhead;
        return;
        
    }
};