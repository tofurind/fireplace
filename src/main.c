#include <Arduino.h>

const int pwmPin = 0; //pin 5 (PB0)
const int pwmPin2 = 1; //pin 6 (PB1)

// If you are unhappy with the performance, try tweaking these values:
const uint8_t minbrightness = 40; // relates to pwm 0..255
const uint8_t stepsize = 20; // relates to pwm 0..255
const int stepduration = 30; // ms


typedef struct {
    uint8_t min;
    uint8_t max;
    uint8_t maxstep;
    uint8_t val;
} RandomWalk;

void RandomWalk_init(RandomWalk *r, const uint8_t min, const uint8_t max, const uint8_t maxstep) {
    r->min = min;
    r->max = max;
    r->maxstep = maxstep;
    r->val = (max-min)/2;
}

void RandomWalk_run(RandomWalk *r) {
    int dist = (rand()%(2*r->maxstep +1)) - r->maxstep;
    if((int)(r->val) + dist > (int)r->max){
        r->val = r->max;
    }
    else if((int)(r->val) + dist < (int)r->min){
        r->val = r->min;
    }
    else{
        r->val += dist;
    }
}

RandomWalk r1,r2;

void setup() {
    pinMode(pwmPin, OUTPUT);
    pinMode(pwmPin2, OUTPUT);
    RandomWalk_init(&r1, minbrightness, 255UL, stepsize);
    RandomWalk_init(&r2, minbrightness, 255UL, stepsize);
}

void loop() {
    RandomWalk_run(&r1);
    RandomWalk_run(&r2);
    analogWrite(pwmPin, r1.val);
    analogWrite(pwmPin2, r2.val);
    delay(stepduration);
}
