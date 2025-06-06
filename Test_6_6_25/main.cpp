#include "stack.h"
#include "queue.h"

class Date
{
public:
    Date(int year, int month, int day)
      :_year(year)
      ,_month(month)
      ,_day(day)
    {}

    bool operator>(const Date& date) const
    {
        if (_year > date._year)
        {
            return true;
        }
        else if (_year == date._year)
        {
            if (_month > date._month)
            {
                return true;
            }
            else if (_month == date._month)
            {
                if (_day > date._day)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator==(const Date& date) const
    {
        return (_year == date._year) && (_month == date._month) && (_day == date._day);
    }

    bool operator!=(const Date& date) const
    {
        return !((*this) == date);
    }

    bool operator>=(const Date& date) const
    {
        return ((*this)>date) || ((*this)==date);
    }

    bool operator<(const Date& date) const
    {
        return !((*this)>=date);
    }

    bool operator<=(const Date& date) const
    {
        return !((*this) > date);
    }
private:
    int _year;
    int _month;
    int _day;
};

class CompareDateGreater
{
public:
    bool operator()(const Date& d1, const Date& d2)
    {
        return d1 < d2;
    }
};

class CompareDateGreaterPointer
{
public:
    bool operator()(Date* d1, Date* d2)
    {
        return *d1 < *d2;
    }
};
void date_compare1()
{
    std::vector<Date> vd;
    Date d1(2025,6,1);
    vd.push_back(d1);
    vd.push_back(Date(2025,3,21));
    vd.push_back({2025,10,1});

    std::sort(vd.begin(), vd.end(), CompareDateGreater());
}

// 指针比较
void date_compare2()
{
    std::vector<Date*> vd;
    Date* d1 = new Date(2030,1,1);
    Date* d2 = new Date(2018,1,1);
    Date* d3 = new Date(2025,1,1);
    vd.push_back(d1);
    vd.push_back(d2);
    vd.push_back(d3);

    std::sort(vd.begin(), vd.end(), CompareDateGreaterPointer());
}
int main()
{
    date_compare2();
    return 0;
}
//void stack_test()
//{
//    dsj::stack<int,std::deque<int>> st;
//    st.push(1);
//    st.push(2);
//    st.push(3);
//    st.push(4);
//    while (!st.empty())
//    {
//        std::cout << "st.size -> " << st.size() << " st.top -> " << st.top() << " ";
//        st.pop();
//        std::cout << std::endl;
//    }
//}
//
//void queue_test()
//{
//    dsj::queue<int, std::deque<int>> que;
//    que.push(1);
//    que.push(2);
//    que.push(3);
//    que.push(4);
//    que.push(5);
//    que.push(10);
//    que.push(9);
//    que.push(6);
//    que.push(8);
//    que.push(7);
//    while (!que.empty())
//    {
//        std::cout << "que.size -> " << que.size() << " que.front -> " << que.front() << " ";
//        que.pop();
//        std::cout << std::endl;
//    }
//}
//
//void priority_queue_test()
//{
//    dsj::priority_queue<int,std::vector<int>> pq;
//    pq.push(2);
//    pq.push(1);
//    pq.push(5);
//    pq.push(3);
//    pq.push(4);
//    pq.push(10);
//    pq.push(9);
//    pq.push(6);
//    pq.push(8);
//    pq.push(7);
//    while (!pq.empty())
//    {
//        std::cout << pq.top() << " ";
//        pq.pop();
//    }
//    std::cout << std::endl;
//}

// 仿函数测试
//class goods
//{
//public:
//    goods(const std::string& name, int price, int sales_figures)
//      :_name(name)
//      ,_price(price)
//      ,_sales_figures(sales_figures)
//    {}
//
//public:
//    std::string _name; // 商品名称
//    int _price; // 价格
//    int _sales_figures; // 销售额
//};
//
//class ComparePriceGreater
//{
//public:
//    bool operator()(const goods& good1, const goods& good2)
//    {
//        return good1._price > good2._price;
//    }
//};
//
//class ComparePriceLess
//{
//public:
//    bool operator()(const goods& good1, const goods& good2)
//    {
//        return good1._price < good2._price;
//    }
//};
//
//class CompareNameGreater
//{
//public:
//    bool operator()(const goods& good1, const goods& good2)
//    {
//        return good1._name > good2._name;
//    }
//};
//
//class CompareNameLess
//{
//public:
//    bool operator()(const goods& good1, const goods& good2)
//    {
//        return good1._name < good2._name;
//    }
//};
//
//void test_functors1()
//{
//    std::vector<goods> vg;
//    goods good1("手机",10000,200);
//    goods good2("化妆品",2000,300);
//    goods good3("玩具", 300, 500);
//    vg.push_back(good1);
//    vg.push_back(good2);
//    vg.push_back(good3);
//
//    // 按照价格的升序 or 降序
//    std::sort(vg.begin(), vg.end(), ComparePriceGreater());
//    std::sort(vg.begin(), vg.end(), ComparePriceLess());
//
//    // 按照名字的升序 or 降序
//    std::sort(vg.begin(), vg.end(), CompareNameGreater());
//    std::sort(vg.begin(), vg.end(), CompareNameLess());
//}
//
//
//
//void priority_queue_test2()
//{
//    dsj::priority_queue<int,std::vector<int>, dsj::CompareHeapGreater<int>> pq;
//    pq.push(2);
//    pq.push(1);
//    pq.push(5);
//    pq.push(3);
//    pq.push(4);
//    pq.push(10);
//    pq.push(9);
//    pq.push(6);
//    pq.push(8);
//    pq.push(7);
//    while (!pq.empty())
//    {
//        std::cout << pq.top() << " ";
//        pq.pop();
//    }
//    std::cout << std::endl;
//}

//void priority_queue_test3()
//{
//    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
//    pq.push(2);
//    pq.push(1);
//    pq.push(5);
//    pq.push(3);
//    pq.push(4);
//    pq.push(10);
//    pq.push(9);
//    pq.push(6);
//    pq.push(8);
//    pq.push(7);
//    while (!pq.empty())
//    {
//        std::cout << pq.top() << " ";
//        pq.pop();
//    }
//    std::cout << std::endl;
//}

//int main()
//{
//    //test_functors1();
//    priority_queue_test2();
//    return 0;
//}

//int main()
//{
//    //stack_test();
//    //queue_test();
//    //priority_queue_test();
//    return 0;
//}
//using namespace std;
//class myclass
//{
//public:
//    myclass(int a, int b)
//      :_a(a)
//      ,_b(b)
//    {}
//
//    bool operator()(int* a, int *b)
//    {
//        return *a > *b;
//    }
//private:
//    int _a;
//    int _b;
//};
//
//bool operator()(myclass& a, int* b)
//{
//
//}
//int main()
//{
//    myclass my(1,9);
//    cout <<  << endl;
//    return 0;
//}
