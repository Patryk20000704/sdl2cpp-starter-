#include "sdl_utils.h"

bool sdl_utils::sdlUtils::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    
    if (TTF_Init() == -1) {
        SDL_Log("Failed to initialize SDL_ttf: %s", TTF_GetError());
        return false;
    }

    return true;
}

std::pair<SDL_Window*, SDL_Renderer*> sdl_utils::sdlUtils::windowAndRenderer(std::string name) {
    const char* working_name = name.c_str();
    SDL_Window* window = SDL_CreateWindow(working_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Quit();
        return std::make_pair(nullptr, nullptr);
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return std::make_pair(nullptr, nullptr);
    }

    return std::make_pair(window, renderer);
}

void sdl_utils::sdlUtils::closeSDL() {
    
    TTF_Quit();
    SDL_Quit();
}

void sdl_utils::sdlUtils::clearScreen(SDL_Renderer* renderer, bool color) {
    if (color)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
    }


    SDL_RenderClear(renderer); // Clear the screen
}

std::pair<SDL_Window*, SDL_Renderer*> sdl_utils::sdlUtils::start(std::string name) {
    if (!init()) {
        return std::make_pair(nullptr, nullptr);
    }

    auto [window, renderer] = windowAndRenderer(name);
    if (window == nullptr || renderer == nullptr) {
        closeSDL();
        return std::make_pair(nullptr, nullptr);
    }

    return std::make_pair(window, renderer);
}

void sdl_utils::sdlUtils::square(SDL_Renderer* renderer, int x, int y, int width, int height)
{
    // Draw a square
    SDL_Rect rect = { x, y, width, height }; // x, y, width, height
    SDL_RenderFillRect(renderer, &rect);
}

// Implementing renderText function
void sdl_utils::sdlUtils::renderText(SDL_Renderer* renderer, std::string text, int x, int y, int fontSize, SDL_Color color) {
    
    TTF_Font* font = TTF_OpenFont("Roboto-Black.ttf", fontSize);
    if (font == nullptr) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return;
    }

    
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr) {
        SDL_Log("Unable to render text surface: %s", TTF_GetError());
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        SDL_Log("Unable to create texture from rendered text: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
        return;
    }

    SDL_Rect dstRect = { x, y, surface->w, surface->h }; // Destination rect
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    // Clean up
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

bool sdl_utils::sdlUtils::button(int x_start, int y_start, int x_end, int y_end)
{
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                // Check if the click occurred within the button's area
                if (event.button.x >= x_start && event.button.x <= x_end &&
                    event.button.y >= y_start && event.button.y <= y_end) {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}
