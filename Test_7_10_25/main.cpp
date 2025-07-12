#include <iostream>
#include <map>
#include <set>
#include <vector>

void test_set()
{
    std::set<int> st;
    int arr[] = {30,12,21,43,13,95,59};
    for (const auto& val:arr)
    {
        st.insert(val);
    }

    std::set<int>::iterator it = st.begin();
    while (it != st.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    st.erase(st.lower_bound(10), st.upper_bound(40));

    for (it = st.begin(); it != st.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}

void set_test2()
{
    std::vector<int> v = {9,7,6,4,3};
    std::set<int> st(v.begin(),v.end());

    auto it = st.begin();
    for (it = st.begin(); it != st.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void map_test()
{
    std::map<std::string, int> mp;
    std::vector<std::string> vs = {"草莓","香蕉","西瓜","西瓜","香蕉","香蕉"};
    for (auto it = vs.begin(); it != vs.end(); ++it)
    {
        auto mit = mp.find(*it);
        if (mit == mp.end())
        {
            mp.insert({*it,1});
        }
        else
        {
           mit->second++;
        }
    }

    auto mit = mp.begin();
    while (mit != mp.end())
    {
        std::cout << mit->first << ": " << mit->second << " ";
        ++mit;
    }
    std::cout << std::endl;
}

int main()
{
    map_test();
    return 0;
}
