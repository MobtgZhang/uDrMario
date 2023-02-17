# include "GameEngine.h"
# include "CFG.h"

GameEngine::GameEngine(){

}

GameEngine::~GameEngine(){
    
}

void GameEngine::init(){
    // Initialize SDL2
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)<0){
        std::string msg = "SDL could not be initialized. SDL Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }
    // Create the main windows
    window = SDL_CreateWindow(SCREEN_WINDOWS_TITLE,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WINDOWS_WIDTH,SCREEN_WINDOWS_HEIGHT,SDL_WINDOW_SHOWN);
    if(window == nullptr){
        std::string msg = "Window could not be created. SDL Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    // Set scaling interpolation algorithm
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, SCALING_QUALITY);

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::string msg = "Renderer could not be created. SDL Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    //Initialize image loading
    int flags = IMG_INIT_PNG;
    int imginit = IMG_Init(flags);
    if((imginit&flags) != flags){
        std::string msg = "SLD_image could not be initialized. SDL_image Error: ";
        std::string error = IMG_GetError();
        throw std::runtime_error(msg+error);
    }

    //Initialize SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        std::string msg = "SLD_mixer could not be initialized. SDL_mixer Error: ";
        std::string error = Mix_GetError();
        throw std::runtime_error(msg+error);
    }

    screen = SDL_GetWindowSurface(window);

    running = true;

}

void GameEngine::mainLoop(){

}

void GameEngine::terminate(){

}
