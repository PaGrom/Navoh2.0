#include "Navoh.h"

Navoh::Navoh() {

}

Navoh::~Navoh() {

}

void Navoh::load(std::string imageName) {
  image = cvLoadImage(imageName.c_str(), 1);
  if (!image)
    throw openImageException();
}