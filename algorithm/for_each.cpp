#include <iostream>
#include <vector>
#include <algorithm>

/* *
 * 
 * for_each 算法
 * for_each(Iterator begin, Iterator end, proc p)
 * 1. proc为普通算法
 * 2. proc为反函数
 * 
 * 反函数：
 * 1. 一个类使用对象时调用的函数，其实现时类包含了operator()，之后这个类就有啦类系函数的行为，就是一个仿函数。
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

/* *
 * 定义一个仿函数
 * */
template <class T>
class Multiple
{
    private:
        T value;
    public:
        Multiple(const T& v): value(v){}

        // 重载operator()方法
        void operator()(T& elem) const 
        {
            elem *= value;
        }
};

class Sum
{
    private:
        long sum;
    public:
        Sum(): sum(0) {}

        void operator() (int elem)
        {
            sum += elem;
        }

        operator double() 
        {
            return static_cast<double>(sum);
        }
        
};

int  main()
{
    std::vector<int> myvector;
    FillValue(myvector, 1, 10);
    for_each(myvector.begin(), myvector.end(), print);
    std::cout << std::endl;
    // 使用仿函数
    for_each(myvector.begin(), myvector.end(), Multiple<int>(2));
    for_each(myvector.begin(), myvector.end(), print);

    // 重载operator double
    double sum = for_each(myvector.begin(), myvector.end(), Sum());
    std::cout << "sum:" << sum << std::endl;
    return 0;
}
