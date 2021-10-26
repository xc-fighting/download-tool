/*
Revenue Milestones
We keep track of the revenue Facebook makes every day, and we want to know on what days Facebook hits certain revenue milestones. Given an array of the revenue on each day, and an array of milestones Facebook wants to reach, return an array containing the days on which Facebook reached every milestone.
Signature
int[] getMilestoneDays(int[] revenues, int[] milestones)
Input
revenues is a length-N array representing how much revenue FB made on each day (from day 1 to day N). milestones is a length-K array of total revenue milestones.
Output
Return a length-K array where K_i is the day on which FB first had milestones[i] total revenue. If the milestone is never met, return -1.
Example
revenues = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
milestones = [100, 200, 500]
output = [4, 6, 10]
Explanation
On days 4, 5, and 6, FB has total revenue of $100, $150, and $210 respectively. Day 6 is the first time that FB has >= $200 of total revenue.



*/


#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
int getDayReachMileStone(vector<int>& input, int target) {
   //find the first day which is larger than this target
   int left = 0;
   int right = input.size() - 1;
   while( left + 1 < right ) {
      int mid = left + (right - left) / 2;
      if( input[mid] >= target ) {
          right = mid;
      }
      else {
          left = mid;
      }
   }
   if( input[left] >= target ) {
       return left + 1;
   }
   if( input[right] >= target ) {
       return right + 1;
   }
   return -1;
}

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  // Write your code here
  int len = revenues.size();
  vector<int> revenueSum(len , 0);
  revenueSum[0] = revenues[0];
  for( int index = 1; index < revenues.size(); index++ ) {
     revenueSum[index] = revenueSum[index-1] + revenues[index];
  }
  int k = milestones.size();
  vector<int> result(k, -1);
  for( int index = 0; index < k; index++ ) {
     int day = getDayReachMileStone(revenueSum, milestones[index]);
     result[index] = day;
  }
  return result;
}