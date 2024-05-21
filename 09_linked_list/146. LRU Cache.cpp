/*
https://leetcode.com/problems/lru-cache/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
  list<int> dll; // doubly linked list
  map<int, pair<list<int>::iterator, int>> mp;
  int n;

  void makeRecentlyUsed(int key)
  {
    // remove from the list
    dll.erase(mp[key].first);

    // push back at front so it is recently used
    dll.push_front(key);

    // update address on the map
    mp[key].first = dll.begin();
  }

public:
  LRUCache(int capacity)
  {
    n = capacity;
  }

  int get(int key)
  {
    if (mp.find(key) == mp.end()) // key not found
      return -1;

    // if key found, make it recently used
    makeRecentlyUsed(key);

    return mp[key].second; // return the value
  }

  void put(int key, int value)
  {
    // if key already in map, update it
    if (mp.find(key) != mp.end())
    {
      mp[key].second = value;
      makeRecentlyUsed(key);
    }
    // if key not present, add it
    else
    {
      dll.push_front(key);
      mp[key] = {dll.begin(), value};
      n--;
    }

    // if size increase from capacity then remove from the back
    if (n < 0)
    {
      int keyToBeDelete = dll.back();
      mp.erase(keyToBeDelete);
      dll.pop_back();
      n++;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
  LRUCache *obj = new LRUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  cout << obj->get(1) << endl;
  obj->put(3, 3);
  cout << obj->get(2) << endl;
  obj->put(4, 4);
  cout << obj->get(1) << endl;
  cout << obj->get(3) << endl;
  cout << obj->get(4) << endl;
  return 0;
}

/*
// Time Limit Exceed (Brute Force)

class LRUCache {
private:
    vector<pair<int, int>> cache;
    int n;
public:
    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {

        for(int i=0; i<cache.size(); i++)
        {
            if(cache[i].first == key) {
                int val = cache[i].second;

                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);

                return val;
            }
        }

        return -1;
    }

    void put(int key, int value) {

        for(int i=0; i<cache.size(); i++) {
            if(cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        if(cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        }
        else {
            cache.push_back({key, value});
        }
    }
};


*/