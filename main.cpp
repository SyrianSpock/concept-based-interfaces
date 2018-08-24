#include <iostream>
#include <string>
#include <vector>

#include "Applyable.h"

struct Square
{
    double x;
};
void apply(const Square& s)
{
    std::cout << s.x * s.x << std::endl;
}

int main()
{
    std::vector<Applyable> fs;
    fs.push_back(Square{4});
    fs.push_back(Square{9});

    for (const auto& f : fs)
    {
        apply(f);
    }
}
