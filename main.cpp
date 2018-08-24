#include <iostream>
#include <string>
#include <vector>

#include "Applyable.h"

struct Square {};
double apply(const Square&, double x)
{
    return x * x;
}

struct Double {};
double apply(const Double&, double x)
{
    return 2 * x;
}

int main()
{
    std::vector<Applyable<double, double>> fs;
    fs.push_back(Square{});
    fs.push_back(Double{});

    for (const auto& f : fs)
    {
        std::cout << apply(f, 4) << std::endl;
        std::cout << apply(f, 9) << std::endl;
        std::cout << std::endl;
    }
}
