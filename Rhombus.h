#ifndef OOP_EXERSICE_03_RHOMBUS_H
#define OOP_EXERSICE_03_RHOMBUS_H
#include "Figures.h"

class Rhombus : public Figures {
private:
    double D1, D2;
public:
    Rhombus(const double &x, const double &y, const double &d1, const double &d2);
    double Area() override;
    Cord Center() override;
    void Print() override;
    friend std::ostream& operator<<(std::ostream& out, const Rhombus& rhombus);
};

#endif //OOP_EXERSICE_03_RHOMBUS_H
