/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
struct comp {
public:
   bool operator()(ListNode* lhs, ListNode* rhs) {
       if( lhs->val < rhs->val ) {
           return false;
       }
       return true;
   }
};
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* newHead = nullptr;
        ListNode* cur = nullptr;
        for( int idx = 0; idx < lists.size(); idx++ ) {
            if( lists[idx] == nullptr ) {
                //skip it 
                continue;
            }
            pq.push(lists[idx]);
        }
        while( pq.empty() == false ) {
            ListNode* frontNode = pq.top();
            pq.pop();
            if( newHead == nullptr ) {
                newHead = frontNode;
                cur = frontNode;
            }
            else {
                 cur->next = frontNode;
                 cur = cur->next;
            }
            if( frontNode->next != nullptr ) {
                pq.push(frontNode->next);
            }
        }
        return newHead;
    }
};