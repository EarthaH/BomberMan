#pragma once

// Std. Includes
#include <vector>

#include <iostream>
#include "glm/ext.hpp"

// GL Includes
#define GLEW_STATIC
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const GLfloat YAW        = -90.0f;
const GLfloat PITCH      =  -89.0f;
const GLfloat SPEED      =  6.0f;
const GLfloat SENSITIVTY =  0.25f;
const GLfloat ZOOM       =  45.0f;

// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera
{
    public:
        Camera();
        Camera(Camera const &);
        ~Camera();

        Camera  const & operator=(Camera const &);

        // Constructor with vectors
        Camera( glm::vec3 position = glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3 up = glm::vec3( 0.0f, 1.0f, 0.0f ), GLfloat yaw = YAW, GLfloat pitch = PITCH);
        
        // Constructor with scalar values
        Camera( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        
        // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
        glm::mat4 GetViewMatrix( );
        
        // Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
        void ProcessKeyboard( Camera_Movement direction, GLfloat deltaTime );
        
        // Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
        void ProcessMouseMovement( GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = true );
        
        GLfloat GetZoom( );
        
        glm::vec3 GetPosition( );

        glm::vec3 bombermanLevelBegin(glm::vec3 coordinates);
        
    private:
        // Camera Attributes
        glm::vec3 position;
        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;
        glm::vec3 worldUp;
        
        // Eular Angles
        GLfloat yaw;
        GLfloat pitch;
        
        // Camera options
        GLfloat movementSpeed;
        GLfloat mouseSensitivity;
        GLfloat zoom;
        
        // Calculates the front vector from the Camera's (updated) Eular Angles
        void updateCameraVectors( );
};