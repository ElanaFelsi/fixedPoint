#ifndef CPP_FIXED_POINT_ELANAFELSI_COLOR_H
#define CPP_FIXED_POINT_ELANAFELSI_COLOR_H

#include "fixed_point.h"

class Color {
public:
    template<class T>
    Color* calcFixedPointGradient(T num) {
        static Color pallette[num.m_size];//implicit interface
        return pallette;
    }

    template<class T>
    unsigned int getSizeArr(T num) {
        return num.m_size;
    }

};



#endif //CPP_FIXED_POINT_ELANAFELSI_COLOR_H
