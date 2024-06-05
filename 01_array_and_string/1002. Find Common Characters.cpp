/*
https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void fillCount(string &word, int count[26])
  {
    for (auto &ch : word)
      count[ch - 'a']++;
  }

public:
  vector<string> commonChars(vector<string> &words)
  {

    vector<string> res;
    int count[26] = {0};
    fillCount(words[0], count);

    for (int i = 1; i < words.size(); i++)
    {
      int temp[26] = {0};
      fillCount(words[i], temp);

      for (int j = 0; j < 26; j++)
        count[j] = min(count[j], temp[j]);
    }

    for (int i = 0; i < 26; i++)
    {
      int freq = count[i];
      while (freq--)
        res.push_back(string(1, i + 'a'));
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<string> words = {"bella", "label", "roller"};
  vector<string> res = s.commonChars(words);

  for (auto &str : res)
    cout << str << " ";
  cout << endl;

  return 0;
}