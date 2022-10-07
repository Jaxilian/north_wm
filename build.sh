premake5 gmake2

LIBS=-ldl make config=debug
LIBS=-ldl make config=release
(cd ./bin/Debug; ./north_wm)

