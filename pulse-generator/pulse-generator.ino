#define AIN_PIN 0
#define PWMOUT_PIN 11

//int v_max = round(255 * 1.4 / 5.0);
//int v_min = round(255 * 0.7 / 5.0);

int ain = 0;
float volt = 0.0;
int volt_out = 0;

void setup() {
    
  pinMode(PWMOUT_PIN, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  ain = analogRead(AIN_PIN);
  volt = 0.7 + (0.7 * ain / 1023.0);
  volt_out = round(255 * volt / 5.0);

  analogWrite(PWMOUT_PIN, volt_out);

//  for ( int led_value = v_min; led_value <= v_max; led_value += 1 ) {
//    analogWrite( 11, led_value );
//    delay( 100 );
//  }
//  delay( 2000 );
//  
//  for ( int led_value = v_max; led_value >= v_min; led_value -= 1 ) {
//    analogWrite( 11, led_value );
//    delay( 100 );
//  }
//  delay( 2000 );

  Serial.print("volt=");
  Serial.println(volt);
//  Serial.println("");
  
  delay(500);
  
}
