#include "TimerOne.h"

#define OUTPIN 13
#define HZ 32

long t1 = (32 / 2 * 1000); // ms
long t2 = (32 / 2 * 1000); // ms
int v = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(OUTPIN, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(pulseOn);
}

void pulseOn() {
  digitalWrite(OUTPIN, HIGH);
  Timer1.setPeriod(t1);
  Timer1.attachInterrupt(pulseOff);
}

void pulseOff() {
  digitalWrite(OUTPIN, LOW);
  Timer1.setPeriod(t2);
  Timer1.attachInterrupt(pulseOn);
}

double vToHz(int v) {
  return v * (4 * 637) / (60 * 60);
}

void loop() {
  Serial.print(vToHz(30));
  delay(1000);
}
