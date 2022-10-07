#include "wm.h"
#include <string.h>
Display* display;



int main(int argc, char** argv){
    wm_alloc();
    
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-d")){
            wm_set_debug(true);
        }
    }
    wm_listen();
    wm_free();
}