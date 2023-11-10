#include <iostream>
#include <vector>

using namespace std;
using std::vector;
int main()
{
  vector<int> v = {1,2,3,4};
  for (unsigned char i = 0; i != v.size(); ++i) {
    std::cout << v[i] << std::endl;
  }
  return 0;
}