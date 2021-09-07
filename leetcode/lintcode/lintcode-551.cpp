/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList) {
        // Write your code here
        int result = 0;
        for(int i=0;i<nestedList.size();i++)
        {
            result += getSum(nestedList[i],1);
        }
        return result;
    }
    int getSum(const NestedInteger& root,int depth)
    {
       if(root.isInteger())
       {
           return depth*root.getInteger();
       }
       const vector<NestedInteger>& integerList = root.getList();
       int result = 0;
       for(int i=0;i < integerList.size(); i++ )
       {
           result += getSum(integerList[i],depth+1);
       }
       return result;
    }
};



/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList) {
         
         int result = 0;
         for(int i=0;i<nestedList.size();i++)
         {
            result += expand(nestedList[i]);
         }
         return result;
    }

    int expand(const NestedInteger& root)
    {
        stack<pair<const NestedInteger&,int>> traverseStack;
        traverseStack.push(pair<const NestedInteger&,int>(root,1));
        int result = 0;
        while(traverseStack.empty()==false)
        {
           pair<const NestedInteger&,int> topPair = traverseStack.top();
           traverseStack.pop();
           const NestedInteger& topElem = topPair.first;
           int depth = topPair.second;
           if(topElem.isInteger())
           {
               result += topElem.getInteger() * depth;
           }
           else
           {
               const vector<NestedInteger>& list = topElem.getList();
               for(int i=0;i<list.size();i++)
               {
                   traverseStack.push(pair<const NestedInteger&,int>(list[i],depth+1));
               }
           }
        }
        return result;
    }
   
};