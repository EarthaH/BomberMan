#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../external/soil2/src/SOIL2/SOIL2.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../includes/shader.hpp"

#include "Mesh.hpp"

//using namespace std;

GLint TextureFromFile( const char *path, std::string directory );

class Model
{
public:
    /*  Functions   */
    // Constructor, expects a filepath to a 3D model.
    Model( GLchar *path );
    
    // Draws the model, and thus all its meshes
    void Draw( Shader shader );
    
private:
    /*  Model Data  */
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<Texture> textures_loaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    
    /*  Functions   */
    // Loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
    void loadModel( std::string path );
    
    // Processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
    void processNode( aiNode* node, const aiScene* scene );
    
    Mesh processMesh( aiMesh *mesh, const aiScene *scene );
    
    // Checks all material textures of a given type and loads the textures if they're not loaded yet.
    // The required info is returned as a Texture struct.
    std::vector<Texture> loadMaterialTextures( aiMaterial *mat, aiTextureType type, std::string typeName );
};

GLint TextureFromFile( const char *path, std::string directory );
