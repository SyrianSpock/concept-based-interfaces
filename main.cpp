#include <array>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "Add.h"
#include "Bijection.h"

std::ostream& operator<<(std::ostream& stream, const std::array<double, 2>& x)
{
    stream << "[" << x[0] << ", " << x[1] << "]";
    return stream;
}

int main()
{
    Bijection<std::array<double, 2>, double> f(Add{});

    std::cout << "Applying for [2, 2]: " << apply(f, {2,2}) << std::endl;
    std::cout << "Applying for [3, 6]: " << apply(f, {3,6}) << std::endl;
    std::cout << "Inverting for 4: " << invert(f, 4) << std::endl;
    std::cout << "Inverting for 9: " << invert(f, 9) << std::endl;
}
