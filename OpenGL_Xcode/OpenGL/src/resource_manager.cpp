#include "resource_manager.h"

#include <iostream>
#include <sstream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::map<std::string, Texture2D>    ResourceManager::Textures;
std::map<std::string, Shader>       ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name)
{
    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}
Shader ResourceManager::GetShader(std::string name)
{
    return Shaders[name];
}

Texture2D &ResourceManager::LoadTexture(const char *file, bool alpha, std::string name)
{
    Textures.insert(std::pair<std::string, Texture2D>(name, loadTextureFromFile(file, alpha)));
    return Textures[name];
}

Texture2D &ResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}

void ResourceManager::Clear()
{
    for(auto iter : Shaders)
    {
        glDeleteProgram(iter.second.ID);
    }
    
    for(auto iter: Textures)
    {
        glDeleteProgram(iter.second.ID);
    }
}

Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
{
    Shader shader(vShaderFile, fShaderFile, gShaderFile);
    return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    Texture2D texture;
    if(alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    // Load image
    int width, height, nrChannels;

    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
    if (data)
    {
        texture.Generate(width, height, data);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return texture;
}














