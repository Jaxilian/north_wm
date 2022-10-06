#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>

Display* dpy;
Window window;
int main(int argc, char *argv[]){
    XWindowAttributes winattrb;
    dpy = XOpenDisplay(NULL);
    XGetWindowAttributes(dpy, window, &winattrb);



    return 0;
    
}