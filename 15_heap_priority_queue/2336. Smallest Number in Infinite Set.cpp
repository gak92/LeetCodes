/*
https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//=======================================================
// Solution # 03

class SmallestInfiniteSet
{
private:
  int currSmallest;
  set<int> st;

public:
  SmallestInfiniteSet()
  {
    currSmallest = 1;
  }

  int popSmallest()
  {
    int res;

    if (st.empty())
    {
      res = currSmallest;
      currSmallest++;
    }
    else
    {
      res = *st.begin();
      st.erase(*st.begin());
    }

    return res;
  }

  void addBack(int num)
  {
    if (num >= currSmallest || st.find(num) != st.end())
      return;

    st.insert(num);
  }
};

//=======================================================
// Solution # 02
/*
class SmallestInfiniteSet {
private:
    int currSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SmallestInfiniteSet() {
        currSmallest = 1;

    }

    int popSmallest() {
        int res;

        if(pq.empty()) {
            res = currSmallest;
            currSmallest++;
        } else {
            res = pq.top();
            pq.pop();
            st.erase(res);
        }

        return res;
    }

    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;

        st.insert(num);
        pq.push(num);
    }
};

*/

//=======================================================
// Solution # 01
/*
class SmallestInfiniteSet {
private:
    vector<bool> nums;
    int smallest;
public:
    SmallestInfiniteSet() {
        nums = vector<bool>(1001, true);
        smallest = 1;
    }

    int popSmallest() {
        int res = smallest;
        nums[smallest] = false;

        while(nums[smallest] != true) {
            smallest++;
        }

        return res;
    }

    void addBack(int num) {
        nums[num] = true;
        if(num < smallest)
            smallest = num;
    }
};

*/

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main()
{
  SmallestInfiniteSet *obj = new SmallestInfiniteSet();
  cout << obj->popSmallest() << endl;
  obj->addBack(1);
  cout << "Added 1" << endl;
  cout << obj->popSmallest() << endl;
  obj->addBack(1);
  cout << "Added another 1" << endl;
  cout << obj->popSmallest() << endl;
  cout << obj->popSmallest() << endl;
  cout << obj->popSmallest() << endl;
  cout << obj->popSmallest() << endl;
  cout << obj->popSmallest() << endl;
  cout << obj->popSmallest() << endl;
  cout << obj->popSmallest() << endl;
  cout << obj->popSmallest() << endl;

  return 0;
}