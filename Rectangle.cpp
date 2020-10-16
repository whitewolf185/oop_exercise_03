#include "Rectangle.h"

Rectangle::Rectangle(const double &x, const double &y,
                     const double &a, const double &b) : A(a), B(b) { // x and y are left-bottom point of figure
    this->X = x;
    this->Y = y;

    if (A < 0.0 or B < 0.0) {
        throw std::invalid_argument("Invalid rectangle parameters!");
    }
}

double Rectangle::Area() {
    return A * B;
}

Cord Rectangle::Center() {
    return Cord(X + A / 2.0, Y + B / 2.0);
}

void Rectangle::Print() {
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &rectangle) {
    out << "Rectangle vertices: [";
    out << Cord(rectangle.X, rectangle.Y) << ", ";
    out << Cord(rectangle.X, rectangle.Y + rectangle.B) << ", ";
    out << Cord(rectangle.X + rectangle.A, rectangle.Y + rectangle.B) << ", ";
    out << Cord(rectangle.X + rectangle.A, rectangle.Y);
    out << "]";
    return out;
}