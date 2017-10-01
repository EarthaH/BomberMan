#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../includes/shader.hpp"

//using namespace std;

struct Vertex
{
    // Position
    glm::vec3 Position;
    // Normal
    glm::vec3 Normal;
    // TexCoords
    glm::vec2 TexCoords;
};

struct Texture
{
    GLuint id;
    std::string type;
    aiString path;
};

class Mesh
{
public:
    /*  Mesh Data  */
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    
    /*  Functions  */
    // Constructor
    Mesh( std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures );
    
    // Render the mesh
    void Draw( Shader shader );
    
private:
    /*  Render data  */
    GLuint VAO, VBO, EBO;
    
    /*  Functions    */
    // Initializes all the buffer objects/arrays
    void setupMesh( );
};


