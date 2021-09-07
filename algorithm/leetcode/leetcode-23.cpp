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
class Compare
{
public:
    bool operator()(ListNode* lhs,ListNode* rhs)
    {
        if(lhs->val == rhs->val)
        {
            return true;
        }
        if(lhs->val < rhs->val)
        {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        ListNode* newhead = nullptr;
        ListNode* curTail = nullptr;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i] != nullptr)
            {
                pq.push(lists[i]);
            }
            
        }
        while(pq.empty()==false)
        {
            ListNode* topNode = pq.top();
            pq.pop();
            if(newhead == nullptr)
            {
                newhead = topNode;
                curTail = topNode;
            }
            else
            {
                curTail->next = topNode;
                curTail = curTail->next;
            }
            if(topNode->next != nullptr)
            {
                pq.push(topNode->next);
                topNode->next = nullptr;
            }
        }
        return newhead;
    }
};