#include <mbed.h>
#include <mbed_events.h>

#if SAM
#define MAL_LED PA17
#else
#define MAL_LED LED1
#endif

static void blinky(void) {
    static DigitalOut led(MAL_LED);
    led = !led;
    printf("LED = %d \r\n",led.read());
}

int main()
{
  EventQueue queue;

  queue.call_in(2000, printf, "called in 2 seconds!");
  queue.call_every(1000, blinky);

  queue.dispatch();
}