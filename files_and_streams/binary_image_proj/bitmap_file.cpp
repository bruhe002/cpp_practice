#include <fstream>
#include "bitmap_file.h"

using namespace std;

// Save image data to file
bool Bitmap::write() {
    bitmap_file_header file_header;
    bitmap_info_header info_header;

    // Calculate the size of the bitmap
    file_header.file_size = sizeof(bitmap_file_header) 
        + sizeof(bitmap_info_header) 
        + width * height * sizeof(pixel);
    file_header.data_offset = sizeof(bitmap_file_header) + sizeof(bitmap_info_header);

    // Set the image's width and height
    info_header.width = width;
    info_header.height = height;

    // Open the file where we will write the bitmap

}