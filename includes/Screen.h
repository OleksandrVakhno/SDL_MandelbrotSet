//
// Created by Alex Vakhno on 2019-05-27.
//


#ifndef SDL_MANDELBROTSET_SCREEN_H
#define SDL_MANDELBROTSET_SCREEN_H

#include <SDL.h>
#include <iostream>


using namespace std;


namespace display {
    class Screen {
    public:
        const static int SCREEN_WIDTH{1000};
        const static int SCREEN_HEIGHT{800};
    private:
        SDL_Window * _window{nullptr};
        SDL_Renderer *_renderer{nullptr};
        SDL_Texture *_texture{nullptr};
        Uint32 *_buffer1{nullptr};
        Uint32 *_buffer2{nullptr};
    public:
        Screen();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        void update();
        bool quit();
        void close();

    public:
        class InitException: public exception{};
        class WindowException: public exception{};
        class RendererException: public exception{};
        class TextureException: public exception{};
    };


}

#endif //SDL_MANDELBROTSET_SCREEN_H
