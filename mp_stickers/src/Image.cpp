#include <Image.h>
#include "cs225/PNG.h"

// Lighten an Image by increasing the luminance of every pixel by 0.1.
// This function ensures that the luminance remains in the range [0, 1].
void Image::lighten() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).l + 0.1 >= 0 && getPixel(i, j).l + 0.1 <= 1) {
                getPixel(i, j).l += 0.1;
            } else {
                if (getPixel(i, j).l + 0.1 < 0) {
                    getPixel(i, j).l = 0;
                } else {
                    getPixel(i, j).l = 1;
                }
            }
        }
    }
}

void Image::lighten(double amount) {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).l + amount >= 0 && getPixel(i, j).l + amount <= 1) {
                getPixel(i, j).l += amount;
            } else {
                if (getPixel(i, j).l + amount < 0) {
                    getPixel(i, j).l = 0;
                } else {
                    getPixel(i, j).l = 1;
                }
            }
        }
    }
}

// Darken an Image by decreasing the luminance of every pixel by 0.1.
// This function ensures that the luminance remains in the range [0, 1].
void Image::darken() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).l - 0.1 >= 0 && getPixel(i, j).l - 0.1 <= 1) {
                getPixel(i, j).l -= 0.1;
            } else {
                if (getPixel(i, j).l - 0.1 < 0) {
                    getPixel(i, j).l = 0;
                } else {
                    getPixel(i, j).l = 1;
                }
            }
        }
    }
}

void Image::darken(double amount) {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).l - amount >= 0 && getPixel(i, j).l - amount <= 1) {
                getPixel(i, j).l -= amount;
            } else {
                if (getPixel(i, j).l - amount < 0) {
                    getPixel(i, j).l = 0;
                } else {
                    getPixel(i, j).l = 1;
                }
            }
        }
    }
}

// Saturates an Image by increasing the saturation of every pixel by 0.1.
// This function ensures that the saturation remains in the range [0, 1]
void Image::saturate() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s + 0.1 >= 0 && getPixel(i, j).s + 0.1 <= 1) {
                getPixel(i, j).s += 0.1;
            }
        }
    }
}

void Image::saturate(double amount) {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s + amount >= 0 && getPixel(i, j).s + amount <= 1) {
                getPixel(i, j).s += amount;
            }
        }
    }
}

// Desaturates an Image by decreasing the saturation of every pixel by 0.1.
// This function ensures that the saturation remains in the range [0, 1]
void Image::desaturate() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s - 0.1 >= 0 && getPixel(i, j).s - 0.1 <= 1) {
                getPixel(i, j).s -= 0.1;
            }
        }
    }
}

void Image::desaturate(double amount) {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).s - amount >= 0 && getPixel(i, j).s - amount <= 1) {
                getPixel(i, j).s -= amount;
            }
        }
    }
}

//Turns the image grayscale by setting saturation of all pixels to 0.
void Image::grayscale() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            getPixel(i, j).s = 0;
        }
    }
}

// Rotates the color wheel by degrees. Rotating in a positive direction 
// increases the degree of the hue. This function ensures that the hue 
// remains in the range [0, 360].
void Image::rotateColor(double degrees) {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            if (getPixel(i, j).h + degrees > 360 || getPixel(i, j).h + degrees < 0) {
                if (getPixel(i, j).h + degrees > 360) {
                    getPixel(i, j).h = getPixel(i, j).h + degrees - 360;
                } else {
                    getPixel(i, j).h = 360 + getPixel(i, j).h + degrees;
                }
            } else {
                getPixel(i, j).h += degrees;
            }
        }
    }
}

// Trasnform an Image to Illini colors.
// The hue of every pixel is set to the a hue value of either orange or blue, based on if 
// the pixel's hue value is closer to orange than blue.
// “Illini Orange” has a hue of 11
// “Illini Blue” has a hue of 216
void Image::illinify() {
    for (unsigned int i = 0; i < width(); i++) {
        for (unsigned int j = 0; j < height(); j++) {
            cs225::HSLAPixel pixel = getPixel(i, j);
            int current_hue = pixel.h;
            //blue and orange distance 1 determine distance without wrapping around the wheel
            // i.e counterclockwise
            int blue_distance1 = abs(current_hue - 216);
            int orange_distance1 = abs(current_hue - 11);
            //blue and orange distance 2 determine distance moving clockwise around the wheel
            int blue_distance2 = abs(360 - current_hue) + 216;
            int orange_distance2 = abs(360 - current_hue) + 11;
            //find which direction results in smallest distance
            if (blue_distance2 < blue_distance1) {
                blue_distance1 = blue_distance2;
            }
            if (orange_distance2 < orange_distance1) {
                orange_distance1 = orange_distance2;
            }
            if (blue_distance1 < orange_distance1) {
                getPixel(i, j).h = 216;
            } else {
                getPixel(i, j).h = 11;
            }
        }
    }
}

// Scale the Image by a given factor.
// For example:
// A factor of 1.0 does not change the image.
// A factor of 0.5 results in an image with half the width and half the height.
// A factor of 2 results in an image with twice the width and twice the height.
// This function both resizes the Image and scales the contents.

// HSLAPixel(double hue, double saturation, double luminance)
void Image::scale(double factor) {

    double old_width = width();
    double old_height = height();

    int newWidth = old_width * factor;
    int newHeight = old_height * factor;
    cs225::PNG copy_image = *this;
    resize(newWidth, newHeight);
    int row = 0;
    int col = 0;
    for (double i = 0; i < old_width; i = i + 1/factor) {
        col = 0;
        for (double j = 0; j < old_height; j = j + 1/factor) {
            int x = floor(i);
            int y = floor(j);
            if(row >= newWidth || col >= newHeight) {
                break;
            }
            getPixel(row, col) = copy_image.getPixel(x, y);
            col++;
        }
        row++;
    }
}

// Scales the image to fit within the size (w x h).
// This function preserves the aspect ratio of the image, so the 
// result will always be an image of width w or of height h (not necessarily both).
// For example, if the Image is currently (10, 20) and we want to scale to 
// (100, 100), then this should scale the Image to (50, 100). Note that scaling the 
// image to (100, 200) does not fit within the (100,100) dimensions given and is therefore incorrect.
// This function both resizes the Image and scales the contents.

void Image::scale(unsigned w, unsigned h) {
    double old_width = width();
    double old_height = height();
    
    double width_factor = w/old_width;
    double height_factor = h/old_height;

    if (old_height * width_factor > h) {
        scale(height_factor);
    } else {
        scale(width_factor);
    }
}