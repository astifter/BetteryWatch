#include "bettery_watch_window.h"
#include "watchface_base/watchface_base.h"
#include "watchface_base/logging_helper.h"
#include <pebble.h>

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  LOG_FUNC();
  update_time();
}
  
int main(void) {
  LOG_FUNC();

  watchface_base_init(update_time);
  show_bettery_watch_window();
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  app_event_loop();

  tick_timer_service_unsubscribe();
  hide_bettery_watch_window();
  watchface_base_deinit();
}
