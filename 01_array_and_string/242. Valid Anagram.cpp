class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);

        for(char &ch : s) {
            count[ch - 'a']++;
        }

        for(char &ch : t) {
            count[ch - 'a']--;
        }

        bool all_zeroes = all_of(begin(count), end(count), [](int element) {
            return element == 0;
        });

        return all_zeroes;

        // for(int i=0; i<count.size(); i++) {
        //     if(count[i] != 0)
        //         return false;
        // }

        // return true;
    }
};
