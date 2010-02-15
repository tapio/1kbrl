1kbrl
=====

This is a little roguelike game which source code
is less than 1024 bytes in size.

Features
--------
* Colored output
* Random dungeons
* Field of view
* Torch affects vision
* Death

Instructions
------------
* Use WASD to move.
* You cannot move through walls: #
* Collect coins: o
* Descent to new levels: <
* Keep your torch alive: f

File Contents
-------------
    bin/				binaries for win32 / linux from both source versions
    1kbrl.cc			C++ source
    1kbrl.bas			FreeBASIC source
    1kbrl-verbose.cc	more readable, but >1kB version
    getch.cc			cross-platform getch() for C++ version
  						(not counted towards 1kB, because it is not needed on Windows)
    make-all.sh			compilation script for linux
    README.markdown		this file

Version Differences
-------------------
* C++ version requires ANSI capable terminal
* FB/C++ version colors are not identical
* At least linux versions need to be launched from terminal

License
-------

             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                     Version 2, December 2004

    Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

    Everyone is permitted to copy and distribute verbatim or modified
    copies of this license document, and changing it is allowed as long
    as the name is changed.

             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

    0. You just DO WHAT THE FUCK YOU WANT TO.


