#include <iostream>
#include <unistd.h>
#include "Fractal.h"

using namespace std;
using namespace display;
using namespace fractal;

int fractal::Mandelbrot::MAX_ITERATIONS = 2000;

int main() {

    try{

        Screen screen;
        Fractal fractal(screen);


        //adding colors for different ranges in fractal
        fractal.addColorRange(0.0, RGB(0, 0, 255));
        fractal.addColorRange(0.5, RGB(255, 99, 71));
        fractal.addColorRange(0.8, RGB(255, 215, 0));
        fractal.addColorRange(1, RGB(255,255,255));

        fractal.draw();
        screen.update();

        //main loop updating the picture
        while(true){

            //checking for cursor position to zoom in
            SDL_PumpEvents();
            int x,y;
            if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                fractal.addZoom(Zoom(x,y,0.1));
                fractal.draw_zoom();
            }

            if(screen.quit()){
                break;
            }

        }


        screen.close();
    }
    catch (exception &e){
        cout<<"An exception of type: '" << typeid(e).name()<<"' occured."<<endl;
    }




    return 0;
}