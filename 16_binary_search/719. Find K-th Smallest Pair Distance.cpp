/*
https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
*/

// Check array and heap folders for other approaches
// Method - Binary Search (Optimal Approach)

class Solution {
private:
    int slidingWindowCount(vector<int>& nums, int D)
    {
        int i = 0;
        int j = 1;
        int n = nums.size();
        int pairCount = 0;

        while(j < n) {
            while(nums[j] - nums[i] > D)
                i++;

            pairCount += (j - i);
            j++;
        }

        return pairCount;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());     // n*log(n)

        int l = 0;
        int r = nums[n-1] - nums[0];

        int res = 0;

        while(l <= r) {     // n*log(M)
            int mid = l + (r-l) / 2;

            int countPair = slidingWindowCount(nums, mid);

            if(countPair < k) {
                l = mid + 1;
            }
            else {
                res = mid;
                r = mid - 1;
            }
        }

        return res;
    }
};
