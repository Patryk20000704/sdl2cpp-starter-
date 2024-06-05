SDL Utilities Library This library provides a set of utility functions for working with the Simple DirectMedia Layer (SDL) library. It includes functions for initializing and cleaning up SDL, creating windows and renderers, rendering text, drawing shapes, and handling user input.

Functions

    bool init(): Initializes SDL and SDL_ttf libraries. Returns true if successful, false otherwise.
    std::pair<SDL_Window*, SDL_Renderer*> windowAndRenderer(std::string name): Creates a window and renderer with the given name. Returns a pair of pointers to the window and renderer, or a pair of null pointers if creation fails.
    void closeSDL(): Cleans up and quits SDL and SDL_ttf libraries.
    void clearScreen(SDL_Renderer* renderer, bool color): Clears the screen with the specified color.
    std::pair<SDL_Window*, SDL_Renderer*> start(std::string name): Initializes SDL, creates a window and renderer, and returns a pair of pointers to the window and renderer.
    void square(SDL_Renderer* renderer, int x, int y, int width, int height): Draws a square on the renderer at the specified position and size.
    void renderText(SDL_Renderer* renderer, std::string text, int x, int y, int fontSize, SDL_Color color): Renders the given text on the renderer at the specified position, size, and color.
    bool button(int x_start, int y_start, int x_end, int y_end): Checks if the left mouse button is clicked within the specified button area. Returns true if clicked, false otherwise.

Dependencies

This library depends on the SDL and SDL_ttf libraries. Make sure to link against the appropriate SDL and SDL_ttf libraries when compiling the code.

Usage

To use this library, include the sdl_utils.h header file in your code and create an instance of the sdlUtils class. Then, call the desired utility functions as needed.

Make sure to call closeSDL() before exiting the program to clean up SDL and SDL_ttf libraries.