/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
*/
#include <stdint.h>


// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
/*
int led = 13;

void turn_off(void) {
  volatile uint32_t  *address = (volatile uint32_t *)0x400ff088;
  uint32_t write_val = 0x00000020;
  *address = write_val;
}

void turn_on(void) {
  volatile uint32_t *address = (volatile uint32_t *)0x400ff084;
  uint32_t write_val = 0x00000020;
  *address = write_val;
}

void read_reg() {
 volatile uint32_t *address = (volatile uint32_t *)0x400ff080;
 Serial.print("this is the value ");
 Serial.println(*address, HEX);
}

void init_pin() {
  unsigned int *p = (unsigned int *)0x4004B014;
  unsigned int x = *p | (0x1 << 8);
  *p = x;
  x = *p & (1 << 8);
  Serial.print("the value for the pin is");
  Serial.println(x, HEX);
  
  
  unsigned int *address = (unsigned int *)0x40048038;
  unsigned int masked = !!(*address & (1 << 11));
  Serial.print("The port C is atm ");
  Serial.println(masked);
  
  
}
*/


// Enables port C
void enable_port_c(void) 
{

  uint32_t addr_val;
  uint32_t *sim_scgc5 = (uint32_t *)0x40048038;
  // bit 11 controls port c
  uint32_t port_c = !!(*sim_scgc5 & (1 << 11)); 
  
  if(!port_c) {
      addr_val = *sim_scgc5;
      addr_val = addr_val | (1 << 11);
      *sim_scgc5 = addr_val;
  }

  *sim_scgc5 = 0x3F82;
}

// Led is in PTC5
// sets the pin to be GPIO
void enable_pin(void) 
{
  uint32_t addr_val, temp;  
  
  uint32_t *portc_pcr5 = (uint32_t *)0x4004B014;
  
  addr_val = *portc_pcr5;
  
  addr_val &= (0 << 10);
  addr_val &= (0 << 9);
  addr_val |= (1 << 8);
  
  *portc_pcr5 = addr_val;
}

// will set the pin to be output and turn on the pin
void set_output(void) 
{

  uint32_t *gpioc_pddr = (uint32_t *)0x400FF094;
  uint32_t *gpioc_pdor = (uint32_t *)0x400FF080;
  *gpioc_pddr |= (1 << 5);
  *gpioc_pdor &= (1 << 5);
  

}

void toggle_pin(void) 
{
  uint32_t *gpioc_ptor = (uint32_t *)0x400FF08C;
  *gpioc_ptor |= (1 << 5);

}

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  enable_port_c();
  enable_pin(); 
  set_output();
  //pinMode(13, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  //delay(1000);
  toggle_pin();
  delay(1000);
  
}
