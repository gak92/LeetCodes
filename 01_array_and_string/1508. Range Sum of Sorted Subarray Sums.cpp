/*
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04
*/

class Solution {
private:
    int M = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySum;

        for(int i=0; i<n; i++) {
            int summ = 0;
            for(int j=i; j<n; j++) {
                summ += nums[j];
                subarraySum.push_back(summ);
            }
        }

        sort(subarraySum.begin(), subarraySum.end());

        int res = 0;
        for(int i=left-1; i<=right-1; i++) {
            res = (res + subarraySum[i]) % M;
        }

        return res;
    }
};
