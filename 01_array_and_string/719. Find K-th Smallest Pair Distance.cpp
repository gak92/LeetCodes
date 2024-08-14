/*
https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
*/

// Check other methods in heap and binary search folders

// =================================================================================================
// Method # 01 - Brute Force (Time Limit Exceed)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                diff.push_back(abs(nums[i] - nums[j]));
            } 
        }

        sort(diff.begin(), diff.end());

        return diff[k-1];
    }
};

// =================================================================================================
// Method # 02 - Improve by counting distances (Accepted)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());
        vector<int> vec(maxElem+1, 0);

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        for(int i=0; i<vec.size(); i++) {
            k -= vec[i];
            if(k <= 0)
                return i;
        }

        return -1;
    }
};


// =================================================================================================
// Method # 03 - Using C++ builtin Utility (Accepted)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                diff.push_back(abs(nums[i] - nums[j]));
            } 
        }

        nth_element(diff.begin(), diff.begin() + (k-1), diff.end());

        return diff[k-1];
    }
};
