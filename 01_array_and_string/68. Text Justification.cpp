/*
https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int MAX_WIDTH;
  string createLine(int i, int j, int eachSlotSpaces, int extraSpaces, vector<string> &words)
  {
    string line;

    for (int k = i; k < j; k++)
    {
      line += words[k]; // add word into line

      if (k == j - 1)
      {
        continue;
      }

      for (int z = 1; z <= eachSlotSpaces; z++)
      {
        line += " ";
      }

      if (extraSpaces > 0)
      {
        line += " ";
        extraSpaces--;
      }
    }

    while (line.length() < MAX_WIDTH)
    {
      line += " ";
    }

    return line;
  }

public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    vector<string> res;
    int n = words.size();
    MAX_WIDTH = maxWidth;

    int i = 0;

    while (i < n)
    {
      int lettersCount = words[i].length(); // 4 (This)
      int j = i + 1;                        // j ---> is
      int emptySlots = 0;

      // counting no. of letters in the line, and how many empty slots
      while (j < n && words[j].length() + 1 + emptySlots + lettersCount <= MAX_WIDTH)
      {
        lettersCount += words[j].length();
        emptySlots++;
        j++;
      }

      int remainingSlots = MAX_WIDTH - lettersCount;
      int eachSlotSpaces = emptySlots == 0 ? 0 : remainingSlots / emptySlots;
      int extraSpaces = emptySlots == 0 ? 0 : remainingSlots % emptySlots;

      if (j == n)
      { // last line left justified
        eachSlotSpaces = 1;
        extraSpaces = 0;
      }

      res.push_back(createLine(i, j, eachSlotSpaces, extraSpaces, words));
      i = j;
    }

    return res;
  }
};

int main()
{
  vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;
  Solution s;
  vector<string> res = s.fullJustify(words, maxWidth);

  for (auto &str : res)
  {
    cout << str << endl;
  }

  return 0;
}