# ifndef GAME_H
# define GAME_H
# include<SDL2/SDL.h>
# include<SDL2/SDL_mixer.h>
# include<SDL2/SDL_image.h>
# include<string>
# include<stdexcept>

class GameEngine{
private:
    SDL_Window* window;
    SDL_Surface* screen;
    SDL_Renderer* renderer;
    Mix_Music* music;
    bool running;
public:
    GameEngine();
    ~GameEngine();
    void init();
    void mainLoop();
    void terminate();
};

# endif
