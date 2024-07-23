/*
https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23
*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto& num : nums)
            mp[num]++;

        
        auto lambda = [&](int& num1, int& num2) {
            if(mp[num1] == mp[num2])
                return num1 > num2;

            return mp[num1] < mp[num2];
        };

        sort(nums.begin(), nums.end(), lambda);

        return nums;
    }
};
