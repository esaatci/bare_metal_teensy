
unsigned int set_val = 0x20000000;
unsigned int port_set_output =  0x400FF104;
unsigned int port_set_output = 0x400FF108;



ldr r1, [set_val]
ldr r3, [port_set_output]
mv r3, r1
str port_set_output, r3

asm volatile();












my_test: In function 'void toggle_led()':
my_test:24: warning: unused variable 'port_set_output' 
   unsigned int port_set_output =  0x400FF104;
                ^
my_test:25: warning: unused variable 'port_clear_output' 
   unsigned int port_clear_output =  0x400FF108;
                ^
/var/folders/ch/wnmk24g93ss29jnv9vxld0_40000gn/T//ccKvbwW5.s: Assembler messages:
/var/folders/ch/wnmk24g93ss29jnv9vxld0_40000gn/T//ccKvbwW5.s:75: Error: invalid offset, value too big (0xFFFFFFFFFFFFFFFC)
Error compiling for board Teensy LC.


This report would have more information with
"Show verbose output during compilation"
option enabled in File -> Preferences.

Arduino: 1.8.13 (Mac OS X), TD: 1.53, Board: "Teensy LC, Serial, 48 MHz, Smallest Code, US English"











my_test: In function 'void toggle_led()':
my_test:24: warning: unused variable 'port_set_output' 
   unsigned int port_set_output =  0x400FF104;
                ^
my_test:25: warning: unused variable 'port_clear_output' 
   unsigned int port_clear_output =  0x400FF108;
                ^
/var/folders/ch/wnmk24g93ss29jnv9vxld0_40000gn/T//ccKvbwW5.s: Assembler messages:
/var/folders/ch/wnmk24g93ss29jnv9vxld0_40000gn/T//ccKvbwW5.s:75: Error: invalid offset, value too big (0xFFFFFFFFFFFFFFFC)
Error compiling for board Teensy LC.


This report would have more information with
"Show verbose output during compilation"
option enabled in File -> Preferences.
