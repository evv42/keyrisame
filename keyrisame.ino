#define DEBUG 0

#include "scancodes.h"

void setup() {
  Serial.begin(19200, SERIAL_8O1); //PC-98 keyboard RX
  pinMode(A0,INPUT_PULLUP);        //AT,PS/2 clock
  pinMode(A1,INPUT_PULLUP);        //AT,PS/2 data
  DDRD=0xFF;                       //D2-D7 are joystick up,down,left,right,1 and 2 in order
  PORTD=0xFF;
}

uint16_t ps2_buf = 0;
uint8_t ps2_count = 0;
uint8_t ps2_scancode = 0;
uint8_t ps2_release = 0;
uint8_t ps2_special = 0;

uint8_t joy_before = 0xFC;
uint8_t joy_now = 0xFC;

void pc98_key_make(uint8_t code){
  if(ps2_special)code = pgm_read_byte_near(pc98_scancode_spe + code);
  else code = pgm_read_byte_near(pc98_scancode + code);
  Serial.write(code);
}

void pc98_key_break(uint8_t code){
  if(ps2_special)code = pgm_read_byte_near(pc98_scancode_spe + code);
  else code = pgm_read_byte_near(pc98_scancode + code);
  Serial.write(code | 0x80);
}

void loop() {
  if(!(PINC & 1)){
    //Serial.println(PINC >> 1);
    ps2_buf |= ((PINC >> 1) << 11);
    ps2_buf >>= 1;
    ps2_count++;
    while(!(PINC & 1));
  }
  if(ps2_count == 11){
    ps2_count = 0;
    ps2_scancode = (ps2_buf >> 1) & 0xFF;
    if(ps2_scancode == 0xF0)ps2_release = 1;
    else if(ps2_scancode == 0xE0)ps2_special = 1;
    else if(ps2_release){
      if(DEBUG){
        Serial.print("RELEASE:");
        if(ps2_special)Serial.print("SPE:");
        Serial.println(ps2_scancode, HEX);
      }else pc98_key_break(ps2_scancode);
      ps2_special = 0;
      ps2_release = 0;
    }else{
      if(DEBUG){
        if(ps2_special)Serial.print("SPE:");
        Serial.println(ps2_scancode, HEX);
      }else pc98_key_make(ps2_scancode);
      ps2_special = 0;
    }
    ps2_buf = 0;  
  }
  
  joy_now = PIND & 0xFC;
  
  if(joy_now != joy_before){
    delay(1);//debounce
    joy_now = PIND & 0xFC;
    if(joy_now != joy_before){
      uint8_t to_press = joy_before & (~joy_now);  
      uint8_t to_release = joy_now & (~joy_before);
      if(to_press){
        //Serial.print("p");
        //Serial.println(to_press,BIN);
        if(to_press & 0b00000100)Serial.write(0x3A);//up
        if(to_press & 0b00001000)Serial.write(0x3D);//down
        if(to_press & 0b00010000)Serial.write(0x3B);//left
        if(to_press & 0b00100000)Serial.write(0x3C);//right
        if(to_press & 0b01000000)Serial.write(0x2A);//1
        if(to_press & 0b10000000)Serial.write(0x29);//2
      }
      if(to_release){
        //Serial.print("r");
        //Serial.println(to_release,BIN);
        if(to_release & 0b00000100)Serial.write(0x3A | 0x80);//up
        if(to_release & 0b00001000)Serial.write(0x3D | 0x80);//down
        if(to_release & 0b00010000)Serial.write(0x3B | 0x80);//left
        if(to_release & 0b00100000)Serial.write(0x3C | 0x80);//right
        if(to_release & 0b01000000)Serial.write(0x2A | 0x80);//1
        if(to_release & 0b10000000)Serial.write(0x29 | 0x80);//2
      }
      joy_before = joy_now;
    }
  }
}
