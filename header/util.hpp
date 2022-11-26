#pragma once
#include <iostream>

#define readonly(type, identifier) private: type _ ## identifier;\
  public: const type &identifier = _ ## identifier;

#define _DEBUG 1

#if _DEBUG == 1
  #define log(text) std::cout << __FILE__ << " [" << __LINE__ << "]: " << text << std::endl
#else
  #define log(text)
#endif