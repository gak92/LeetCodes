/*
https://leetcode.com/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=leetcode-75
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        if(left == right)
            return left;
        int pivot = nums[left];
        int i = left;
        int j = right;

        while(i <= j) {
            if(nums[i] < pivot && nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= pivot)
                i++;
            if(nums[j] <= pivot)
                j--;
        }
        swap(nums[j], nums[left]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // Solution # 03
        int left = 0;
        int right = nums.size() - 1;
        int pivotIdx;

        // partition in descending order - (kth largest = nums[k-1])
        while(true) {
            pivotIdx = partition(nums, left, right);
            if(pivotIdx == k-1)
                break;
            else if(pivotIdx > k-1)
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }

        return nums[pivotIdx];

        // Solution # 02 - O(n*logk) (using minheap)
        // priority_queue<int, vector<int>, greater<int>> pq;    // default max heap
        // for(int& num:nums) {
        //     pq.push(num);
        //     if(pq.size() > k)
        //         pq.pop();
        // }
        // return pq.top();


        // Solution # 01 - O(n*logn)
        // sort(nums.begin(), nums.end(), greater<int>());
        // return nums[k-1];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<s.findKthLargest(nums, k)<<endl;
 return 0;
}