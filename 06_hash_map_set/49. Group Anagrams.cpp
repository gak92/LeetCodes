/*
https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for(int i=0; i<n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            mp[temp].push_back(strs[i]);
        }

        for(auto& it:mp) {
            res.push_back(it.second);
        }

        return res;
    }
};

*/

class Solution
{
private:
  string generate(string word)
  {
    string newWord = "";
    int arr[26] = {0};

    for (auto &ch : word)
      arr[ch - 'a']++;

    for (int i = 0; i < 26; i++)
    {
      int freq = arr[i];
      if (freq > 0)
        newWord += string(freq, i + 'a');
    }

    return newWord;
  }

public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    int n = strs.size();
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < n; i++)
    {
      string word = strs[i];

      string newWord = generate(word);
      mp[newWord].push_back(word);
    }

    for (auto &it : mp)
    {
      res.push_back(it.second);
    }

    return res;
  }
};

int main()
{
  Solution obj;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> res = obj.groupAnagrams(strs);

  for (auto &v : res)
  {
    for (auto &str : v)
    {
      cout << str << " ";
    }
    cout << endl;
  }
  return 0;
}