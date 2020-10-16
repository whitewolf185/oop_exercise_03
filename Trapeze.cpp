#include "Trapeze.h"

Trapeze::Trapeze(const double &x, const double &y,
                 const double &a, const double &b, const double &c) : A(a), B(b), C(c) { // x and y are left-bottom point of figure
    this->X = x;
    this->Y = y;
    if (A < 0.0 or B < 0.0 or C < 0.0) {
        throw std::invalid_argument("Invalid trapeze parameters!");
    }
    if (B > A) {
        std::swap(A, B);
    }
}

double Trapeze::Area() {
    double diff = (A - B) / 2.0;
    double height = std::sqrt(C * C - diff * diff);
    return height * (A + B) / 2.0;
}

Cord Trapeze::Center() {
    double diff = (A - B) / 2.0;
    double height = std::sqrt(C * C - diff * diff);
    return Cord(X + A / 2.0, Y + height / 2.0);
}

void Trapeze::Print() {
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Trapeze &trapeze) {
    double diff = (trapeze.A - trapeze.B) / 2.0;
    double height = std::sqrt(trapeze.C * trapeze.C - diff * diff);
    out << "Trapeze vertices: [";
    out << Cord(trapeze.X, trapeze.Y) << ", ";
    out << Cord(trapeze.X + diff, trapeze.Y + height) << ", ";
    out << Cord(trapeze.X + trapeze.A - diff, trapeze.Y + height) << ", ";
    out << Cord(trapeze.X + trapeze.A, trapeze.Y);
    out << "]";
    return out;
}