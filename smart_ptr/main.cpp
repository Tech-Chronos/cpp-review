#include <iostream>

int main()
{
    std::shared_ptr<int> ptr1 = std::make_shared<int>(2);
    std::weak_ptr<int> ptr2(ptr1);

    return 0;
}
