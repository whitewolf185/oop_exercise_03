#ifndef OOP_EXERSICE_03_TRAPEZE_H
#define OOP_EXERSICE_03_TRAPEZE_H
#include "Figures.h"


class Trapeze : public Figures{
private:
    double A, B, C;
public:
    Trapeze(const double &x, const double &y, const double &a, const double &b, const double &c);
    double Area() override;
    Cord Center() override;
    void Print() override;
    friend std::ostream & operator << (std::ostream & out, const Trapeze & trapeze);
};
#endif //OOP_EXERSICE_03_TRAPEZE_H
