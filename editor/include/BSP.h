///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================

#ifndef BSP_H_INCLUDED
#define BSP_H_INCLUDED

#define MAX_TEXTURES 1000
#define FACE_POLYGON	1
#define FACE_UNUSED     2
#define FACE_MESHVERT   3

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <memory>

#include "include/BSPFace.h"

#include "include/Frustum.h"
#include <include/texture.hpp>

struct CVector3
{
    float x, y, z;
};

struct tVector3i
{
    int x, y, z;
};

struct CVector2
{
    float x, y;
};

struct tBSPHeader
{
    char strID[4];
    int version;
};


struct tBSPLump
{
    int offset;
    int length;
};


struct tBSPVertex
{
    glm::vec3 vPosition;
    glm::vec2 vTextureCoord;
    glm::vec2 vLightmapCoord;
    glm::vec3 vNormal;
    char color[4];
};



struct tBSPFace
{
    int textureID;
    int effect;
    int type;
    int startVertIndex;
    int numOfVerts;
    int startIndex;
    int numOfIndices;
    int lightmapID;
    int lMapCorner[2];
    int lMapSize[2];
    CVector3 lMapPos;
    CVector3 lMapVecs[2];
    CVector3 vNormal;
    int size[2];
};

struct tBSPTexture
{
    char strName[64];
    int flags;
    int contents;
};

struct BSPTexture
{
std::string path;
GLuint GLTextureID;
int type;
};


enum eLumps
{
    kEntities = 0,
    kTextures,
    kPlanes,
    kNodes,
    kLeafs,
    kLeafFaces,
    kLeafBrushes,
    kModels,
    kBrushes,
    kBrushSides,
    kVertices,
    kIndices,
    kShaders,
    kFaces,
    kLightmaps,
    kLightVolumes,
    kVisData,
    kMaxLumps
};


struct tBSPNode
{
    int plane;
    int front;
    int back;
    tVector3i min;
    tVector3i max;
};

struct tBSPLeaf
{
    int cluster;
    int area;
    tVector3i min;
    tVector3i max;
    int leafface;
    int numOfLeafFaces;
    int leafBrush;
    int numOfLeafBrushes;
};


struct tBSPPlane
{
    CVector3 vNormal;
    float d;
};

struct tBSPVisData
{
	int numOfClusters;
	int bytesPerCluster;
    char *pBitsets;
};

struct tBSPEntitie
{
	string ents;
};

class CBitset
{

public:


    CBitset() : m_bits(0), m_size(0) {}


    ~CBitset()
    {

        if(m_bits)
        {
            delete m_bits;
            m_bits = NULL;
        }
    }

    void Resize(int count)
    {

        m_size = count/32 + 1;

        if(m_bits)
        {
            delete m_bits;
            m_bits = 0;
        }

        m_bits = new unsigned int[m_size];
        ClearAll();
    }

    void Set(int i)
    {
        m_bits[i >> 5] |= (1 << (i & 31));
    }

    int On(int i)
    {
        return m_bits[i >> 5] & (1 << (i & 31 ));
    }

    void Clear(int i)
    {
        m_bits[i >> 5] &= ~(1 << (i & 31));
    }

    void ClearAll()
    {
        memset(m_bits, 0, sizeof(unsigned int) * m_size);
    }

private:

    unsigned int *m_bits;
    int m_size;
};


class CQuake3BSP
{

public:

    CQuake3BSP();

    virtual ~CQuake3BSP(){
        delete VertexBufferArrays;
        //cout << "Destroyed BSP map" << endl;
    }

    bool LoadBSP(const char *strFileName);

    bool isLoaded() {return mIsLoaded; }

    void RenderLevel(glm::vec3 vPos, GLuint shader, bool Shadow);

    void Destroy();

    CFrustum Frustum;

private:

    void FindTextureExtension(char *strFileName);

    void RenderFace(int faceIndex, GLuint shader, GLuint texID);

    int IsClusterVisible(int current, int test);

	int FindLeaf(glm::vec3 vPos);

    int  m_numOfVerts;
    int  m_numOfFaces;
    int  m_numOfIndices;
    int  m_numOfTextures;
    int  m_numOfLightmaps;


	int m_numOfNodes;
	int m_numOfLeafs;
	int m_numOfLeafFaces;
	int m_numOfPlanes;

    int			*m_pIndices;
    tBSPVertex  *m_pVerts;
    tBSPFace	*m_pFaces;


	tBSPNode    *m_pNodes;
	tBSPLeaf    *m_pLeafs;
	tBSPPlane   *m_pPlanes;
	int         *m_pLeafFaces;
	tBSPVisData  m_clusters;

    unsigned int m_textures[MAX_TEXTURES];

    unsigned int* VertexBufferArrays;

    CBitset m_FacesDrawn;

    std::map<int, BSPFace> Faces;
    std::vector<OpenGL::Texture*> Textures;
    std::map<int, OpenGL::Texture*> faceTexture;

    std::map<int, OpenGL::Texture*> faceTexture_normal;
    std::map<int, OpenGL::Texture*> faceTexture_specular;
    std::map<int, OpenGL::Texture*> faceTexture_metallic;
    std::vector<OpenGL::Texture*> normalTextures;
    std::vector<OpenGL::Texture*> specularTextures;
    std::vector<OpenGL::Texture*> metallicTextures;

    bool lightmap;
    bool color;
    bool mIsLoaded = false;
    int faceCount;
    GLuint NormalTextureID;

};


#endif /// BSP_H_INCLUDED
