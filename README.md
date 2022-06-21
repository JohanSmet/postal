# Postal

Source code of Postal by Running With Scissors, imported from their GPL [release](https://runningwithscissors.com/the-original-postal-has-been-made-open-source/) on bitbucket a few years ago.

## Overview of changes
- small series of changes to silence compiler warnings (not all, but most -Wall warnings on GCC/Clang)
- ported to 64-bit; builds and runs on modern Linux, Windows and (Intel) MacOS systems.

## Status of the ports

### PC 64-bit
- should work fine on Linux, Windows and (Intel) MacOS X
- needs more testing
- no multiplayer

### Xbox - nxdk (branch wip/xbox)
- no sound with latest nxdk. With older nxdk: sound works on Xemu but SDL_init() hangs on real hardware.
- no saved games
- no multiplayer
- even less tested than 64-bit PC port
- menu needs to be cleaned to remove invalid options on console (keyboard mapping, ...)
- add build instructions (+ improve packaging workflow)

## Future plans
- ports to other systems (Xbox, M1 macs)
- actually properly testing the game.
