## uncompress strings

* Should have first written out the approach before writing trying out solution

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