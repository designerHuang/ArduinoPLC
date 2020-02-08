#define X_DIR_PIN          55
#define X_STEP_PIN         54
#define X_ENABLE_PIN       38

#define Y_DIR_PIN          61
#define Y_STEP_PIN         60
#define Y_ENABLE_PIN       56

#define Z_DIR_PIN          48
#define Z_STEP_PIN         46
#define Z_ENABLE_PIN       62

#define X_STEP_HIGH             PORTF |=  0b00000001;
#define X_STEP_LOW              PORTF &= ~0b00000001;

#define Y_STEP_HIGH             PORTF |=  0b01000000;
#define Y_STEP_LOW              PORTF &= ~0b01000000;

#define Z_STEP_HIGH             PORTL |=  0b00001000;
#define Z_STEP_LOW              PORTL &= ~0b00001000;

#define TIMER1_INTERRUPTS_ON    TIMSK1 |=  (1 << OCIE1A);
#define TIMER1_INTERRUPTS_OFF   TIMSK1 &= ~(1 << OCIE1A);

unsigned int c0;

#define buzPin 24
#define ledPin 13

#define IN01 A3
#define IN02 A4
#define IN03 A5
#define IN04 A9
#define IN05 A10
#define IN06 A11

#define OUT01 49
#define OUT02 47
#define OUT03 45
#define OUT04 44
#define OUT05 43
#define OUT06 42
#define OUT07 41
#define OUT08 40
#define OUT09 37
#define OUT10 36

#define B01 35
#define B02 34
#define B03 33
#define B04 32
#define B05 31
#define B06 30
#define B07 23
#define B08 22
#define B09 A15
#define B10 A14
#define B11 A13
#define B12 A12

#define O01 5
#define O02 2
#define O03 3

#define O05 6
#define O06 7
#define O07 8
#define O08 10
#define O09 11
#define O10 12
#define O11 25
#define O12 26
#define O13 27
#define O14 28
#define O15 29
#define O16 39
