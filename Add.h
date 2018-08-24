struct Add {};

double apply(const Add&, std::array<double, 2> x)
{
    return x[0] + x[1];
}

std::array<double, 2> invert(const Add&, double x)
{
    return {x, 0};
}
