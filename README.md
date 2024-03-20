# keyrisame - an AT / PS2 to PC-98 keyboard converter  

work in progress, mostly works. not responsible if you break stuff. use at your own risk.  
you will need an atmega328p based arduino. others are untested.

## Wiring

```
PC0 (A0) to AT clock
PC1 (A1) to AT data

PD1 (TX) to PC-98 RX

PD2 to joystick up
PD3 to joystick down
PD4 to joystick left
PD5 to joystick right
PD6 to joystick 1
PD7 to joystick 2

don't forget the grounds...
```
