#include <iostream>
#include "Navoh.h"

int main(int argc, char const *argv[]) {
  Navoh navoh;
  // try {
  //   navoh.loadImageFromFile(argv[1]);
  // }
  // catch (openImageException& e) {
  //   std::cout << "openImageException caught: " << e.what() << std::endl;
  // }
  // navoh.displayImage();
  try {
    navoh.loadImageFromCam(0);
  }
  catch (captureCameraException& e) {
    std::cout << "captureCameraException caught: " << e.what() << std::endl;
  }
  navoh.displayImage();
  return 0;
}
