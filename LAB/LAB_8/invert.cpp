/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 8
DATE: 2/28/2024

Task A: write a program that inverts all colors. So white shades become black, and black become white
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>



//!FOR THIS LAB WE WILL NOT MODIFY THE FOLLOWING FUNCTIONS(readImage and writeImage) as they are working properly
//!Your goal is to change the main function, and possibly define your own new functions to implement the tasks.


const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	
	//variables to read header (click on image file in vscode and you will see it)
	char c;
	int x; //this one doesnt even do nun. ima just leave it as is

	//open image file
	std::ifstream instr;
	instr.open("inImage.pgm");

	//read the header P2
	//read character data from image file
	instr >> c;
	//?If condition inside assert() function becomes false then program will terminate and produce error message
	//if c is not equal 'p' then terminate program and produce error
	assert(c == 'P'); 
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	//skip white lines before checking if the next character is '#'(# is the delimiter)
	//if the next character is # then we ignore/skip 4096 characters(big number is just used to assume that line on input file will not exceed that length) or ignore until we get to a new line('\n)
	while ((instr>>std::ws).peek() == '#') { //std::ws = used to skip whitespace characters when reading from an input stream
		instr.ignore(4096, '\n'); 
	}

	//read the dimension data into variables height and width
	instr >> width;
	instr >> height;

	//if width > MAX_W or height > MAX_H then  terminate program and produce error bc condition in assert() function will be false
	assert(width <= MAX_W);
	assert(height <= MAX_H);

	//reading each pixel value (grayscale color value 0-255)
	int max;
	instr >> max;
	//if max not 255 then terminate
	assert(max == 255);

	//inserting the pixel value into positions(indexs row and col) in the image array
	//ex: pixel value = 215 -> inserting that value into array at position [3][7]. so row 3 column 7 in the array. (2D array think of it as auditorium map)
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	
	//close the file
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	//open file for writing
	std::ofstream ostr;
	ostr.open("outImage.pgm");

	//print error message if fails to open for writing
	if (ostr.fail()) {
		std::cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << std::endl;
	
	// print width and height. the ' ' just a space to separate the values
	ostr << width << ' ';
	ostr << height << std::endl;
	ostr << 255 << std::endl;

	//loop through each row and column of the image
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			//pretty much checks if the pixel at the position [row][col] in the array is < 256. if its not then it stops the program
			assert(image[row][col] < 256);

			//checks if pixel at position [row][col] in array us >= 0. if its not then it stops the program
			assert(image[row][col] >= 0);
			
			//if the two asserts pass then it prints out the pixel value on that [row][col] position with a space after for separation between numbers
			ostr << image[row][col] << ' ';

			//move to next line after every pixel
			ostr << std::endl;
		}
	}
	ostr.close();
	return;
}



int main() {

	//declare the 2-Dimensional array
	int img[MAX_H][MAX_W];

	//vraiables to sore height and width
	int h, w;

	
    //call function

    //which reads the input image data from inImage.pgm and stores it in the img array. 
    //It also sets the h and w variables to the height and width of the image.
	readImage(img, h, w); 

	// Now we can manipulate the image the way we like

	//loop through 2D array(row and columns)
	for(int row = 0; row < h; row++){
		for(int col = 0; col < w; col++){
			//change for inverted colors
			//if 255(white pixel) - current pixel = new pixel value. if new value is 1-244 254 its gray. if 255 then its white. if 0 its black
			img[row][col] = 255 - img[row][col];
		}
	}

	

	//save this new image to file "outImage.pgm"
	writeImage(img, h, w);

	return 0;
}
