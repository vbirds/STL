#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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
    FillValue(myvector, 1, 10);
    for_each(myvector.begin(), myvector.end(), print);
    std::cout << std::endl;

    std::vector<int>::iterator pos1;
    pos1 = std::find(myvector.begin(), myvector.end(), 5);
    std::cout << "pos1:" << std::distance(myvector.begin(), pos1) << std::endl;
    
    std::vector<int>::iterator pos2;
    pos2 = std::find_if(myvector.begin(), myvector.end(), std::bind2nd(std::greater<int>(),2));
    std::cout << "pos2:" << std::distance(myvector.begin(), pos2) << std::endl;
    return 0;
}
