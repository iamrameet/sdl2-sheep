#pragma once
#include <unordered_map>
#include "SDL2/SDL.h"


typedef struct Timeout{
  void (* handler)();
  unsigned int timeout;
  unsigned int time;
  bool isInterval = false;
  Timeout(void (* handler)(), unsigned int timeout, bool isInterval = false){
    this->handler = handler;
    this->timeout = timeout;
    this->time = timeout + SDL_GetTicks();
    this->isInterval = isInterval;
  }
} Timeout;

class Timer{
public:
  static unsigned int keyCounter;
  static std::unordered_map<unsigned int, Timeout> timeouts;
  static unsigned int setTimeout(void (* handler)(), unsigned int timeout){
    timeouts.insert({keyCounter, Timeout(handler, timeout)});
    return keyCounter++;
  }
  static unsigned int setInterval(void (* handler)(), unsigned int interval){
    timeouts.insert({keyCounter, Timeout(handler, interval, true)});
    return keyCounter++;
  }
  static void clearTimeout(unsigned int key){
    timeouts.erase(key);
  }

  static void call(){
    unsigned int ticks = SDL_GetTicks();
    for(auto current_timeout = timeouts.begin(); current_timeout != timeouts.end(); current_timeout++){
      if(current_timeout->second.time <= ticks){ // 5500 <= 5500
        current_timeout->second.handler();
        if(current_timeout->second.isInterval)
          current_timeout->second.time = ticks + current_timeout->second.timeout; // 3500 + 2000 = 5500
        else
          timeouts.erase(current_timeout);
      }
    }
  }

};

unsigned int Timer::keyCounter = 0;
std::unordered_map<unsigned int, Timeout> Timer::timeouts;