#include <pebble.h>

#include "bettery_watch_window.h"
  
int main(void) {
  show_bettery_watch_window();
  app_event_loop();
  hide_bettery_watch_window();
}