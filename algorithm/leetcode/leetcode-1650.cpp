/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    
public:
    Node* getParent(Node* n1, Node* n2) {
        while( n1 != n2 ) {
            n1 = n1->parent;
            n2 = n2->parent;
        }
        return n1;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int distanceP = 0;
        int distanceQ = 0;
        Node* curP = p;
        Node* curQ = q;
        while( curP != nullptr ) {
            curP = curP->parent;
            distanceP++;
        }
        
        while( curQ != nullptr ) {
            curQ = curQ->parent;
            distanceQ++;
        }
        
        // three case
        // distance P == distance Q
        if( distanceP == distanceQ ) {
            return getParent(p,q);
        }
        // distance P < distance q
        if( distanceP < distanceQ ) {
            int diff = distanceQ - distanceP;
            int move = 0;
            while(move < diff) {
                q = q->parent;
                move++;
            }
            if( p == q ) {
                return p;
            }
            return getParent(p,q);
        }
        else {
            int diff = distanceP - distanceQ;
            int move = 0;
            while( move < diff ) {
                p = p->parent;
                move++;
            }
            if( p == q ) {
                return q;
            }
            return getParent(p,q);
        }
    }
};