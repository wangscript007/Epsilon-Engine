///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================

#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <GL/glew.h>
#include <string>
#include <iostream>

class Shader{
public:

   Shader(const char*, const char*);
   virtual ~Shader(void){
   }

    void Use(void){glUseProgram(this->ProgramID);}

    void Free(void){glUseProgram(0);}

    GLuint getProgramID(){return this->ProgramID;}

    std::string getPath(){return this->Path;}

private:
    GLuint ProgramID;
    std::string Path;

    void getUniformsLocations();

public:
    GLuint MVP_Location;
    GLuint WorldTransform_Location;
    GLuint Projection_Location;
    GLuint View_Location;
    GLuint ViewDirection_Location;
    GLuint ViewPosition_Location;
    GLuint LightSpaceMatrix_Location;
    GLuint ModelView3x3Matrix_Location;
    GLuint NormalMatrix_Location;
    GLuint LightDirection_Location;
    GLuint ClipPlane_Location;
    GLuint Time_Location;
    GLuint texture_diffuse_Location;
    GLuint texture_specular_Location;
    GLuint texture_normal_Location;
    GLuint texture_height_Location;
    GLuint skybox_Location;

};


#endif /// SHADER_H_INCLUDED
