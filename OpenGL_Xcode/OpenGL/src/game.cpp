#include "game.h"
#include "resource_manager.h"
#include "sprite_render.h"

SpriteRenderer *Renderer;

Game::Game(int width, int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
    
}

Game::~Game()
{
    
}

void Game::Init()
{
    // load shader

    ResourceManager::LoadShader("resources/shaders/sprite.vs" , "resources/shaders/sprite.fs", nullptr, "sprite");
    
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    
    auto spriteShader = ResourceManager::GetShader("sprite");
    spriteShader.Use();
    spriteShader.setInt("image", 0);
    spriteShader.setMat4("projection", projection);
    
    ResourceManager::LoadTexture("resources/textures/awesomeface.png", true, "face");
    Renderer = new SpriteRenderer(spriteShader);
    
}

void Game::Update(float delta)
{
    
}

void Game::ProcessInput(float delta)
{
    
}

void Game::Render()
{
    Renderer->DrawSprite(ResourceManager::GetTexture("face"), glm::vec2(200,200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
