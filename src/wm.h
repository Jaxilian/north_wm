#ifndef WM_H
#define WM_H
extern "C" {
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>
}
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <unordered_map>
#include <mutex>

struct wm_data_t{
    bool debug_mode = false;
    Display* display = nullptr;
    Window root;
    std::unordered_map<Window, Window> clients;
    std::mutex wm_detected_mutex;
    bool wm_detected = true;
};

void wm_set_debug(bool val);

void wm_alloc();
void wm_listen();
void wm_free();

#endif