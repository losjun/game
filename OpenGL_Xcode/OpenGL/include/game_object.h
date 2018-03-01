

#ifndef game_object_h
#define game_object_h

#include "texture.h"
#include "sprite_render.h"

class GameObject
{
public:
    // Object state
    glm::vec2 Position, Size, Velocity;
    glm::vec3 Color;
    float Rotation;
    bool IsSolid;
    bool Destroyed;
    
    // Render state
    Texture2D Sprite;
    
    GameObject();
    GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
    
    // Draw sprite
    virtual void Draw(SpriteRenderer & renderer);
};


#endif /* game_object_h */
