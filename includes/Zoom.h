//
// Created by Alex Vakhno on 2019-05-28.
//

#ifndef SDL_MANDELBROTSET_ZOOM_H
#define SDL_MANDELBROTSET_ZOOM_H
namespace display {
    struct Zoom {
        int x{0};
        int y{0};
        double scale{0};
        Zoom(int x, int y, double scale): x(x), y(y), scale(scale){};
    };
}
#endif //SDL_MANDELBROTSET_ZOOM_H
