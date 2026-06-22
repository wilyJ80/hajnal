#define CHARGE_PIN 25
#define ANALOG_PIN 32
#define RESISTOR_VALUE 1000.0

void setup() {
  Serial.begin(9600);
  pinMode(CHARGE_PIN, OUTPUT);
}

void loop() {
  digitalWrite(CHARGE_PIN, LOW);
  pinMode(CHARGE_PIN, OUTPUT);
  delay(1000);

  digitalWrite(CHARGE_PIN, HIGH);
  unsigned long startTime = micros();

  while(analogRead(ANALOG_PIN) < 2600) {
  }

  unsigned long elapsedTime = micros() - startTime;

  float timeSeconds = elapsedTime / 1e6;
  float capacitanceFarads = timeSeconds / RESISTOR_VALUE;
  float capacitanceMicroFarads = capacitanceFarads * 1e6;

  Serial.print("Capacitance: ");
  Serial.print(capacitanceMicroFarads);
  Serial.println(" uF");

  delay(2000);
}
