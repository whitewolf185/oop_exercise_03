
#include "Rhombus.h"

Rhombus::Rhombus(const double &x, const double &y, const double &d1, const double &d2) : D1(d1), D2(d2) {
    //point of left edge
    this->X = x;
    this->Y = y;

    if (D1 < 0 || D2 < 0) {
        throw std::invalid_argument("Invalid Rhombus parameters!");
    }
}

double Rhombus::Area() {
    return D1 * D2 / 2;
}

Cord Rhombus::Center() {
    return Cord(X + D1 / 2, Y);
}

void Rhombus::Print() {
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Rhombus &rhombus) {
    out << "Rhombus vertices: [ " << Cord(rhombus.X, rhombus.Y) << ", "
        << Cord(rhombus.X + rhombus.D1 / 2, rhombus.Y + rhombus.D2 / 2) << ", "
        << Cord(rhombus.X + rhombus.D1, rhombus.Y) << ", "
        << Cord(rhombus.X - rhombus.D1 / 2, rhombus.Y - rhombus.D2 / 2) << " ]" << std::endl;

    return out;
}



