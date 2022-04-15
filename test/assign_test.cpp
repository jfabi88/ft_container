#include <iostream>
#include <vector>

int main()
{
    std::vector<int> stvec(10, 10);
    std::vector<char>   stvec2(10, 'a');

    stvec.assign(stvec2.begin(), stvec2.end());
}