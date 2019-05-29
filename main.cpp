#include <iostream>
#include <unistd.h>
#include "Fractal.h"

using namespace std;
using namespace display;
using namespace fractal;

int main() {

    try{

        Screen screen;
        Fractal fractal(screen);

        fractal.addColorRange(0.0, RGB(0, 0, 255));
        fractal.addColorRange(0.5, RGB(255, 99, 71));
        fractal.addColorRange(0.8, RGB(255, 215, 0));
        fractal.addColorRange(1, RGB(255,255,255));

        fractal.draw();

        while(true){
            screen.update();

            SDL_PumpEvents();
            int x,y;
            if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                fractal.addZoom(Zoom(x,y,0.1));
                fractal.draw();
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