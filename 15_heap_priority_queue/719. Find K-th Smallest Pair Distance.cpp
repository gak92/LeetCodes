/*
https://leetcode.com/problems/find-k-th-smallest-pair-distance/submissions/
*/

// Check other methods in array and binary search folders

// =============================================================================
// Method # 03 - Using Max Heap (Time Limit Exceed)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>> pq;    // max-heap

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int val = abs(nums[i] - nums[j]);
                pq.push(val);

                if(pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};
