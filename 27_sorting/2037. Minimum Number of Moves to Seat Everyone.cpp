/*
https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minMovesToSeat(vector<int> &seats, vector<int> &students)
  {

    int maxIdx = max(*max_element(seats.begin(), seats.end()),
                     *max_element(students.begin(), students.end())) +
                 1;
    vector<int> count_seats(maxIdx, 0);
    vector<int> count_students(maxIdx, 0);

    for (auto &seat : seats)
      count_seats[seat]++;

    for (auto &student : students)
      count_students[student]++;

    int i = 0; // for seats
    int j = 0; // for students
    int res = 0;
    int remaining = seats.size();

    while (remaining)
    {
      if (count_seats[i] == 0)
        i++;

      if (count_students[j] == 0)
        j++;

      if (count_seats[i] && count_students[j])
      {
        res += abs(i - j);
        count_seats[i] -= 1;
        count_students[j] -= 1;
        remaining -= 1;
      }
    }

    return res;
  }
};

int main()
{
  vector<int> seats = {3, 1, 5};
  vector<int> students = {2, 7, 4};
  Solution s;
  cout << s.minMovesToSeat(seats, students) << endl;

  return 0;
}