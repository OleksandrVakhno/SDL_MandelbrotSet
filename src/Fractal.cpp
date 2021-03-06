//
// Created by Alex Vakhno on 2019-05-28.
//

#include "Fractal.h"
namespace fractal{
    Fractal::Fractal(Screen& screen): _width(Screen::SCREEN_WIDTH), _height(Screen::SCREEN_HEIGHT),
                                            _screen(&screen),
                                             _histogram(new int[Mandelbrot::MAX_ITERATIONS]{}),
                                             _fractal(new int[_width*_height]{}),
                                              _zoomlist(new ZoomList(_width, _height))
    {
        //initial Zoom value
        _zoomlist->add(Zoom(_width/2, _height/2 ,4.0/_width));
    }


    //calculating iterations for each pixel according to zoom values
    void Fractal::calculateIterations(){
        for(int y=0; y<_height;y++){
            for(int x=0; x<_width; x++){

                pair<double, double> coords = _zoomlist->doZoom(x,y);

                int iterations = Mandelbrot::getIterations(coords.first, coords.second);

                _fractal[y * _width + x] = iterations;

                if(iterations != Mandelbrot::MAX_ITERATIONS) _histogram[iterations]++;
            }
        }
    }


    void Fractal::draw() {

        calculateIterations();//getting iterations for each pixel

        calculateRangePixelTotals();//getting the max number of pixels for each color range

        //calculating color for each pixel
        for(int y=0; y<_height;y++){
            for(int x=0; x<_width; x++){

                uint8_t red = 0;
                uint8_t green =0;
                uint8_t blue = 0;

                int iterations = _fractal[y*_width+x];

                int range = getRange(iterations);
                int rangeTotal = _rangeTotals[range];
                int rangeStart = _range[range];

                RGB& startColor = _colors[range];
                RGB& endColor = _colors[range+1];
                RGB colorDiff = endColor - startColor;

                if(iterations!=Mandelbrot::MAX_ITERATIONS) {
                    int totalPixels =0 ;
                    for (int i = rangeStart; i <= iterations; i++) {
                        totalPixels+= _histogram[i];
                    }

                    //getting color and its intensity for each pixel
                    red = startColor.r + colorDiff.r*(double)totalPixels/rangeTotal;
                    green =  startColor.g + colorDiff.g*(double)totalPixels/rangeTotal;
                    blue =  startColor.b + colorDiff.b*(double)totalPixels/rangeTotal;

                }

                _screen->setPixel(x,y,red,green,blue);


            }
        }
    }


    //two step zoom in
    void Fractal::draw_zoom() {
        Mandelbrot::MAX_ITERATIONS =100;
        while(Mandelbrot::MAX_ITERATIONS<=2000) {
            draw();
            _screen->update();
            Mandelbrot::MAX_ITERATIONS += 1900;
        }
    }



    void Fractal::addColorRange(double end, const RGB& rgb) {
        _range.push_back(end*Mandelbrot::MAX_ITERATIONS);
        _colors.push_back(rgb);

        if(_gotFirstRange){
            _rangeTotals.push_back(0);
        }

        _gotFirstRange = true;

    }

    //max number of pixels for each range
    void Fractal::calculateRangePixelTotals(){
        int rangeIndex =0;
        for(int i =0 ; i < Mandelbrot::MAX_ITERATIONS; i++){
            int pixels = _histogram[i];
            if(i>= _range[rangeIndex+1]){
                rangeIndex++;
            }
            _rangeTotals[rangeIndex] += pixels;
        }

    }

    //calculation range for a pixel with a specific number of iterations
    int Fractal::getRange(int iterations) const {
        int rangeIndex = 0;
        for(int i = 1; i<_range.size();i++){
            rangeIndex =i ;
            if(_range[i]>iterations){
                break;
            }
        }
        rangeIndex--;
        assert(rangeIndex > -1);
        assert(rangeIndex < _range.size());

        return rangeIndex;
    }


    void Fractal::addZoom(const Zoom &zoom) {
        _zoomlist->add(zoom);
    }


    Fractal::~Fractal() {}

}
