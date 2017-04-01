#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


void print(int elem)
{
    std::cout << elem;
}

int main(void)
{
    int arry1[] = {1,2,3,4,5,6,7,8,9};
    int arry2[] = {11,12,13,14,15,16,17,18,19};

    std::vector<int> v1;
    std::vector<int> v2;

    v1.assign(arry1, arry1+9);
    std::for_each(v1.begin(), v1.end(), print);
    std::cout << std::endl;
    copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, ", "));

    return 0;
}
