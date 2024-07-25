/*
https://leetcode.com/problems/sort-an-array/description/?envType=daily-question&envId=2024-07-25
*/

// Using Count Sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(auto& num : nums)
            mp[num]++;

        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());

        int idx = 0;
        for(int num = minEle; num <= maxEle; num++)
        {
            while(mp[num] > 0) {
                nums[idx] = num;
                idx++;
                mp[num]--;
            }
        }

        return nums;
    }
};
