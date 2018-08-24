#include <array>
#include <iostream>
#include <string>
#include <vector>

#include "Affine.h"
#include "Bijection.h"

int main()
{
    Bijection<double, double> f{Affine1D{0.2, 4.3}};

    std::vector<double> values{
        2,
        3,
    };
    for (const auto& v : values)
    {
        auto fv = apply(f, v);
        std::cout << "Using: " << v << std::endl;
        std::cout << "Applying: " << fv << std::endl;
        std::cout << "Inverting: " << invert(f, fv) << std::endl;
    }
}
