#include <array>
#include <iostream>
#include <string>
using namespace std;

int main()
{ 
  string s1; // empty

  string s2(10, 174);
  string s3(10, 94);

  cout << s2 << endl; 
  cout << s3 << endl;

  auto s4 = "id "s + to_string(1010.10222f);
  cout << "s4 = " << s4 << endl;

  std::string s5 = "ab\0\0cd";
  string s6 = "ab\0\0cd"s; // literal
  cout << "s5 = " << s5 << " ";
  cout << "s6 = " << s6 << endl;
  cout << "size of s6 = " << s6.size() << endl; // 6 - contains the middle \0 as well
  cout << "size of s5 = " << s6.size() << endl; // also 6
  // length can be different from size in case of multi-bytes chars
  cout << "len of s5 = " << s6.length() << endl; // also 6
  cout << "len of s5 = " << s6.length() << endl; // 6
  cout << (s5 == "ab\0\0cd") << endl;

  // finding in strings
  



}