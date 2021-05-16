int FPS = 10;
//https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM
void setup() {
  pinMode(9, OUTPUT);                               // Set digital pin 9 (D9) to an output
  TCCR1A = _BV(COM1A1) | _BV(WGM11);                // Enable the PWM output OC1A on digital pins 9
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS12);     // Set fast PWM and prescaler of 256 on timer 1
  ICR1 = 12499;                                     // Set the PWM frequency to 5Hz: 16MHz/(256 * 5Hz) - 1 = 12499
  OCR1A = 1249;                                     // Set the duty-cycle to 10%: 62499 / 10 = 1249
  
  Serial.begin(9600);                               //listen to serial port
}


void loop() {
if(Serial.available() > 0)  {
    int incomingData= Serial.read(); 
    Serial.print(incomingData);
    int frequency = incomingData;
    int FPS =  16000000/(256*frequency)-1; // calculate new FPS
    ICR1 = FPS;
    OCR1A = FPS/10;

}

}
