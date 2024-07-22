/*
https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22
*/

// Approach # 01

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> p(n);

        for(int i=0; i<n; i++) {
            p[i] = make_pair(names[i], heights[i]);
        }

        auto lambda = [](auto& p1, auto& p2) {
            return p1.second > p2.second;
        };
        
        sort(p.begin(), p.end(), lambda);

        for(int i=0; i<n; i++) {
            names[i] = p[i].first;
        }

        return names;
    }
};

// Approach # 02
/*

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> p(n);

        for(int i=0; i<n; i++) {
            p[i] = make_pair(heights[i], names[i]);
        }

        sort(p.rbegin(), p.rend());

        for(int i=0; i<n; i++) {
            names[i] = p[i].second;
        }

        return names;
    }
};

*/

// Approach # 3 (using hashmap)
/*

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> mp;

        for(int i=0; i<n; i++) {
            mp[heights[i]] = names[i];
        }

        sort(heights.rbegin(), heights.rend());

        for(int i=0; i<n; i++) {
            names[i] = mp[heights[i]];
        }

        return names;
    }
};

*/
