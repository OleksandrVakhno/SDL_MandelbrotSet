//
// Created by Alex Vakhno on 2019-05-28.
//

#ifndef SDL_MANDELBROTSET_ZOOMLIST_H
#define SDL_MANDELBROTSET_ZOOMLIST_H

#include "Zoom.h"
#include <vector>
#include <utility>

using namespace std;


namespace display {
    class ZoomList {
    private:
        double _xCenter{0};
        double _yCenter{0};
        double _scale{1.0};
        int _width{0};
        int _height{0};
        vector<Zoom> zooms;
    public:
        ZoomList(int width, int height);
        void add(const Zoom& zoom );
        pair<double, double> doZoom(int x, int y);

    };
}


#endif //SDL_MANDELBROTSET_ZOOMLIST_H
