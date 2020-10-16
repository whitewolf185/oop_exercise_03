#ifndef OOP_EXERSICE_03_COORD_H
#define OOP_EXERSICE_03_COORD_H
#include <iostream>
#include <cmath>

struct Cord {
    double X, Y;
    Cord() : X(NAN), Y(NAN) {};
    Cord(double x, double y) : X(x), Y(y) {};
    ~Cord() = default;
};

inline std::ostream& operator<< (std::ostream & out, const Cord & crd) {
    out << "(" << crd.X << ", " << crd.Y << ")";
    return out;
}
#endif //OOP_EXERSICE_03_COORD_H
