#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;
int main()
{
  uint64_t string_size, cost_reverse, cost_inverse;
  cin >> string_size >> cost_reverse >> cost_inverse;

  // read the string
  string input;
  cin >> input;

  /// Count groups of isolated '0'
  input.push_back('1'); // to make sure it ends in 1

  char last(input.front());
  uint64_t groups = count_if(input.begin(), input.end(), [&last] (char c) {
      bool retVal = (c == '1' and last == '0');
      last = c;
      return retVal;
    });

  uint64_t total_cost(0);
  if (groups > 0) {
    // Calculate the cost
    if (cost_reverse < cost_inverse) {
      // reverse all gruups until we get only one, then inverse
      total_cost = (groups-1) * cost_reverse + cost_inverse;
    } else {
      // inverse each group
      total_cost = (groups * cost_inverse); 
    }
  }

  cout << total_cost << "\n";
}
