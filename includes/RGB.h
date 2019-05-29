//
// Created by Alex Vakhno on 2019-05-28.
//

#ifndef SDL_MANDELBROTSET_RGB_H
#define SDL_MANDELBROTSET_RGB_H

namespace display {
    struct RGB {
        double r;
        double g;
        double b;
        RGB(double r, double g, double b): r(r), b(b), g(g){};
    };

    RGB operator-(const RGB& first, const RGB& second);

}



#endif //SDL_MANDELBROTSET_RGB_H
