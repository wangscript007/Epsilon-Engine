#pragma once

#include <Core.hpp>

class GPU
{
public:
    GPU(){
        mVendor = (char*)glGetString(GL_VENDOR);
        mDriverVersion = (char*)glGetString(GL_RENDERER);
        mDevice = (char*)glGetString(GL_VERSION);
        glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &mMaxTextureUnitsInFragmentShader);
    }
    ~GPU(){}

    std::string getDriverVersion()
    {
        return mDriverVersion;
    }

    std::string getVendor()
    {
        return mVendor;
    }

    std::string getDevice()
    {
        return mDevice;
    }
    
    GLint getMaxtextureUnits()
    {
        return mMaxTextureUnitsInFragmentShader;
    }

    size_t getAvailableMemory()
    {
        GLint cur_avail_mem_kb = 0;
        glGetIntegerv(GL_GPU_MEM_INFO_CURRENT_AVAILABLE_MEM_NVX,
                      &cur_avail_mem_kb);

        if(getTotalMemory() <= 0) {
        GLint cur_avail_mem_kb = 0;
        glGetIntegerv( GL_TEXTURE_FREE_MEMORY_ATI,
                        &cur_avail_mem_kb );

        }

        return cur_avail_mem_kb;
    }

    size_t getTotalMemory()
    {
        GLint total_mem_kb = 0;
        glGetIntegerv(GL_GPU_MEM_INFO_TOTAL_AVAILABLE_MEM_NVX,
                      &total_mem_kb);

	#ifdef _WIN32 //These functions are not present in linux
#ifndef EPSILON_STATIC
        if(total_mem_kb <= 0) {
            GLuint uNoOfGPUs = wglGetGPUIDsAMD( 0, 0 );
            GLuint* uGPUIDs = new GLuint[uNoOfGPUs];
            wglGetGPUIDsAMD( uNoOfGPUs, uGPUIDs );

            GLuint total_mem_kb = 0;
            wglGetGPUInfoAMD( uGPUIDs[0],
                              WGL_GPU_RAM_AMD,
                              GL_UNSIGNED_INT,
                              sizeof( GLuint ),
                              &total_mem_kb );

            total_mem_kb *= 1024;

        }
        #endif
#endif

        return total_mem_kb;
    }

private:
    std::string mVendor;
    std::string mDriverVersion;
    std::string mDevice;
    GLint mMaxTextureUnitsInFragmentShader = 0;
};
