#include <stdint.h>

static const int x = 11;
static int a = 5;
int sum;


// Enables port C
void enable_port_c(void) 
{

  uint32_t addr_val;
  uint32_t *SIM_SCGC5 = (uint32_t *)0x40048038;
  // bit 11 controls port c
  uint32_t port_c = !!(*SIM_SCGC5 & (1 << 11)); 
  
  if(!port_c) {
      addr_val = *SIM_SCGC5;
      addr_val = addr_val | (1 << 11);
      *SIM_SCGC5 = addr_val;
  }
  
  *SIM_SCGC5 = 0x3F82;
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
  *gpioc_pdor = 0x20; /* Make pin C5 logic high */

}

int main(void) {

  enable_port_c();
  enable_pin(); 
  set_output();
  while(1);

}
