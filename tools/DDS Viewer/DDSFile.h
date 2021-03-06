#pragma once

#define FOURCC_DXT1 0x31545844
#define FOURCC_DXT3 0x33545844
#define FOURCC_DXT5 0x35545844

#define MAGICNUMBER 0x44445320

constexpr int MAGICNUMBEROFFSET = 4;

struct DDS_PIXELFORMAT {
  int dwSize;
  int dwFlags;
  int dwFourCC;
  int dwRGBBitCount;
  int dwRBitMask;
  int dwGBitMask;
  int dwBBitMask;
  int dwABitMask;
};

struct DDS_HEADER
{
    int           dwSize;
    int           dwFlags;
    int           dwHeight;
    int           dwWidth;
    int           dwPitchOrLinearSize;
    int           dwDepth;
    int           dwMipMapCount;
    int           dwReserved1[11];
    DDS_PIXELFORMAT ddspf;
    int           dwCaps;
    int           dwCaps2;
    int           dwCaps3;
    int           dwCaps4;
    int           dwReserved2;

};


