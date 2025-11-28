#include "../include/MathFunctions.h"
#include <cmath>
#include <stdexcept>

namespace MathFunctions {

double sinTaylor(double x) {
    x = fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    if (x < -M_PI) x += 2 * M_PI;
    
    double result = 0.0;
    double term = x;
    double x2 = x * x;
    int n = 1;
    
    for (int i = 0; i < 10; ++i) {
        result += term;
        term *= -x2 / ((2 * n) * (2 * n + 1));
        n++;
    }
    return result;
}

double cosTaylor(double x) {
    x = fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    if (x < -M_PI) x += 2 * M_PI;
    
    double result = 0.0;
    double term = 1.0;
    double x2 = x * x;
    int n = 1;
    
    for (int i = 0; i < 10; ++i) {
        result += term;
        term *= -x2 / ((2 * n - 1) * (2 * n));
        n++;
    }
    return result;
}

double tanTaylor(double x) {
    double cosx = cosTaylor(x);
    if (fabs(cosx) < 1e-10) {
        throw std::runtime_error("error: in parser tan(x) where cos(x)=0");
    }
    return sinTaylor(x) / cosx;
}

}
