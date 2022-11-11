#include "Image.h"

#include <iostream>

int main() {
  Image alma;

  std::cout << "Using Image::lighten to create `lighten.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.lighten(0.2);
  alma.writeToFile("../lighten.png");

  std::cout << "Using Image::saturate to create `saturate.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.saturate(0.2);
  alma.writeToFile("../saturate.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  std::cout << "Image Width: " + std::to_string(alma.width()) << std::endl;
  std::cout << "Image Height: " + std::to_string(alma.height()) << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(1000, 800);
  std::cout << "Image Width after scale: " + std::to_string(alma.width()) << std::endl;
  std::cout << "Image Height after scale: " + std::to_string(alma.height()) << std::endl;
  alma.writeToFile("../scale2x.png");

  return 0;
}
