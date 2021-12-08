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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        int curStep = 0;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr && curStep < n) {
            
            cur = cur->next;
            curStep++;
        }
        
        ListNode* deleteNode = head;
        while(cur != nullptr) {
            prev = deleteNode;
            deleteNode = deleteNode->next;
            cur = cur->next;
        }
        
        if(prev == nullptr) {
            
            ListNode* newhead = head->next;
            head->next = nullptr;
            return newhead;
            
        }
        
        ListNode* newNext = deleteNode->next;
        deleteNode->next = nullptr;
        prev->next = newNext;
        return head;
    }
};