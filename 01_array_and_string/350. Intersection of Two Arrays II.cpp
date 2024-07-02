/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02
/*

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return res;
    }
};

*/

// Solution # 01
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
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution obj;
    vector<int> res = obj.intersect(nums1, nums2);
    for (auto &num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}