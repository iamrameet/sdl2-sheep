#pragma once
#include <iostream>

#define readonly(type, identifier) private: type _ ## identifier;\
  public: const type &identifier = _ ## identifier;\
  private:

#define _DEBUG 1

#if _DEBUG == 1
  #define log(text) std::cout << text << std::endl
#else
  #define log(text)
#endif