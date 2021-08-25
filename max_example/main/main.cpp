



// max example
// https://www.cplusplus.com/reference/algorithm/max/
#include <iostream>     // std::cout
#include <algorithm>    // std::max

/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{
  std::cout << "max(1,2)==" << std::max(1,2) << '\n';
  std::cout << "max(2,1)==" << std::max(2,1) << '\n';
  std::cout << "max('a','z')==" << std::max('a','z') << '\n';
  std::cout << "max(3.14,2.73)==" << std::max(3.14,2.73) << '\n';
}


