/*
https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01
*/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(auto& detail : details)
        {
            int firstDigit  = detail[11] - '0';
            int secondDigit = detail[12] - '0';

            int age = firstDigit * 10 + secondDigit;
            if(age > 60)
                count++;
        }

        return count;
    }
};
