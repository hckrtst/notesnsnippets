## uncompress strings

* Should have first written out the approach before writing trying out solution
* think about the time/space complexities before trying out the solution,
 this is an interesting one...since it actually is doing a decompression so it's not simply dependent on the size of input
### first solution
```cpp

#include <string>

/*
44s13fg ssssfg
  i
*/

// find number for the following char
int get_next_count(std::string& s, int& i)
{
  std::string count = "0";
  while ((i < s.size()) && (std::isdigit(s[i]))) 
  {
    count += s[i];
    i++;
  }
  return stoi(count);
}
//3n12e2z
std::string uncompress(std::string s) { 
  std::string res;
  int i = 0;
  for (;;)
  {
    int count = get_next_count(s, /*ref*/ i);
    if (i >= s.size()) break;
    for (int j = 0; j < count; ++j) {
      res += s[i];
    }
    i++;
  }
  return res;
}

```

shorter version

```cpp
std::string uncompress(std::string s) {
  std::string res;
  int i{}, j{};
  while(j < s.length())
  {
    while (std::isdigit(s[j])) j++; 
    int count = std::stoi(s.substr(i, j - i));
    res += std::string(count, s[j]);
    j++;
    i = j; // i starts at next digit or end of string
  }
  return res;
}

```

## compress string

first solution, this is O(n) where n = num of input chars

```cpp
std::string compress(std::string s) {
  std::string res;
  int i{}, j{};
  while (j < s.length())
  {
    while ((j < s.length()) && (s[j] == s[i])) j++;
    int len = j - i;
    if (len > 1) {
      res += std::to_string(len);
    }
    res += s[i];
    i = j;
  }
  return res;
}

```

* one trick as suggested by Alvin might be to compare with nul at the end...


