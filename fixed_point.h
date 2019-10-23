#ifndef CPP_FIXED_POINT_ELANAFELSI_FIXED_POINT_H
#define CPP_FIXED_POINT_ELANAFELSI_FIXED_POINT_H

#include <iostream>
#include <iomanip>

#include "my_math.h"


template <unsigned int SIZE, typename T = int>
class FixedPoint {
public:
    explicit FixedPoint(T integer = 0, int fraction = 0.00);

    FixedPoint &operator=(const FixedPoint<SIZE, T> &other);
    FixedPoint &operator=(const T integer);

    FixedPoint &operator+=(const FixedPoint<SIZE, T> &other);
    /*FixedPoint &operator-=(const FixedPoint<SIZE, T> &other);
    FixedPoint &operator*=(const FixedPoint<SIZE, T> &other);
    FixedPoint &operator/=(const FixedPoint<SIZE, T> &other);
    FixedPoint &operator%=(const FixedPoint<SIZE, T> &other);*/

    FixedPoint& operator++();
    /*FixedPoint& operator--();

    FixedPoint operator++(int);
    FixedPoint operator--(int);

    FixedPoint& operator-();

    double T2double();*/

    friend std::ostream& operator<<(std::ostream& out, FixedPoint fixedPoint)
    {
        if(fixedPoint.m_signed)
            out << '-';
        out << +fixedPoint.m_integer << "." << std::setfill('0') << std::setw(SIZE) << fixedPoint.m_fraction << "\n";
        return out;
    }

private:
    T m_integer;
    unsigned int m_fraction;
    bool m_signed;

};

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T>::FixedPoint(T integer, int fraction)
{
    if(integer < 0)
    {
        m_signed = true;
        m_integer = integer * -1;
    }
    if(integer >= 0)
    {
        m_signed = false;
        m_integer = integer;
    }
    if(fraction < 0)
    {
        m_signed = true;
        m_fraction = fraction * -1;
    }
    else
    {
        m_fraction = fraction;
    }

}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator=(const FixedPoint<SIZE, T> &other)
{
    if(this != &other)
    {
        m_integer = other.m_integer;
        m_fraction = other.m_fraction;
        m_signed = other.m_signed;
    }
    return *this;
}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator=(const T integer) {
    if(integer < 0)
    {
        m_signed = true;
        m_integer = integer * -1;
    }
    if(integer >= 0)
    {
        m_signed = false;
        m_integer = integer;
    }
    m_fraction = 0;

}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator+=(const FixedPoint<SIZE, T> &other)
{
    if(m_signed == other.m_signed)
    {
        if ((m_fraction + other.m_fraction) >= Power<SIZE>(10)) {
            ++m_integer;
        }
        m_fraction = (other.m_fraction + m_fraction) % Power<SIZE>(10);
        m_integer += other.m_integer;
    }
    else
    {
        if(m_signed)
        {
            m_integer =  m_integer - other.m_integer;
            if ((int)(m_fraction - other.m_fraction) <= 0) {
                ++m_integer;
            }
        }
        m_integer = other.m_integer - m_integer;
        m_fraction += other.m_fraction;
        if(m_integer < 0)
        {
            m_integer = m_integer * -1;
            m_signed= true;
        }
        else
        {
            m_signed= false;
        }
    }
}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator++() {
    m_integer = m_integer + 1;
    return *this;
}


#endif //CPP_FIXED_POINT_ELANAFELSI_FIXED_POINT_H
