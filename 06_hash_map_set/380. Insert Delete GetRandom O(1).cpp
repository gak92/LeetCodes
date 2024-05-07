/*
https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
private:
  vector<int> vec;
  unordered_map<int, int> mp;

public:
  RandomizedSet()
  {
  }

  bool insert(int val)
  {
    if (mp.find(val) != mp.end()) // val already present
      return false;

    vec.push_back(val);
    mp[val] = vec.size() - 1;
    return true;
  }

  bool remove(int val)
  {
    if (mp.find(val) == mp.end()) // if not present
      return false;

    int idx = mp[val];        // get index of element to be remove
    int lastVal = vec.back(); // store last element
    vec.back() = val;

    vec[idx] = lastVal; // move last element to the index
    mp[lastVal] = idx;  // update index of last element

    vec.pop_back(); // remove the given element
    mp.erase(val);  // remove also from map

    return true;
  }

  int getRandom()
  {
    int n = vec.size();
    int randIdx = rand() % n;
    return vec[randIdx];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
  RandomizedSet *obj = new RandomizedSet();
  cout << obj->insert(1) << endl;
  cout << obj->remove(2) << endl;
  cout << obj->insert(2) << endl;
  cout << obj->getRandom() << endl;
  cout << obj->remove(1) << endl;
  cout << obj->insert(2) << endl;
  cout << obj->getRandom() << endl;
  return 0;
}