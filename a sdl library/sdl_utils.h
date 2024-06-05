#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <utility>
#include <string>

class sdl_utils {
public:
    class sdlUtils {
    public:
        static bool init();
        static std::pair<SDL_Window*, SDL_Renderer*> windowAndRenderer(std::string name);
        static void closeSDL();
        static void clearScreen(SDL_Renderer* renderer, bool color);
        static void square(SDL_Renderer* renderer, int x, int y, int width, int height);
        static std::pair<SDL_Window*, SDL_Renderer*> start(std::string name);


        static void renderText(SDL_Renderer* renderer, std::string text, int x, int y, int fontSize, SDL_Color color);
        static bool button(int x_start, int y_start, int x_end, int y_end);
    };
};
