#include <iostream>
#include "my_string.h"
#include "my_string_view.h"

int main() {
    std::cout.flags(std::ios::boolalpha);
    char str[] = {"123"};
    char str2[] = {"lab"};
    String a(str2);
    a.insert(2,str2,2);
    String b = a;
    bool is = a <= b;
    std::cout << is << '\n';
    for (size_t i = 0; i != b.length(); ++i) {
        std::cout << b[i];
    }
    return 0;
}
