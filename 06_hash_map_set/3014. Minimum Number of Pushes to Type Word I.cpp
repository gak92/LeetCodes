/*
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/
*/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> mp;
        int res = 0;
        int assignKey = 2;

        for(auto& ch : word) {
            if(assignKey > 9)
                assignKey = 2;

            mp[assignKey]++;
            res += mp[assignKey];
            assignKey++;
        }

        return res;
    }
};
