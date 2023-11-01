#include <iostream>
#include <string>
using namespace std;

int main() {
  string short_s = "this is short ";
  string long_s = "this is loooooooooooong";

  string&& combined = short_s + long_s; // avoids copy by forcing a move

  cout << combined << endl;

  string new_owner = move(combined);

  cout << "combined = " << combined << endl;
  cout << "new_owner = " << new_owner << endl;

  // we can do the same move with this
  string third_owner = static_cast<string&&>(new_owner);

  cout << "combined = " << combined << endl;
  cout << "new_owner = " << new_owner << endl;
  cout << "third_owner = " << third_owner <<endl;

  return 0;
}