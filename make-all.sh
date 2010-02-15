#!/bin/sh
# Script name: make-all
# Description: Builds everything in linux
# Version:     1

echo "C++ linux x86"
g++ 1kbrl.cc -o bin/1kbrl-gcc.x86

echo "C++ MinGW cross-compilation for win32"
i586-mingw32msvc-g++ 1kbrl.cc -o bin/1kbrl-mingw-win32.exe

echo "FreeBASIC linux x86"
fbc 1kbrl.bas -x bin/1kbrl-fb.x86

echo "FreeBASIC Wine cross-compilation for win32"
wine "C:\Program Files\FreeBASIC\fbc.exe" 1kbrl.bas -x bin/1kbrl-fb-win32.exe

echo "Done."

