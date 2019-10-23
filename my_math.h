#ifndef CPP_FIXED_POINT_ELANAFELSI_MY_MATH_H
#define CPP_FIXED_POINT_ELANAFELSI_MY_MATH_H


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
