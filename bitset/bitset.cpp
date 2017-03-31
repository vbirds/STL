#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * @brief print
 * @param bit
 */
void print(std::bitset<16> & bit)
{
    int size = bit.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << bit[i];
    }

    cout << "   :" << "The size of bitset :" << size << endl;
}

int main(int argc, char *argv[])
{
    std::string str = "001111111111101011101111";
    std::bitset<16> b1;
    std::bitset<16> b2(25);
    std::bitset<16> b3(str, 2, 16);

    print(b1);
    print(b2);
    print(b3);

    // b1
    if (b1.none())
    {
        cout << "b1 is empty" << endl;
    }
    b1.set(0);
    print(b1);
    cout << "b1:" << b1.to_ulong() << endl;


    // cout << "Hello World!" << endl;
    return 0;
}
