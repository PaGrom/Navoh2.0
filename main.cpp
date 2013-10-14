#include <iostream>
#include "Navoh.h"

int main(int argc, char const *argv[]) {
  Navoh navoh;
  try {
    navoh.load(argv[1]);
  }
  catch (openImageException& e) {
    std::cout << "openImageException caught: " << e.what() << std::endl;
  }
  return 0;
}