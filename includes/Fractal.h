//
// Created by Alex Vakhno on 2019-05-28.
//

#ifndef SDL_MANDELBROTSET_FRACTAL_H
#define SDL_MANDELBROTSET_FRACTAL_H

#include <iostream>
#include <vector>
#include "Zoom.h"
//#include "Bitmap.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "RGB.h"
#include "Screen.h"



using namespace std;
using namespace display;

namespace fractal {
    class Fractal {
    private:
        const int _width;
        const int _height;
        int _total{0};

        vector<int> _range;
        vector<RGB> _colors;
        vector<int> _rangeTotals;

        bool _gotFirstRange{false};


        Screen* _screen;
        unique_ptr<ZoomList> _zoomlist;

        unique_ptr<int[]> _histogram;
        unique_ptr<int[]> _fractal;
    private:
        void calculateIterations();

        void  calculateTotalIterations();

        int getRange(int iterations) const;

    public:

        Fractal(Screen& screen);

        virtual ~Fractal();

        void addZoom(const Zoom &zoom);

        void addColorRange(double end, const RGB& rgb);

        void calculateRangePixelTotals();

        void draw();


    };
}


#endif //SDL_MANDELBROTSET_FRACTAL_H
