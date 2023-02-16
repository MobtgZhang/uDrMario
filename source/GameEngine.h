# ifndef GAME_H
# define GAME_H
# include<SDL2/SDL.h>

class GameEngine{
public:
    GameEngine();
    ~GameEngine();
    void init();
    void mainLoop();
    void terminate();
};

# endif
