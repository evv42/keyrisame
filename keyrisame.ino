#define DEBUG 0

#include "scancodes.h"

void setup() {
  Serial.begin(19200, SERIAL_8O1); //PC-98 keyboard RX
  pinMode(A0,INPUT_PULLUP);        //AT,PS/2 clock
  pinMode(A1,INPUT_PULLUP);        //AT,PS/2 data
}

uint16_t ps2_buf = 0;
uint8_t ps2_count = 0;
uint8_t ps2_scancode = 0;
uint8_t ps2_release = 0;
uint8_t ps2_special = 0;

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
}
