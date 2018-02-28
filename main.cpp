/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

#include "./Math/Vec2.h"

using namespace std;
using namespace CAN;

struct RGBType
{
    double r;
    double g;
    double b;
};

void savebmp(const char *filename, int width, int height, int dpi, RGBType *data)
{
    // create a file object that we will use to write our image
    FILE *image;
    // we want to know how many pixels to reserve
    int image_size = width * height;
    // a byte is 4 bits but we are creating a 24 bit image so we can represent a pixel with 3
    // our final file size of our image is the width * height * 4 + size of bitmap header
    int file_size = 54 + 4 * image_size;
    // pixels per meter https://www.wikiwand.com/en/Dots_per_inch
    int ppm = dpi * 39.375;

    // /*

    // bitmap file header (14 bytes)
    // we could be savages and just create 2 array but since this is for learning lets
    // use structs so it can be parsed by someone without having to refer to the spec

    // since we have a non-natural set of bytes, we must explicitly tell the
    // compiler to not pad anything, on gcc the attribute alone doesn't work so
    // a nifty trick is if we declare the smallest data type last the compiler
    // *might* ignore padding, in some cases we can use a pragma or gcc's
    // __attribute__((__packed__)) when declaring the struct
    // we do this so we can have an accurate sizeof() which should be 14, however
    // this won't work here since we need to order the bytes as they are written
    struct bitmap_file_header
    {
        unsigned char bitmap_type[2]; // 2 bytes
        int file_size;                // 4 bytes
        short reserved1;              // 2 bytes
        short reserved2;              // 2 bytes
        unsigned int offset_bits;     // 4 bytes
    } bfh;

    // bitmap image header (40 bytes)
    struct bitmap_image_header
    {
        unsigned int size_header;   // 4 bytes
        unsigned int width;         // 4 bytes
        unsigned int height;        // 4 bytes
        short int planes;           // 2 bytes
        short int bit_count;        // 2 bytes
        unsigned int compression;   // 4 bytes
        unsigned int image_size;    // 4 bytes
        unsigned int ppm_x;         // 4 bytes
        unsigned int ppm_y;         // 4 bytes
        unsigned int clr_used;      // 4 bytes
        unsigned int clr_important; // 4 bytes
    } bih;

    // if you are on Windows you can include <windows.h>
    // and make use of the BITMAPFILEHEADER and BITMAPINFOHEADER structs

    memcpy(&bfh.bitmap_type, "BM", 2);
    bfh.file_size = file_size;
    bfh.reserved1 = 0;
    bfh.reserved2 = 0;
    bfh.offset_bits = 0;

    bih.size_header = sizeof(bih);
    bih.width = width;
    bih.height = height;
    bih.planes = 1;
    bih.bit_count = 24;
    bih.compression = 0;
    bih.image_size = file_size;
    bih.ppm_x = ppm;
    bih.ppm_y = ppm;
    bih.clr_used = 0;
    bih.clr_important = 0;

    image = fopen(filename, "wb");

    // compiler woes so we will just use the constant 14 we know we have
    fwrite(&bfh, 1, 14, image);
    fwrite(&bih, 1, sizeof(bih), image);

    // */

/*
    // another way to write bmp, you can annotate ahead code, and cancel this.
    unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

    bmpfileheader[2] = (unsigned char)(file_size);
    bmpfileheader[3] = (unsigned char)(file_size >> 8);
    bmpfileheader[4] = (unsigned char)(file_size >> 16);
    bmpfileheader[5] = (unsigned char)(file_size >> 24);

    bmpinfoheader[4] = (unsigned char)(width);
    bmpinfoheader[5] = (unsigned char)(width >> 8);
    bmpinfoheader[6] = (unsigned char)(width >> 16);
    bmpinfoheader[7] = (unsigned char)(width >> 24);

    bmpinfoheader[8] = (unsigned char)(height);
    bmpinfoheader[9] = (unsigned char)(height >> 8);
    bmpinfoheader[10] = (unsigned char)(height >> 16);
    bmpinfoheader[11] = (unsigned char)(height >> 24);

    bmpinfoheader[21] = (unsigned char)((4 * image_size));
    bmpinfoheader[22] = (unsigned char)((4 * image_size) >> 8);
    bmpinfoheader[23] = (unsigned char)((4 * image_size) >> 16);
    bmpinfoheader[24] = (unsigned char)((4 * image_size) >> 24);

    bmpinfoheader[25] = (unsigned char)(ppm);
    bmpinfoheader[26] = (unsigned char)(ppm >> 8);
    bmpinfoheader[27] = (unsigned char)(ppm >> 16);
    bmpinfoheader[28] = (unsigned char)(ppm >> 24);

    bmpinfoheader[29] = (unsigned char)(ppm);
    bmpinfoheader[30] = (unsigned char)(ppm >> 8);
    bmpinfoheader[31] = (unsigned char)(ppm >> 16);
    bmpinfoheader[32] = (unsigned char)(ppm >> 24);

    image = fopen(filename, "wb");

    fwrite(bmpfileheader, 1, 14, image);
    fwrite(bmpinfoheader, 1, 40, image);
*/

    // write out pixel data, one last important this to know is the ordering is backwards
    // we have to go BGR as opposed to RGB
    for (int i = 0; i < image_size; i++)
    {
        RGBType BGR = data[i];

        double red = (BGR.r);
        double green = (BGR.g);
        double blue = (BGR.b);

        // if you don't follow BGR image will be flipped!
        unsigned char color[3] = 
        {
            (int)floor(blue), (int)floor(green), (int)floor(red)
        };

        fwrite(color, 1, sizeof(color), image);
    }

    fclose(image);
}

int main()
{
    int width = 400;
    int height = 400;
    int dpi = 96;

    RGBType *pixels = new RGBType[width * height];

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int a = y * width + x;

            if ((x > 50 && x < 350) && (y > 50 && y < 350))
            {
                pixels[a].r = 255;
                pixels[a].g = 255;
                pixels[a].b = 5;
            }
            else
            {
                pixels[a].r = 55;
                pixels[a].g = 55;
                pixels[a].b = 55;
            }
        }
    }

    savebmp("black_border.bmp", width, height, dpi, pixels);
    return 0;
}