#include <array>
#include <cmath>
#include <exception>

struct Affine1D {
    double a;
    double b;
};

double apply(const Affine1D& f, double x)
{
    return f.a * x + f.b;
}

double invert(const Affine1D& f, double x)
{
    return (x - f.b) / f.a;
}
