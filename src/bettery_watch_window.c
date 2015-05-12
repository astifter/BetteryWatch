#include "bettery_watch_window.h"
#include "watchface_base/logging_helper.h"
#include "watchface_base/hw_handling.h"
#include <pebble.h>

static bool ui_updates_enabled = false;
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_background;
static GFont s_res_bitham_42_light;
static GFont s_res_roboto_condensed_21;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_timelayer;
static TextLayer *s_daylayer;
static TextLayer *s_datelayer;
static TextLayer *s_infolayer_1;
static TextLayer *s_infolayer_2;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorClear);
  
  s_res_image_background = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
  s_res_bitham_42_light = fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT);
  s_res_roboto_condensed_21 = fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21);
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_image_background);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_timelayer
  s_timelayer = text_layer_create(GRect(5, 13, 134, 50));
  text_layer_set_background_color(s_timelayer, GColorClear);
  text_layer_set_text_color(s_timelayer, GColorWhite);
  text_layer_set_text(s_timelayer, "00:00");
  text_layer_set_text_alignment(s_timelayer, GTextAlignmentCenter);
  text_layer_set_font(s_timelayer, s_res_bitham_42_light);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_timelayer);
  
  // s_daylayer
  s_daylayer = text_layer_create(GRect(5, 64, 134, 26));
  text_layer_set_background_color(s_daylayer, GColorClear);
  text_layer_set_text_color(s_daylayer, GColorWhite);
  text_layer_set_text(s_daylayer, "Mon");
  text_layer_set_text_alignment(s_daylayer, GTextAlignmentCenter);
  text_layer_set_font(s_daylayer, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_daylayer);
  layer_set_hidden(text_layer_get_layer(s_daylayer), true);
  
  // s_datelayer
  s_datelayer = text_layer_create(GRect(5, 64, 134, 26));
  text_layer_set_background_color(s_datelayer, GColorClear);
  text_layer_set_text_color(s_datelayer, GColorWhite);
  text_layer_set_text(s_datelayer, "2.5.2015");
  text_layer_set_text_alignment(s_datelayer, GTextAlignmentCenter);
  text_layer_set_font(s_datelayer, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_datelayer);
  
  // s_infolayer_1
  s_infolayer_1 = text_layer_create(GRect(5, 100, 134, 26));
  text_layer_set_background_color(s_infolayer_1, GColorClear);
  text_layer_set_text_color(s_infolayer_1, GColorWhite);
  text_layer_set_text(s_infolayer_1, "Text layer");
  text_layer_set_text_alignment(s_infolayer_1, GTextAlignmentCenter);
  text_layer_set_font(s_infolayer_1, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_infolayer_1);
  
  // s_infolayer_2
  s_infolayer_2 = text_layer_create(GRect(5, 125, 134, 26));
  text_layer_set_background_color(s_infolayer_2, GColorClear);
  text_layer_set_text_color(s_infolayer_2, GColorWhite);
  text_layer_set_text(s_infolayer_2, "Text layer");
  text_layer_set_text_alignment(s_infolayer_2, GTextAlignmentCenter);
  text_layer_set_font(s_infolayer_2, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_infolayer_2);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_timelayer);
  text_layer_destroy(s_daylayer);
  text_layer_destroy(s_datelayer);
  text_layer_destroy(s_infolayer_1);
  text_layer_destroy(s_infolayer_2);
  gbitmap_destroy(s_res_image_background);
}
// END AUTO-GENERATED UI CODE

void update_time(void) {
  LOG_FUNC();

  if (!ui_updates_enabled) {
      LOG(LOG_FACEUPDATE, "static void update_time(): not done, not enabled");
      return;
  }

  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  LOG(LOG_FACEUPDATE, "static void update_time(): display plain time");
  // Use a static (long lived) buffer for the numeric time.
  static char time[] = "00:00";
  // Write the current hours and minutes into the buffer, considerung the
  // 12/24h style.
  if(clock_is_24h_style() == true) {
    strftime(time, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    strftime(time, sizeof("00:00"), "%I:%M", tick_time);
  }
  // Display time in respective layer.
  text_layer_set_text(s_timelayer, time);

  int weekday = tick_time->tm_wday-1;
  if (weekday < 0) weekday += 7;
  LOG(LOG_FACEUPDATE, "static void update_time(): display date");
  LOG_EXT(LOG_FACEUPDATE, "static void update_time(): day: %d", weekday);
  LOG_EXT(LOG_FACEUPDATE, "static void update_time(): mday: %d", tick_time->tm_mday);
  LOG_EXT(LOG_FACEUPDATE, "static void update_time(): month: %d", tick_time->tm_mon);
  // Use a static (long lived) buffer for the numeric date.
  static char date[80];
  strftime(date, 80, "%a, %d. %b", tick_time);
  // Display date in respective layer.
  LOG(LOG_FACEUPDATE, "updating s_date_layer");
  text_layer_set_text(s_datelayer, date);

  // Fetch and print BlueTooth status information.
  LOG(LOG_FACEUPDATE, "updating s_info1_layer");
  text_layer_set_text(s_infolayer_1, bt_state_string);

  LOG(LOG_FACEUPDATE, "updating s_infolayer_2");
  text_layer_set_text(s_infolayer_2, battery_state_string());
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_bettery_watch_window(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);

  ui_updates_enabled = true;
  update_time();
}

void hide_bettery_watch_window(void) {
  window_stack_remove(s_window, true);
}
