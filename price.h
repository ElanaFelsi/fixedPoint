
#ifndef CPP_FIXED_POINT_ELANAFELSI_PRICE_H
#define CPP_FIXED_POINT_ELANAFELSI_PRICE_H

#include <iostream>

#define REPRESENTATION 100

class Price {
public:
    explicit Price(int dollar = 0, int cent = 0.00);

    Price &operator=(const Price &other);
    Price &operator=(const int dollar);

    Price &operator+=(const Price &other);
    Price &operator-=(const Price &other);
    Price &operator*=(const Price &other);
    Price &operator/=(const Price &other);
    Price &operator%=(const Price &other);

    Price& operator++();
    Price& operator--();

    Price operator++(int);
    Price operator--(int);

    Price& operator-();

    double int2double();

    friend std::ostream& operator<<(std::ostream& out, const Price price);

    int getPrice() const;
private:
    int m_price;

};

inline Price::Price(int dollar, int cent):m_price(dollar * REPRESENTATION + cent){}

inline Price &Price::operator=(const Price &other) {
    if(this != &other)
    {
        this->m_price = other.m_price;
    }
    return *this;
}

inline Price &Price::operator=(const int dollar) {
    this->m_price = dollar * REPRESENTATION;
    return *this;
}

inline Price &Price::operator+=(const Price &other) {
    m_price += other.m_price;
    return *this;
}

inline Price &Price::operator-=(const Price &other) {
    m_price -= other.m_price;
    return *this;
}

inline Price &Price::operator*=(const Price &other) {
    m_price *= other.m_price;
    m_price /= REPRESENTATION;
    return *this;
}

inline Price &Price::operator/=(const Price &other) {
    m_price /= other.m_price;
    m_price *= REPRESENTATION;
    return *this;
}

inline Price &Price::operator%=(const Price &other) {
    m_price %= other.m_price;
    return *this;
}

inline Price &Price::operator++() {
    ++m_price;
    return *this;
}

inline Price &Price::operator--() {
    --m_price;
    return *this;
}

inline Price Price::operator++(int num) {
    Price temp;
    temp.m_price = this->m_price;
    ++m_price;
    return temp;
}

inline Price Price::operator--(int num) {
    Price temp;
    temp.m_price = this->m_price;
    --m_price;
    return temp;
}

inline Price& Price::operator-()
{
    m_price = -m_price;
    return *this;
}

inline Price operator+(const Price &p1, const Price &p2)
{
    return Price(p1.getPrice() + p2.getPrice());
}

inline Price operator-(const Price &p1, const Price &p2)
{
    return Price(p1.getPrice() - p2.getPrice());
}

inline Price operator*(const Price &p1, const Price &p2)
{
    return Price((p1.getPrice() * p2.getPrice()) / REPRESENTATION);
}

inline Price operator/(const Price &p1, const Price &p2)
{
    return Price((p1.getPrice() / p2.getPrice()) * REPRESENTATION);
}

inline Price operator%(const Price &p1, const Price &p2)
{
    return Price(p1.getPrice() % p2.getPrice());
}

double Price::int2double() {
    return (double)m_price;
}

inline int Price::getPrice() const
{
    return m_price;
}

std::ostream &operator<<(std::ostream &out, Price price) {
    out << price.m_price << "\n";
    return out;
}

inline bool operator==(const Price &p1, const Price &p2)
{
    return p1.getPrice() == p2.getPrice();
}

inline bool operator==(const Price &p1, const int p2)
{
    return p1.getPrice() == p2;
}

inline bool operator<(const Price &p1, const Price &p2)
{
    return p1.getPrice() < p2.getPrice();
}
inline bool operator>(const Price &p1, const Price &p2)
{
    return p1.getPrice() > p2.getPrice();
}
inline bool operator<=(const Price &p1, const Price &p2)
{
    return !(p1 > p2);
}
inline bool operator>=(const Price &p1, const Price &p2)
{
    return !(p1 < p2);
}
inline bool operator!=(const Price &p1, const Price &p2)
{
    return !(p1 == p2);
}


#endif //CPP_FIXED_POINT_ELANAFELSI_PRICE_H
