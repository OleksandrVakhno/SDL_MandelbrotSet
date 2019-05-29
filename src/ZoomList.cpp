//
// Created by Alex Vakhno on 2019-05-28.
//

#include "ZoomList.h"


namespace display{
    ZoomList::ZoomList(int width, int height):_width(width), _height(height) {}
    void ZoomList::add(const display::Zoom &zoom) {
        zooms.push_back(zoom);

        _xCenter += (zoom.x - double(_width)/2)*_scale;
        _yCenter += (zoom.y - double(_height)/2)*_scale;

        _scale *= zoom.scale;

    }
    pair<double,double> ZoomList::doZoom(int x, int y){
        double xFractal =(x - double(_width)/2)* _scale + _xCenter;
        double  yFractal =(y - double(_height)/2)* _scale + _yCenter;

        return pair<double, double>(xFractal, yFractal);
    }
}
