#include "sdl_utils.h"
#include <iostream>

int main(int argc, char* argv[]) {


    // Call start() to initialize SDL and obtain the window and renderer
    auto [window, renderer] = sdl_utils::sdlUtils::start("SDL Window");
    if (window == nullptr || renderer == nullptr) {
        // Initialization failed, handle error
        return 1;
    }

    // Clear the screen
    sdl_utils::sdlUtils::clearScreen(renderer, false);

    // Set render color
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color

    // Draw a square in the center
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    sdl_utils::sdlUtils::square(renderer, width / 2 - 100, height / 2 - 100, 200, 200);

    //Draw a text on the square

    SDL_Color textColor = { 255, 255, 255 };
    sdl_utils::sdlUtils::renderText(renderer, "hello", width / 2 - 100, height / 2 - 50, 90, textColor);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Main loop
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        if (sdl_utils::sdlUtils::button(width / 2 - 100, height / 2 - 100, width / 2 - 100 + 200, height / 2 - 100 + 200))
        {
            quit = true;
        }

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || sdl_utils::sdlUtils::button(width / 2 - 100, height / 2 - 100, width / 2 - 100 + 200, height / 2 - 100 + 200))
                quit = true;
        }
    }

    // Cleanup
    sdl_utils::sdlUtils::closeSDL();

    return 0;
}