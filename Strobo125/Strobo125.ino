/* Stroboscope 125Hz/250Hz for adjusting teletype baudrate
 * by Jochen Krapf - GPL3
 * 
 * Frequency = 16MHz(oscillator) / 256(prescaler) / 250(OCR) / 2(phase) = 125Hz
 * Frequency = 16MHz(oscillator) / 256(prescaler) / 125(OCR) / 2(phase) = 250Hz
 * 
 * https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM
 */

int frq = 250;

void setup() {
  // PWM timer 2
  pinMode(3, OUTPUT);
  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM20);   // PWM phase corrected
  TCCR2B = _BV(WGM22) | _BV(CS22) | _BV(CS21);  // set prescaler to 256
  OCR2A = 31250 / frq;
  OCR2B = OCR2A / 10;   // 10% duty cycle

  //// PWM timer 0
  // pinMode(5, OUTPUT);
  // TCCR0A = _BV(COM0A0) | _BV(COM0B1) | _BV(WGM00);   // PWM phase corrected
  // TCCR0B = _BV(WGM02) | _BV(CS02);  // set prescaler to 256
  // OCR0A = 31250 / frq;
  // OCR0B = OCR0A / 10;   // 10% duty cycle

  // LED status
  // pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // digitalWrite(LED_BUILTIN, ! digitalRead(LED_BUILTIN));
  // delay(500);
}
