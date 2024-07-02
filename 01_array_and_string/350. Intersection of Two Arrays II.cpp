/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        vector<int> res;

        for (auto &num : nums1)
            mp[num]++;

        for (int i = 0; i < nums2.size(); i++)
        {
            int num = nums2[i];
            if (mp[num] > 0)
            {
                mp[num]--;
                res.push_back(num);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}