#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

int main() {
    constexpr std::array<std::string_view, 8> data = {"▁","▂","▃","▄","▅","▆","▇","█"};
    std::array<std::string, std::size(data)> arr;

    std::copy(data.cbegin(), data.cend(), arr.begin());

    auto print = [](const std::string_view s) { std::cout << s << ' '; };

    print("Print in direct order\n");
    std::for_each(arr.cbegin(), arr.cend(), print);
    
    std::cout << std::endl;
    print("Print in reverse order\n");
    std::for_each(arr.crbegin(), arr.crend(), print);

    std::cout << std::endl;


}


