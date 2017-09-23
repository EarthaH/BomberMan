#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader
{
    public:
        GLuint Program;

        Shader();
        Shader(Shader const &);
        ~Shader();
        // Constructor generates the shader on the fly
        Shader( const GLchar *vertexPath, const GLchar *fragmentPath );

        Shader const & operator=(Shader const &);

        // Uses the current shader
        void Use( );
};

#endif