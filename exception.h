#ifndef _EXCEPTION_h
#define _EXCEPTION_h

#include <exception>

struct openImageException: public std::exception {
  const char* what() const throw() {
    return "Could not open or find the image";
  }
};

#endif
