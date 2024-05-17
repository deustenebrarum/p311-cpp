#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

struct Rect {
    Point position;
    int height;
    int width;
};

void Rect_Print(const Rect& rect) {
    for (int i = 0; i < rect.position.y; i++) {
        std::cout << '\n';
    }
    for (int i = 0; i < rect.height; i++) {
        for (int j = 0; j < rect.position.x; j++) {
            std::cout << ' ';
        }
        for (int j = 0; j < rect.width; j++) {
            std::cout << '#';
        }
        std::cout << '\n';
    }
}

struct Fraction {
    int numerator;
    int denominator;
};

Fraction Fraction_Sum(Fraction f1, Fraction f2) {
    int denominator = f1.denominator * f2.denominator;
    
    return {
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        denominator
    };
}

int main() {
    Rect_Print(Rect{
        { 3, 3 },
        5, 7
    });
}

double length(
    const Point p1, 
    const Point p2
) {
    int x_diff = p1.x - p2.x;
    int y_diff = p1.y - p2.y;
    
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}
