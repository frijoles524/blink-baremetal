// define data types that are not defined
using byte = unsigned char;
using uint32_t = unsigned int;
using uint16_t = unsigned short;

// define pinmode and pin state registers so we can interact with I/O
#define PORTB *((volatile byte*) 0x25)
#define DDRB *((volatile byte*) 0x24)

// custom delay function because it's not defined by c
void delay_ms(volatile uint32_t milliseconds) {
    for (volatile uint32_t i = 0; i < milliseconds; i++) {
        for (volatile uint16_t j = 0; j < (F_CPU / 16000); j++) {
            // Empty loop for delay
        }
    }
}

// "normal" setup and loop functions
void setup() {
  // set pin mode: pin 13 output
  DDRB = 32;
}

void loop() {
  // blink example
  PORTB = 32; //this sets the pin 13 bit to 1 to turn on the led
  delay_ms(1000);
  PORTB = 0;  //setting the register to 0 will reset all pins on the port
  delay_ms(1000);
}

// execution entry point, handle the setup and loop functions
int main() {
  setup();

  while(1) {
    loop();
  }

  // compiler wants the main function to return a status code
  return 0;
}
