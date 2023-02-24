#include <iostream>
#include "CImg.h"

using namespace cimg_library;

int main() {
  // Load PNG image
  CImg<unsigned char> image("input.png");

  // Save JPEG image
  image.save_jpeg("output.jpg");

  return 0;
}
