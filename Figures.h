#ifndef OOP_EXERSICE_03_FIGURES_H
#define OOP_EXERSICE_03_FIGURES_H
#include "Coord.h"

class Figures {
protected:
    double X{}, Y{};

public:
    virtual double Area() {
        return 0;
    }
    virtual Cord Center() {
        return Cord(0,0);
    }
    virtual void Print() {}
};
#endif //OOP_EXERSICE_03_FIGURES_H