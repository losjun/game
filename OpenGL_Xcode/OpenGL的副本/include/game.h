#ifdef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum GameState{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
}

class Game
{
public:
    GameState State;
    bool    Keys[1024];
    int     Width, Height;
    Game(int width, int height);
    ~Game();
    void Init();
    void ProcessInput(float delta);
    void Update(float delta);
    void Render();
}

#endif
