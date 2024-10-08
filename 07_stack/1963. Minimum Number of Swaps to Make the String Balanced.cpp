/*
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/
*/

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char& ch: s) {
            if(ch == '[')
                st.push(ch);
            else if(!st.empty())
                st.pop();
        }

        return (st.size() + 1) / 2;
    }
};
