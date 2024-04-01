#include "Header.h"
#include <math.h>

void Discriminant(const double a, const double b, const double c, double& D) {
    D = b * b - 4 * a * c;
}

void Roots(const double a, const double b, const double D, double& x1, double& x2) {
    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);
};