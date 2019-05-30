//
// Created by Alex Vakhno on 2019-05-27.
//

#include "Screen.h"
namespace display{


    Screen::Screen() {
        if (SDL_Init(SDL_INIT_VIDEO)<0){
            cout<<"Error initializing"<<endl;
            throw InitException();
        }

        _window = SDL_CreateWindow("Mandelbrot Fractal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if (_window == NULL){
            SDL_Quit();
            throw WindowException();
        }
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
        if(_renderer == NULL){
            SDL_DestroyWindow(_window);
            SDL_Quit();
            throw RendererException();
        }
        _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,  SCREEN_WIDTH, SCREEN_HEIGHT);
        if(_texture == NULL){
            SDL_DestroyRenderer(_renderer);
            SDL_DestroyWindow(_window);
            SDL_Quit();
            throw TextureException();
        }

        _buffer1 = new Uint32 [SCREEN_WIDTH*SCREEN_HEIGHT];
        _buffer2 = new Uint32 [SCREEN_WIDTH*SCREEN_HEIGHT];


        memset(_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
        memset(_buffer2, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
        if (x<0 || x>=SCREEN_WIDTH || y<0 || y>=SCREEN_HEIGHT){
            return;
        }

        Uint32 color = 0;
        color+=red;
        color<<=8;
        color+=green;
        color<<=8;
        color+=blue;
        color<<=8;
        color+=0xFF;

        _buffer1[(y*SCREEN_WIDTH)+x]=color;
    }

    void Screen::update() {
        SDL_UpdateTexture(_texture, NULL, _buffer1, 1000*sizeof(Uint32));
        SDL_RenderClear(_renderer);
        SDL_RenderCopy(_renderer,_texture, NULL, NULL);
        SDL_RenderPresent(_renderer);
    }
    

    bool Screen::quit() {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return true;
            }
        }
        return false;
    }

    void Screen::close(){
        delete [] _buffer1;
        delete [] _buffer2;


        SDL_DestroyRenderer(_renderer);
        SDL_DestroyTexture(_texture);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

}
