#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> v(10, 9);
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    return 0;
}

//int main()
//{
////    std::string str("hello world");
////    std::cout << sizeof(str) << std::endl;
////std::cout << sizeof(char*) << std::endl;
//    std::string const str("hello Linux");
//    return 0;
//}
