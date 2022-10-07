#include "wm.h"
#include <string>

static std::unique_ptr<wm_data_t> data;
const std::string& display_str = std::string();

void wm_set_debug(bool val){
    data.get()->debug_mode = val;
}

void log(const char* msg){
    printf("%s\n",msg);
}

void err(const char* msg){
    printf("%s\n",msg);
    exit(1);
}

int on_wm_detected(Display* display, XErrorEvent* e){
    err("wm already exists!");
    return 0;
}

void wm_alloc(){
    printf("Allocating...\n");
    data = std::make_unique<wm_data_t>();

    const char* display_c_str = display_str.empty() ? nullptr : display_str.c_str();
    Display* display = XOpenDisplay(display_c_str);
    if (display == nullptr) {
        log(XDisplayName(display_c_str));
        err("Failed to open X display %s\n");
        return;
    }

    data.get()->display = display;

    data.get()->root = DefaultRootWindow(display);

    std::lock_guard<std::mutex> lock(data.get()->wm_detected_mutex);

    data.get()->wm_detected = false;
    XSetErrorHandler(on_wm_detected);
    XSelectInput(
        data.get()->display,
        data.get()->root,
        SubstructureRedirectMask | SubstructureNotifyMask);
    XSync(data.get()->display, false);


}

void wm_listen(){
    if(!data.get()->display){
        err("Display was nullptr in [wm_listen()]");
        exit(1);
    }

    for (;;) {

        XEvent e;
        XNextEvent(data.get()->display, &e);


        switch (e.type) {
        case CreateNotify:
            log("create notify");
            break;
        case DestroyNotify:
            log("destroy notify");
            break;
        case ReparentNotify:
            log("reparent notify");
            break;
        case MapNotify:
            log("map notify");
            break;
        case UnmapNotify:
             log("unmap notify");
            break;
        case ConfigureNotify:
           log("map notify");
            break;
        case MapRequest:
             log("map notify");
            break;
        case ConfigureRequest:
            log("map notify");
            break;
        case ButtonPress:
              log("map notify");
            break;
        case ButtonRelease:
             log("map notify");
            break;
        case MotionNotify:
            // Skip any already pending motion events.
            while (XCheckTypedWindowEvent(data.get()->display, e.xmotion.window, MotionNotify, &e)) {}
            log("motion notify");
            break;
        case KeyPress:
             log("key pressed");
            break;
        case KeyRelease:
             log("key released");
            break;
        default:
        break;
        }
    }
}

void wm_free(){

}