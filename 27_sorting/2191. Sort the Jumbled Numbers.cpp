/*
https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24
*/

class Solution {
private:
    string getMappedNum(string numStr, vector<int>& mapping)
    {
        string str;
        for(int i=0; i<numStr.length(); i++)
        {
            char ch = numStr[i];
            int idx = ch - '0';

            str += to_string(mapping[idx]);
        }

        return str;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i=0; i<n; i++)
        {
            string numStr = to_string(nums[i]);
            string mappedStr = getMappedNum(numStr, mapping);
            vec.push_back({stoi(mappedStr), i});
        }

        sort(vec.begin(), vec.end());

        vector<int> res;
        for(auto& p : vec)
        {
            int idx = p.second;
            res.push_back(nums[idx]);
        }

        return res;
    }
};
