@echo off
cd ..
cd build
mingw32-make -f Makefile
cd bin
raylib-project
pause
