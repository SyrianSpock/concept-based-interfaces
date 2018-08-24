#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "Applyable.h"
#include "Invertable.h"

struct Square {};
double apply(const Square&, double x)
{
    return x * x;
}
double invert(const Square&, double x)
{
    return sqrt(x);
}

struct Double {};
double apply(const Double&, double x)
{
    return 2 * x;
}
double invert(const Double&, double x)
{
    return x / 2;
}

template<typename Input, typename Output>
struct Bijection : Applyable<Input, Output>, Invertable<Input, Output>
{
    template <typename T>
    Bijection(T&& impl) : Applyable<Input, Output>(impl), Invertable<Input, Output>(impl) {}
};

int main()
{
    std::vector<Bijection<double, double>> fs;
    fs.push_back(Square{});
    fs.push_back(Double{});

    for (const auto& f : fs)
    {
        std::cout << "Applying for 4: " << apply(f, 4) << std::endl;
        std::cout << "Applying for 9: " << apply(f, 9) << std::endl;
        std::cout << "Inverting for 4: " << invert(f, 4) << std::endl;
        std::cout << "Inverting for 9: " << invert(f, 9) << std::endl;
        std::cout << std::endl;
    }
}
