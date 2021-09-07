/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        
        RandomListNode* cur = head;
        RandomListNode* newhead = nullptr;
        //first round copy the node and connect it
        while(cur!=nullptr)
        {
            RandomListNode* curNext = cur->next;
            cur->next = nullptr;
            RandomListNode* newNode = new RandomListNode(cur->label);
            cur->next = newNode;
            newNode->next = curNext;
            cur = curNext;
        }
        //second round connect the random node pointer
        cur = head;
        while(cur != nullptr)
        {
            if(cur->random != nullptr)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        //unlink the node
        cur = head;
        RandomListNode* newcur = nullptr;
        while(cur != nullptr)
        {
           RandomListNode* oldNext = cur->next->next;
           RandomListNode* newNext = cur->next;
           if(newhead == nullptr)
           {
               newhead = newNext;
               newcur = newNext;
           }
           else
           {
               newcur->next = newNext;
               newcur = newcur->next;
           }
           newNext->next = nullptr;
           cur->next = oldNext;
           cur = cur->next;
        }
        return newhead;

    }
};