#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
//    vector<vector<int>> vv;
//    vv.reserve(5);
//    vv.at(1);
    vector<int> v(3);
    return 0;
}
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>> vv(numRows);
//        for (size_t i = 0; i < numRows; ++i)
//        {
//            vv[i].resize(i+1);
//            vv[i][0] = vv[i][i] = 1;
//        }
//        for (size_t i = 0; i < numRows; ++i)
//        {
//            for (size_t j = 0; j < i; ++j)
//            {
//                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//            }
//        }
//        return vv;
//    }
//};

//int main()
//{
//    std::vector<int> v(10, 9);
//    for (auto it : v)
//    {
//        std::cout << it << " ";
//    }
//    return 0;
//}

//int main()
//{
////    std::string str("hello world");
////    std::cout << sizeof(str) << std::endl;
////    std::cout << sizeof(char*) << std::endl;
//      std::string const str("hello Linux");
//      return 0;
//}
