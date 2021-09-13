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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        queue<ListNode*> nodeQueue;
        ListNode* temp = head;
        unordered_map<int,int> valueFreq;
        while(temp != nullptr) {
            int value = temp->val;
            if(valueFreq.find(value) == valueFreq.end()) {
                valueFreq[value] = 0;
            }
            valueFreq[value]++;
            nodeQueue.push(temp);
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(nodeQueue.empty()==false) {
            ListNode* frontNode = nodeQueue.front();
            nodeQueue.pop();
            int frontValue = frontNode->val;
            if(valueFreq[frontValue] == 1) {
                frontNode->next = nullptr;
                cur->next = frontNode;
                cur = cur->next;
            }
            else {
                frontNode->next = nullptr;
               // delete frontNode;
            }
        }
        return dummy->next;
    }
};


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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
       
        ListNode* temp = head;
        unordered_map<int,int> valueFreq;
        while(temp != nullptr) {
            int value = temp->val;
            if(valueFreq.find(value) == valueFreq.end()) {
                valueFreq[value] = 0;
            }
            valueFreq[value]++;
           
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* traverse = head;
        while(traverse != nullptr) {
            ListNode* nextNode = traverse->next;
            int curVal = traverse->val;
            if(valueFreq[curVal] == 1) {
                
                cur->next = traverse;
                cur= cur->next;
            }
            traverse->next = nullptr;
            traverse = nextNode;
        }
        return dummy->next;
    }
};