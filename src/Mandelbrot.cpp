//
// Created by Alex Vakhno on 2019-05-28.
//

#include "Mandelbrot.h"
#include <complex>

using namespace std;

namespace fractal {

    Mandelbrot::Mandelbrot() {}

    Mandelbrot::~Mandelbrot() {}

    //calculating iterations for each pixel according to Mandelbrot Algorithm
    int Mandelbrot::getIterations(double x, double y) {

        complex<double> z = 0;
        complex<double> c(x, y);

        int iterations = 0;

        while (iterations < MAX_ITERATIONS) {
            z = z * z + c;
            if (abs(z) > 2) {
                break;
            }
            iterations++;
        }

        return iterations;
    }

}