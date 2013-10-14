#include "Navoh.h"

Navoh::Navoh() {

}

Navoh::~Navoh() {

}

void Navoh::load(std::string imageName) {
  // char* filename = "argv[1]";
  image = cvLoadImage(imageName.c_str(), 1);
  if (!image) {
    std::cerr <<  "Could not open or find the image" << std::endl ;
    exit(1);
  }
}