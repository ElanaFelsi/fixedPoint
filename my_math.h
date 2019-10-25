#ifndef CPP_FIXED_POINT_ELANAFELSI_MY_MATH_H
#define CPP_FIXED_POINT_ELANAFELSI_MY_MATH_H

/*
template <int n>
struct Power
{
    enum {RET = 10 * Power<n-1>::RET};
};
template <>
struct Power<0>
{
    enum {RET = 1};
};
*/

template <int n>
inline int Power(const int x)
{
    return Power<n-1>(x) *x;
}

template <>
inline int Power<1>(const int x)
{
    return x;
}

template <>
inline int Power<0>(const int x)
{
    return 1;
}




#endif //CPP_FIXED_POINT_ELANAFELSI_MY_MATH_H
