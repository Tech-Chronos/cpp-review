#include <iostream>
#include <vector>
#include <string>
class Base
{
public:
    Base(int base_public, int base_private)
      :_base_public(base_public)
      ,_base_private(base_private)
    {}
public:
    int _base_public;
private:
    int _base_private;
};

class Derive : public Base
{
public:
    // 构造函数
    // 在派生类的构造函数中，如果基类没有默认构造函数，一定要在初始化列表中加入基类构造函数
    Derive(int base_public, int base_private, int derive_public, int derive_private)
      :Base({base_public, base_private})
      ,_derive_public(derive_public)
      ,_derive_private(derive_private)
    {}

    Derive(const Derive& d)
      : Base(d)
    {
        _derive_private = d._derive_private;
        _derive_public = d._derive_public;
    }
public:
    int _derive_public;
private:
    int _derive_private;
};

void extend_test()
{
    Derive dd(1,1,1,1);
}

int main()
{
    extend_test();
    return 0;
}
