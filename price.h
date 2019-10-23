
#ifndef CPP_FIXED_POINT_ELANAFELSI_PRICE_H
#define CPP_FIXED_POINT_ELANAFELSI_PRICE_H

#include <iostream>

#define REPRESENTATION 100

template <typename T, unsigned int SIZE>
class Price {
public:
    explicit Price(T dollar = 0, T cent = 0.00);

    Price &operator=(const Price<T, SIZE> &other);
    Price &operator=(const T dollar);

    Price &operator+=(const Price<T, SIZE> &other);
    Price &operator-=(const Price<T, SIZE> &other);
    Price &operator*=(const Price<T, SIZE> &other);
    Price &operator/=(const Price<T, SIZE> &other);
    Price &operator%=(const Price<T, SIZE> &other);

    Price& operator++();
    Price& operator--();

    Price operator++(int);
    Price operator--(int);

    Price& operator-();

    double T2double();

    //friend std::ostream& operator<<(std::ostream& out, const Price<T> price);

    T getPrice() const;
private:
    T m_price;

};

template <typename T, unsigned int SIZE>
inline Price<T, SIZE>::Price(T dollar, T cent):m_price(dollar * REPRESENTATION + cent){}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator=(const Price<T, SIZE> &other) {
    if(this != &other)
    {
        this->m_price = other.m_price;
    }
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator=(const T dollar) {
    this->m_price = dollar * REPRESENTATION;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator+=(const Price<T, SIZE> &other) {
    m_price += other.m_price;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator-=(const Price<T, SIZE> &other) {
    m_price -= other.m_price;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator*=(const Price<T, SIZE> &other) {
    m_price *= other.m_price;
    m_price /= REPRESENTATION;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator/=(const Price<T, SIZE> &other) {
    m_price /= other.m_price;
    m_price *= REPRESENTATION;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator%=(const Price<T, SIZE> &other) {
    m_price %= other.m_price;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator++() {
    m_price = m_price + REPRESENTATION;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator--() {
    m_price = m_price - REPRESENTATION;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> Price<T, SIZE>::operator++(int num) {
    Price temp;
    temp.m_price = this->m_price;
    m_price = m_price + REPRESENTATION;
    return temp;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> Price<T, SIZE>::operator--(int num) {
    Price temp;
    temp.m_price = this->m_price;
    m_price = m_price - REPRESENTATION;
    return temp;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> &Price<T, SIZE>::operator-()
{
    m_price = -m_price;
    return *this;
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> operator+(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return Price<T, SIZE>(p1.getPrice() + p2.getPrice());
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> operator-(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return Price<T, SIZE>(p1.getPrice() - p2.getPrice());
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> operator*(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return Price<T, SIZE>((p1.getPrice() * p2.getPrice()) / REPRESENTATION);
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> operator/(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return Price<T, SIZE>((p1.getPrice() / p2.getPrice()) * REPRESENTATION);
}

template <typename T, unsigned int SIZE>
inline Price<T, SIZE> operator%(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return Price<T, SIZE>(p1.getPrice() % p2.getPrice());
}

template <typename T, unsigned int SIZE>
double Price<T, SIZE>::T2double() {
    return (double)m_price;
}

template <typename T, unsigned int SIZE>
inline T Price<T, SIZE>::getPrice() const
{
    return m_price;
}
/*
template <typename T>
std::ostream &operator<<(std::ostream &out, Price<T> price) {
    out << price.m_price << "\n";
    return out;
}*/

template <typename T, unsigned int SIZE>
inline bool operator==(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return p1.getPrice() == p2.getPrice();
}

template <typename T, unsigned int SIZE>
inline bool operator==(const Price<T, SIZE> &p1, const T p2)
{
    return p1.getPrice() == p2;
}

template <typename T, unsigned int SIZE>
inline bool operator<(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return p1.getPrice() < p2.getPrice();
}

template <typename T, unsigned int SIZE>
inline bool operator>(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return p1.getPrice() > p2.getPrice();
}

template <typename T, unsigned int SIZE>
inline bool operator<=(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return !(p1 > p2);
}

template <typename T, unsigned int SIZE>
inline bool operator>=(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return !(p1 < p2);
}

template <typename T, unsigned int SIZE>
inline bool operator!=(const Price<T, SIZE> &p1, const Price<T, SIZE> &p2)
{
    return !(p1 == p2);
}


#endif //CPP_FIXED_POINT_ELANAFELSI_PRICE_H
