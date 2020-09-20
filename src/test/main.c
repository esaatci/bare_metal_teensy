
static const int x = 11;
static int a = 5;
int sum;

void turn_on(void) {
  volatile unsigned int *address = (volatile unsigned int *)0x400ff084;
  unsigned int write_val = 0x00000020;
  *address = write_val;
}

void set_direction(void) {
    volatile unsigned int *address = (volatile unsigned int *)0x400FF080;
    unsigned int write_val = 0x00000020;
    *address = write_val;
}

void main() {

    sum = x + a;
    set_direction();
    turn_on();


}
