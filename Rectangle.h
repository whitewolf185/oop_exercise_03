#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Figures.h"

class Rectangle : public Figures {
private:
    double A, B;
public:
    Rectangle(const double &x, const double &y, const double &a, const double &b);
    double Area() override;
    Cord Center() override;
    void Print() override;
    friend std::ostream & operator << (std::ostream & out, const Rectangle & rect);
};

#endif /* RECTANGLE_HPP */
