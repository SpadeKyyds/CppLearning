/**
 * count(iterator beg, iterator end, value);
 * 统计元素出现次数
 * beg 开始迭代器
 * end 结束迭代器
 * value 统计的元素
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//内置数据类型
void myInt()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num = count(v.begin(), v.end(), 4);

    cout << "4的个数为: " << num << endl;
}

//自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    // 自定义数据类型需要 重载==
    // 这里底层代码要求使用 const形参才可以
    bool operator==(const Person& p)
    {
        if (this->m_Age == p.m_Age) {
            return true;
        } else {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};

void myPerson()
{
    vector<Person> v;

    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 25);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("诸葛亮", 35);

    int num = count(v.begin(), v.end(), p);
    cout << "num = " << num << endl;
}

int main()
{
    // myInt();
    myPerson();

    return 0;
}