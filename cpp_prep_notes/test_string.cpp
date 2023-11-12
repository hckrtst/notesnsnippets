#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int id, std::string::size_type n, std::string const& s)
{
    std::cout << id << ") ";
    if (std::string::npos == n)
        std::cout << "not found! n == npos\n";
    else
        std::cout << "found @ n = " << n << ", substr(" << n << ") = "
                  << std::quoted(s.substr(n)) << '\n';
}


///
// function to split a string on a delimiter and return a vector of tokens
///
vector<string> split(const string& src, const char delimiter) {
  vector<string> res;
  size_t head{0}, tail{0};
  while ((tail = src.find(delimiter, head)) != string::npos) {
    res.push_back(src.substr(head, tail - head));
    head = tail + 1;  
  }
  return res;
}

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
  cout << "s5 ==  " << quoted("ab\\0\\0cd"s) << " is " << (s5 == "ab\0\0cd") << endl; // string class implements == operator

  // finding in strings
  string const phrase = "to be or not to be";
  std::string::size_type n;
  
  n = phrase.find("be");
  print(1, n, phrase);

  n= phrase.find("Be");
  print(2, n, phrase);

  cout << "using rfind\n";
  n = phrase.rfind("be");
  print(3, n, phrase);

  cout << "phrase starts with 'to'" << phrase.starts_with("to") << endl; // c++20 has starts_with and ends_with
  // or you can do it the ol-fashioned way with substr
  cout << "phrase starts with 'to'" << (phrase.find("to")  == 0) << endl; // c++20 has starts_with and ends_with
  cout << "phrase ends with 'be'" << (phrase.rfind("be") == (phrase.length() - 2)) << endl;

  auto name = "cppsaurus"s;
  cout << name << " contains one of 'a', 'x' " << name.find_first_of("ax") << endl;
  cout << name << " contains one of 'x' 'y " << name.find_first_of("xy") << endl; // npos is -1

  // converting to lower case
  string mytext = "HI THIS IS A TEST 123";
  std::transform(mytext.begin(), mytext.end(), mytext.begin(), [](unsigned char c){ return std::tolower(c); });

  cout << mytext << endl;
  
  mytext[0] = std::toupper(mytext[0]);

  cout << mytext <<endl;

  // converting string to int
  string sn = "1245";
  int i = stoi(sn);
  float f = stof(sn);

  cout << f+4444 << endl;

  for (auto& e: split(mytext, ' ')) {
    cout << e << endl;
  }
}