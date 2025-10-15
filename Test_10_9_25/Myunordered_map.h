//
// Created by 有趣的中国人 on 2025/10/10.
//
#include "HashTable.h"

#ifndef TEST_10_9_25_MYUNORDERED_MAP_H
#define TEST_10_9_25_MYUNORDERED_MAP_H
namespace dsj
{
    template<class K, class V>
    struct KeyOfT
    {
        const K& operator()(const pair<K, V>& kv)
        {
            return kv.first;
        }
    };

    template<class K, class V, class HashFunc = HashFunc<K>>
    class unordered_map
    {

    public:
        typedef close_hash::HashData<pair<K, V>> Node;
        typedef typename close_hash::HashBucket<K, pair<K, V>, KeyOfT<K, V>, HashFunc>::Iterator iterator;
        typedef typename close_hash::HashBucket<K, pair<K, V>, KeyOfT<K, V>, HashFunc>::Const_Iterator const_iterator;


        const_iterator begin() const
        {
            return _hb.begin();
        }

        const_iterator end() const
        {
            return _hb.end();
        }

        iterator begin()
        {
            return _hb.begin();
        }

        iterator end()
        {
            return _hb.end();
        }

        pair<iterator, bool> insert(const pair<K, V>& kv)
        {
            return _hb.Insert(kv);
        }

        iterator find(const K& key)
        {
            return _hb.find(key);
        }

        bool erase(const K& key)
        {
            return _hb.Erase(key);
        }

        V& operator[](const K& key)
        {
            pair<iterator, bool> p = insert({key, V()});
            iterator it = p.first;
            return it->second;
        }

    private:
        close_hash::HashBucket<K, pair<K, V>, KeyOfT<K, V>, HashFunc> _hb;
    };

    void PrintHash(const unordered_map<int, std::string>& hashTable)
    {
        std::cout << "\n=== 遍历哈希表 ===" << std::endl;
        unordered_map<int, std::string>::const_iterator it = hashTable.begin();
        while (it != hashTable.end()) {
            std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
            ++it;
        }
    }

    void TestHashBucket()
    {
        // 测试1: 整数键值对
        std::cout << "=== 测试1: 整数键值对 ===" << std::endl;
        unordered_map<int, std::string> hashTable;

        // 复杂数据集
        std::vector<std::pair<int, std::string>> testData = {
                {1, "Apple"}, {2, "Banana"}, {3, "Cherry"}, {4, "Date"},
                {5, "Elderberry"}, {6, "Fig"}, {7, "Grape"}, {8, "Honeydew"},
                {9, "Icaco"}, {10, "Jackfruit"}, {11, "Kiwi"}, {12, "Lemon"},
                {13, "Mango"}, {14, "Nectarine"}, {15, "Orange"}, {16, "Papaya"},
                {17, "Quince"}, {18, "Raspberry"}, {19, "Strawberry"}, {20, "Tangerine"},
                {-5, "Negative Key"}, {1000, "Large Key"}, {-100, "Negative Large"},
                {0, "Zero Key"}, {999, "Edge Case"}, {42, "Answer"},
                // 添加一些会哈希冲突的数据
                {5, "Second Elderberry"}, {15, "Second Orange"}, {25, "Another Conflict"},
                {35, "Yet Another Conflict"}, {45, "More Conflict"}
        };

        // 插入数据
        for (const auto& kv : testData) {
            hashTable.insert(kv);
            std::cout << "插入 (" << kv.first << ", " << kv.second << "): "
                      << std::endl;
        }
        PrintHash(hashTable);
        // 如果没有迭代器，可以添加一个打印方法到 HashBucket 类中
        // hashTable.Print();
    }



    void TestHashBucketWithStrings()
    {
        std::cout << "\n\n=== 测试2: 字符串键值对 ===" << std::endl;
        unordered_map<std::string, std::string> stringHashTable;

        std::vector<std::pair<std::string, std::string>> stringData = {
                {"Alice", "25岁"}, {"Bob", "30岁"}, {"Charlie", "35岁"}, {"Diana", "28岁"},
                {"Eve", "22岁"}, {"Frank", "40岁"}, {"Grace", "33岁"}, {"Henry", "29岁"},
                {"Ivy", "26岁"}, {"Jack", "31岁"}, {"Karen", "27岁"}, {"Leo", "34岁"},
                {"Mia", "23岁"}, {"Nathan", "32岁"}, {"Olivia", "24岁"}, {"Peter", "36岁"},
                {"Quinn", "21岁"}, {"Rachel", "37岁"}, {"Sam", "38岁"}, {"Tina", "39岁"},
                {"", "空键"},  // ✅ 现在类型匹配
                {"VeryLongKeyNameThatMightCauseIssues", "特殊长键"},
                {"Key With Spaces", "带空格的键"},
                {"key_with_underscores", "带下划线的键"},
                {"Key-With-Dashes", "带连字符的键"},
                {"Key.With.Dots", "带点的键"},
                {"重复键", "第一次"}, {"重复键", "第二次"}, {"重复键", "第三次"}
        };

        for (const auto& kv : stringData) {
            //bool result = stringHashTable.insert(kv);
            std::cout << "插入 (\"" << kv.first << "\", " << kv.second << "): "
                       << std::endl;
        }
    }

    void TestHashBucketPerformance()
    {
        std::cout << "\n\n=== 测试3: 性能测试 - 大量数据 ===" << std::endl;
        unordered_map<int, int> performanceTable;

        int testSize = 1000; // 可以根据需要调整大小
        std::cout << "插入 " << testSize << " 个元素..." << std::endl;

        for (int i = 0; i < testSize; ++i) {
            // 使用一些有模式的数据，以便观察哈希分布
            int key = (i * 7 + 13) % 997; // 产生一些分布但不连续的数字
            performanceTable.insert(std::make_pair(key, i));

            if (i % 100 == 0) {
                std::cout << "已插入 " << i << " 个元素" << std::endl;
            }
        }

        std::cout << "性能测试完成" << std::endl;
    }

    void TestOperatorCount()
    {
        string str[] = {"苹果","草莓","香蕉", "梨子","苹果"};

        dsj::unordered_map<string, int> countmap;

        for (auto& i : str)
        {
            countmap[i]++;
        }

        auto it = countmap.begin();
        while (it != countmap.end())
        {
            cout << "\n" << it->first <<": " << it->second << endl;
            ++it;
        }
    }
}


#endif //TEST_10_9_25_MYUNORDERED_MAP_H
