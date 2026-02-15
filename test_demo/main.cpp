#include <iostream>
#include <iostream>

int main()
{
    std::string str = "aaaaaaaaaaaa";
    std::cout << sizeof(str) << std::endl;
    std::cout << sizeof(char*) << std::endl;
    std::cout << str.size() << std::endl;
    return 0;
}
