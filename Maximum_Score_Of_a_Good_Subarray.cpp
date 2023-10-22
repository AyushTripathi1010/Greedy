// Problem Link :https://leetcode.com/problems/maximum-score-of-a-good-subarray/

// Problem: You are given an array of integers nums (0-indexed) and an integer k.
// The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). 
// A good subarray is a subarray where i <= k <= j.
// Return the maximum possible score of a good subarray.


// INTUITION: From the question we can crefully observe that whatever subbarray we take it should include the kth index
// So to always ensure that kth index is present in my subbarray, i will start loop using 2 pointers from kth index itself and
// go to left and right directions from kth index.

// Now the question arises in which direction i should go left or right? 
// So if we thing greedily, i will go that direction which has maximum value so that minium element doesn;t decrease too much 
// because the minimum is getting multiplied, by length, so i will try to keep minimum as large as possible.
// SO i will go to direction which gives larger value.

// Why are we not going into smaller direction first?
//  Consider eg: [2,7,4,5], k = 1, so K is pointing to index 1, i = 1, j=1. Now lets go to left direction
// that is i pointer is now pointing to index 0. result = min(2,7)*(j-i+1) = 4.
// Now even if i go to right side to include larger values, the score will increase because minimum will still remain 2, but the
// length increases.
// In the 1st scenario when i am first moving to left direction and towards right direction, the maximum score i will get is 8.

// In the 2nd scenario which is our greedy approach, we first move to right direction towards larger value, so from right direction the 
// minimum element is 4 which will be multiplied to j-i+1 to get 12. and now if even i move to left direction, my currMin will change to 2.
// and score will become 8, but since i have already stored the maximum score of 12. So my answer will not be impacted.

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
           
           int n = nums.size();
           int i = k, j =k;
           int currMin = nums[k];
           int result = nums[k];

           while(i> 0 || j < n-1)
           {
               int lftValue = i > 0 ? nums[i-1] : 0;
               int rhtValue = j <n-1 ? nums[j+1] : 0;

               if(lftValue < rhtValue)
               {
                   j++;
                   currMin = min(currMin , nums[j]);
               }
               else
               {
                   i--;
                   currMin = min(currMin , nums[i]);
               }

               result = max(result, currMin*(j-i+1));
           }

           return result;


    }
};