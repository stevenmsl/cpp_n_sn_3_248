#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol248;
using namespace std;

/*takeaways
  - check cpp_n_sn_2_247 for why we can separate into
    two cases: odd digit numbers and even digit numbers
    when finding SNs
  - as per the question the range can be a very large number
    so we have to optimize the space complexity and NOT
    to store the temporary result in a vector like we
    do in cpp_n_sn_2_247
  - we only need to count how many of them so use a
    variable to record it
*/

void Solution::_count(string L, string H, string num, int &total)
{
  /* we will see if we need to count this num if
     it has the right amount of digits
  */
  if (num.size() >= L.size() && num.size() <= H.size())
  {
    /*skip - num is too large and hence out of range */
    if (num.size() == H.size() && num.compare(H) > 0)
      return;
    /* count it!
       - can't be a multiple digit number with a leading 0
       - if the number of digits of num is the same as L
         , we need to further check to make sure it's not
         smaller than L
    */
    if (!(num.size() > 1 && num[0] == '0') &&
        !(num.size() == L.size() && num.compare(L) < 0))
      total++;
  }

  if (num.size() + 2 > H.size())
    return;

  /* check the next batch of numbers that have two more digits
     than num
     - list out all the possible combinations
     - don't worry about the numbers with
       a leading zero as they will not be counted later
  */
  _count(L, H, "0" + num + "0", total);
  _count(L, H, "1" + num + "1", total);
  _count(L, H, "6" + num + "9", total);
  _count(L, H, "8" + num + "8", total);
  _count(L, H, "9" + num + "6", total);
}

int Solution::count(string L, string H)
{
  auto total = 0;
  /* starting point for even-digit numbers */
  _count(L, H, "", total);

  /* starting point for odd-digit numbers */
  _count(L, H, "0", total);
  _count(L, H, "1", total);
  _count(L, H, "8", total);
  return total;
}