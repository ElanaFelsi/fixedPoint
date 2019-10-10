//
// Created by elana on 10/10/19.
//

#ifndef CPP_FIXED_POINT_ELANAFELSI_PRICE_H
#define CPP_FIXED_POINT_ELANAFELSI_PRICE_H

#define REPRESENTATION 100

class Price {
public:
    Price(int dollar = 0, int cent = 0.00);
    int getPrice() const;
    Price &operator=(const Price &other);
    /*Price &operator=(int dollar);*/

private:
    int m_price;

};

inline Price::Price(int dollar, int cent):m_price(dollar * REPRESENTATION + cent)
{
}

inline int Price::getPrice() const
{
    return m_price;
}

/*
 *
 */
inline Price &Price::operator=(const Price &other) {
    if(this != &other)
    {
        this->m_price = other.m_price;
    }
    return *this;
}

#endif //CPP_FIXED_POINT_ELANAFELSI_PRICE_H
