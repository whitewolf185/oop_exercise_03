
/* Волков Матвей Андреевич
 * Разработать классы согласно варианту задания,
 * классы должны наследоваться от базового класса Figure.
 * Фигуры являются фигурами вращения.
 * Все классы должны поддерживать набор общих методов:
 * - Вычисление геометрического центра фигуры
 * - Вывод в стандартный поток std::cout координат вершин фигуры
 * - Вычисление площади фигуры
 * Создать программу, которая позволяет:
 * - Вводить в стандартный поток std::cin фигуры
 * - Сохранять заданные фигуры в вектор std::vector<Figure*>
 * - Вызывать для всего массива общие функции
 * - Необходимо уметь вычислять общую площадь фигур в массиве.
 * - Удалять из массива фигуру по индексу
 * Прямоугольник, трапеция, ромб.
 */

#include "Figures.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include <vector>



long double TotalArea(std::vector<Figures*> & figures) {
    long double res = 0.0;
    for (auto fig : figures) {
        res = res + fig->Area();
    }
    return res;
}

int main() {
    double x, y, a, b, d1, d2, c;
    std::vector<Figures *> figure;

//    rectangle
    x = 0, y = 0, a = -1, b = -1;
    std::cout << "Input rectangle. The First one is point. The second one are a and b" << std::endl
              << "x, y is a left bottom corner coords" << std::endl
              << "a and b are width and height" << std::endl;
    std::cin >> x >> y >> a >> b;
    Rectangle *rectangle = nullptr;
    try {
        rectangle = new Rectangle(x, y, a, b);
    }
    catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }

    figure.push_back(rectangle);


//    Trapeze
    x = 0.0, y = 0.0, a = -1.0, b = -1.0, c = -1.0;
    std::cout << "Input trapeze. The First one is point. The second one are a, b and c." << std::endl
              << "x, y is a left bottom corner coords" << std::endl
              << "a, b and c are larger, smaller base and side" << std::endl;
    std::cin >> x >> y >> a >> b >> c;
    Trapeze *trapeze = nullptr;
    try {
        trapeze = new Trapeze(x, y, a, b, c);
    }
    catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }

    figure.push_back(trapeze);


    x = 0.0, y = 0.0, d1 = -1, d2 = -1;
    std::cout << "Input rhombus. The First one is point. The second one are d1 and d2." << std::endl
              << "x, y is a left corner coords" << std::endl
              << "d1 is a bigger diagonal. d2 is smaller diagonal" << std::endl;
    std::cin >> x >> y >> d1 >> d2;
    Rhombus *rhombus = nullptr;
    try {
        rhombus = new Rhombus(x, y, d1, d2);
    }
    catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }

    figure.push_back(rhombus);

// working with vector
    for (auto fig : figure) {
        fig->Print();
        std::cout << "Center of figure is " << fig->Center() << std::endl;
        std::cout << "Square of figure is " << fig->Area() << std::endl;
    }
    std::cout << "Total square: " << TotalArea(figure) << std::endl;
    int i = 0;
    std::cout << "Input index to remove figure" << std::endl;
    std::cin >> i;
    for (auto fig = figure.begin(); fig != figure.end() and i > 0; ++fig) {
        --i;
        if (i == 0) {
            figure.erase(fig);
        }
    }
    for (auto fig : figure) {
        fig->Print();
        std::cout << "Center of figure is " << fig->Center() << std::endl;
        std::cout << "Square of figure is " << fig->Area() << std::endl;
    }
    std::cout << "Total square after erase: " << TotalArea(figure) << std::endl;

    return 0;
}