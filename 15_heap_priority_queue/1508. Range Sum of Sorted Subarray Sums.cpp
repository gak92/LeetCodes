/*
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04
*/

class Solution {
private:
    typedef pair<int, int> P; // {subarray sum, end index of this subarray}
    int M = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;    // min heap

        for(int i=0; i<n; i++)
            pq.push({nums[i], i});

        int res = 0;

        for(int count=1; count<=right; count++) {
            auto p =  pq.top();
            pq.pop();

            int sum = p.first;
            int idx = p.second;

            if(count >= left)
                res = (res + sum) % M;

            int new_idx = idx + 1;
            P new_pair;
            if(new_idx < n) {
                new_pair.first  = nums[new_idx] + sum;
                new_pair.second = new_idx;
                pq.push(new_pair);
            }
        }

        return res;
    }
};
