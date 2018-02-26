
#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Texture2D
{
public:
    unsigned int ID; //Id of the texture object
    
    int Width, Height; // Width and height of loaded image in pixels
    
    int Internal_Format; // Format of texture object
    int Image_Format; // Format of loaded image
    
    // Texture configuration
    int Wrap_S; // Wrapping mode on S axis
    int Wrap_T; // Wrapping mode on T axis
    int Filter_Min; // Filtering mode if texture pixels < screen pixels
    int Filter_Max; // Filtering mode if texture pixels > screen pixels
    
    Texture2D();
    
    void Generate(int width, int height, unsigned char* data);
    
    void Bind() const; // Binds the texture as the current active GL_TEXTURE_2D texture objext
    
    
};

#endif
