/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 8
DATE: 4/12/2024

Task G
*/
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;
// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
    char c;
    int x;
    ifstream instr;
    instr.open("inImage.pgm");

    // read the header P2
    instr >> c;
    assert(c == 'P');
    instr >> c;
    assert(c == '2');

    // skip the comments (if any)
    while ((instr>>ws).peek() == '#') {
        instr.ignore(4096, '\n');
    }

    instr >> width;
    instr >> height;

    assert(width <= MAX_W);
    assert(height <= MAX_H);
    int max;
    instr >> max;
    assert(max == 255);

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            instr >> image[row][col];
    instr.close();
    return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
    ofstream ostr;
    ostr.open("outImage.pgm");
    if (ostr.fail()) {
        cout << "Unable to write file\n";
        exit(1);
    };

    // print the header
    ostr << "P2" << endl;
    // width, height
    ostr << width << ' ';
    ostr << height << endl;
    ostr << 255 << endl;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            assert(image[row][col] < 256);
            assert(image[row][col] >= 0);
            ostr << image[row][col] << ' ';
        }
        ostr << endl;
    }
    ostr.close();
    return;
}

// Horizontal edge detection kernel
int horizontalEdgeDetection(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    return (g + 2 * h + i) - (a + 2 * b + c);
}

// Kernel method image filtering
void applyFilter(int inputImage[MAX_H][MAX_W], int outputImage[MAX_H][MAX_W], int height, int width, int (*kernelFunction)(int, int, int, int, int, int, int, int, int)) {
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            // Compute the 3x3 window centered on the current pixel
            int a = col > 0 && row > 0 ? inputImage[row - 1][col - 1] : 0;
            int b = row > 0 ? inputImage[row - 1][col] : 0;
            int c = col < width - 1 && row > 0 ? inputImage[row - 1][col + 1] : 0;
            int d = col > 0 ? inputImage[row][col - 1] : 0;
            int e = inputImage[row][col];
            int f = col < width - 1 ? inputImage[row][col + 1] : 0;
            int g = col > 0 && row < height - 1 ? inputImage[row + 1][col - 1] : 0;
            int h = row < height - 1 ? inputImage[row + 1][col] : 0;
            int i = col < width - 1 && row < height - 1 ? inputImage[row + 1][col + 1] : 0;

            // Apply the kernel function to the window
            int newValue = kernelFunction(a, b, c, d, e, f, g, h, i);

            // Clamp the new value to the range [0, 255]
            if(newValue < 0) {
                newValue = 0;
            }
            else if(newValue > 255) {
                newValue = 255;
            }

            // Assign the new value to the output image
            outputImage[row][col] = newValue;
        }
    }
}

int main() {

    int img[MAX_H][MAX_W];
    int out[MAX_H][MAX_W];
    int h, w;

    readImage(img, h, w);

    // Apply the horizontal edge detection kernel to the image
    applyFilter(img, out, h, w, horizontalEdgeDetection);

    // Write the resulting image to file
    writeImage(out, h, w);

    return 0;
}