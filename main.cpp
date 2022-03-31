#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol248;

/*
Input: low = "50", high = "100"
Output: 3
Explanation: 69, 88, and 96 are three strobogrammatic numbers.
*/
tuple<string, string, int>
testFixture1()
{
  return make_tuple("50", "100", 3);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::count(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  return 0;
}