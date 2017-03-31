#include <iostream>
#include <vector>
#include <algorithm>


/* *
 * 1. count: 求容器中元素的个数
 * 1. count (Iterator begin, Iterator end)
 * 计算 begin 到 end 之间的元素个数
 * 2. count (Iterator begin, Iterator end, UNaryPreicate op)
 * 只有op为真时，才统计元素的个数
 * 
 * 2. min_element:求容器中的最小值
 * 3. max_element:求容器中的最大值
 * 
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

bool is_even(int elem)
{
    return (elem & 1) == 0;
}

int main()
{
    std::vector<int> myvector;
    FillValue(myvector, 1, 10);
    for_each(myvector.begin(), myvector.end(), print);
    std::cout << std::endl;

    // 计算等于4的个数
    int ct = std::count(myvector.begin(), myvector.end(), 4);
    // 计算偶数的个数
    int ct_if = std::count_if(myvector.begin(), myvector.end(), is_even);

    int ctg = std::count_if(myvector.begin(), myvector.end(), std::bind2nd(std::greater<int>(), 2));


    std::cout << "Number of equal 4 is:" << ct << std::endl;
    std::cout << "Number of is even is:" << ct_if << std::endl;
    std::cout << "NUmber of greater 2 is:" << ctg  << std::endl;

}
