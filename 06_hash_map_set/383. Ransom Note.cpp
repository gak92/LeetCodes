/*
https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        for(auto& ch:magazine)
            freq[ch]++;

        for(auto& ch:ransomNote) {
            if(freq[ch] == 0)
                return false;
            freq[ch]--;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.canConstruct("a", "b")<<endl;
    cout<<s.canConstruct("aa", "ab")<<endl;
    cout<<s.canConstruct("aa", "aab")<<endl;
    
 return 0;
}