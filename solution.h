#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol248
{
  class Solution
  {
    static void _count(string L, string H, string num, int &total);

  public:
    static int count(string L, string H);
  };
}
#endif