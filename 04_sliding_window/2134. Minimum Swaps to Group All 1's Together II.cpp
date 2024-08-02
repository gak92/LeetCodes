/*
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02
*/

// Approach # 01 (using extra space)
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(2*n);
        for(int i=0; i<2*n; i++)
            temp[i] = nums[i%n];

        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int i = 0;
        int j = 0;
        int currOnes = 0;
        int maxCount = 0;

        while(j < 2*n) {
            if(temp[j] == 1)
                currOnes++;

            if(j-i+1 > totalOnes) {
                currOnes -= temp[i];
                i++;
            }

            maxCount = max(maxCount, currOnes);
            j++; 
        }

        return totalOnes - maxCount;
    }
};


// Approach # 02 (not using any extra space)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int i = 0;
        int j = 0;
        int currOnes = 0;
        int maxCount = 0;

        while(j < 2*n) {
            if(nums[j%n] == 1)
                currOnes++;

            if(j-i+1 > totalOnes) {
                currOnes -= nums[i%n];
                i++;
            }

            maxCount = max(maxCount, currOnes);
            j++; 
        }

        return totalOnes - maxCount;
    }
};
