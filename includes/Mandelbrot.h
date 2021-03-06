//
// Created by Alex Vakhno on 2019-05-28.
//

#ifndef SDL_MANDELBROTSET_MANDELBROT_H
#define SDL_MANDELBROTSET_MANDELBROT_H


namespace fractal {
    class Mandelbrot {
    public:
        static int MAX_ITERATIONS;

    public:
        Mandelbrot();

        virtual ~Mandelbrot();

        static int getIterations(double x, double y);

    };
}


#endif //SDL_MANDELBROTSET_MANDELBROT_H
