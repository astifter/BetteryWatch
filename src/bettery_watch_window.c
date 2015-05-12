#include "bettery_watch_window.h"
#include <pebble.h>

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
static TextLayer *s_textlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorClear);
  window_set_fullscreen(s_window, true);
  
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
  text_layer_set_font(s_daylayer, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_daylayer);
  
  // s_datelayer
  s_datelayer = text_layer_create(GRect(5, 64, 134, 26));
  text_layer_set_background_color(s_datelayer, GColorClear);
  text_layer_set_text_color(s_datelayer, GColorWhite);
  text_layer_set_text(s_datelayer, "2.5.2015");
  text_layer_set_text_alignment(s_datelayer, GTextAlignmentRight);
  text_layer_set_font(s_datelayer, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_datelayer);
  
  // s_infolayer_1
  s_infolayer_1 = text_layer_create(GRect(5, 100, 134, 26));
  text_layer_set_background_color(s_infolayer_1, GColorClear);
  text_layer_set_text_color(s_infolayer_1, GColorWhite);
  text_layer_set_text(s_infolayer_1, "Text layer");
  text_layer_set_font(s_infolayer_1, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_infolayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(5, 125, 134, 26));
  text_layer_set_background_color(s_textlayer_1, GColorClear);
  text_layer_set_text_color(s_textlayer_1, GColorWhite);
  text_layer_set_text(s_textlayer_1, "Text layer");
  text_layer_set_font(s_textlayer_1, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_timelayer);
  text_layer_destroy(s_daylayer);
  text_layer_destroy(s_datelayer);
  text_layer_destroy(s_infolayer_1);
  text_layer_destroy(s_textlayer_1);
  gbitmap_destroy(s_res_image_background);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_bettery_watch_window(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_bettery_watch_window(void) {
  window_stack_remove(s_window, true);
}
