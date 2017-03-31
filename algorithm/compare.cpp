#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


/* *
 * 区间比较算法
 * 1. equal()
 * 如果两个对象相等，返回true
 * 2. mismatch()
 * 返回两两相异的元素
 * 3. lexicographical_compare()
 * 字典式比较
 * */

template<class T>
void FillValue(T& vect, int first, int last)
{
    if (last >= first)
    {
        for (int i = first; i <= last; ++i)
        {
            vect.push_back(i);
        }
    }
    else
    {
        std::cout << "The indexs is error: last < first." << std::endl;
    }
}

void print(int elem)
{
    std::cout << elem << " ";
}

int main()
{
    std::vector<int> myvector;
    FillValue(myvector, 1, 5);
    for_each(myvector.begin(), myvector.end(), print);
    std::cout << std::endl;

    std::vector<int> myvector2;
    FillValue(myvector2, 1, 8);
    for_each(myvector2.begin(), myvector2.end(), print);
    std::cout << std::endl;
    
    bool eq = equal(myvector.begin(), myvector.end(), myvector2.begin());
    if (eq)
    {
        std::cout << "v1 == v2" << std::endl;
    }

    bool eq2 = equal(myvector2.begin(), myvector2.end(), myvector.begin());
    if (eq2)
    {
        std::cout << "v2 == v1" << std::endl;
    }

    std::list<int> l1;
    std::vector<int> l2;
    std::pair<std::list<int>::iterator, std::vector<int>::iterator> p1;    
    FillValue(l1, 1, 5);
    FillValue(l2, 1, 5);
    for_each(l1.begin(), l1.end(), print);
    std::cout << std::endl;
    for_each(l2.begin(), l2.end(), print);

    p1 = mismatch(l1.begin(), l1.end(), l2.begin());
    std::cout << std::endl;
    if (p1.first == l1.end())
    {
        std::cout << "no mismatch" << std::endl;
    }
    
    // lexicographical_compare 字典序比较
    // 
    bool bt = lexicographical_compare(l1.begin(), l1.end(), l2.begin(), l2.end());
    if (bt)
    {
        std::cout << "l1 < l2" << std::endl;
    }
}
